' ****************************************************************************************
' Library name: MSXML2
' Version: 6.0
' Documentation string: Microsoft XML, v6.0
' Path: D:\WINDOWS\system32\msxml6.dll
' Library GUID: {F5078F18-C551-11D3-89B9-0000F81FE221}
' ****************************************************************************************

' ****************************************************************************************
' To use interfaces derived from other interfaces when you only have a reference to the
' inherited interface, you must use XmlQueryInterface, e.g.:
' LOCAL IID_IXMLDOMText AS GUID
' pDOMNode = IXMLDOMNode_get_firstChild(pRootNode)
' IID_IXMLDOMText = $IID_IXMLDOMText
' pNodeText = XmlQueryInterface(pDOMNode, IID_IXMLDOMText)
' ****************************************************************************************

' ****************************************************************************************
' ProgIDs (Program identifiers)
' ****************************************************************************************

$PROGID_Msxml2DOMDocument = "Msxml2.DOMDocument"
$PROGID_Msxml2DOMDocument26 = "Msxml2.DOMDocument.2.6"
$PROGID_Msxml2DOMDocument30 = "Msxml2.DOMDocument.3.0"
$PROGID_Msxml2DOMDocument40 = "Msxml2.DOMDocument.4.0"
$PROGID_Msxml2DOMDocument60 = "Msxml2.DOMDocument.6.0"
$PROGID_Msxml2FreeThreadedDOMDocument = "Msxml2.FreeThreadedDOMDocument"
$PROGID_Msxml2FreeThreadedDOMDocument26 = "Msxml2.FreeThreadedDOMDocument.2.6"
$PROGID_Msxml2FreeThreadedDOMDocument30 = "Msxml2.FreeThreadedDOMDocument.3.0"
$PROGID_Msxml2FreeThreadedDOMDocument40 = "Msxml2.FreeThreadedDOMDocument.4.0"
$PROGID_Msxml2FreeThreadedDOMDocument60 = "Msxml2.FreeThreadedDOMDocument.6.0"
$PROGID_Msxml2MXHTMLWriter40 = "Msxml2.MXHTMLWriter.4.0"
$PROGID_Msxml2MXHTMLWriter60 = "Msxml2.MXHTMLWriter.6.0"
$PROGID_Msxml2MXNamespaceManager40 = "Msxml2.MXNamespaceManager.4.0"
$PROGID_Msxml2MXNamespaceManager60 = "Msxml2.MXNamespaceManager.6.0"
$PROGID_Msxml2MXXMLWriter = "Msxml2.MXXMLWriter"
$PROGID_Msxml2MXXMLWriter30 = "Msxml2.MXXMLWriter.3.0"
$PROGID_Msxml2MXXMLWriter40 = "Msxml2.MXXMLWriter.4.0"
$PROGID_Msxml2MXXMLWriter60 = "Msxml2.MXXMLWriter.6.0"
$PROGID_Msxml2SAXAttributes = "Msxml2.SAXAttributes"
$PROGID_Msxml2SAXAttributes30 = "Msxml2.SAXAttributes.3.0"
$PROGID_Msxml2SAXAttributes40 = "Msxml2.SAXAttributes.4.0"
$PROGID_Msxml2SAXAttributes60 = "Msxml2.SAXAttributes.6.0"
$PROGID_Msxml2SAXXMLReader = "Msxml2.SAXXMLReader"
$PROGID_Msxml2SAXXMLReader30 = "Msxml2.SAXXMLReader.3.0"
$PROGID_Msxml2SAXXMLReader40 = "Msxml2.SAXXMLReader.4.0"
$PROGID_Msxml2SAXXMLReader60 = "Msxml2.SAXXMLReader.6.0"
$PROGID_Msxml2ServerXMLHTTP = "Msxml2.ServerXMLHTTP"
$PROGID_Msxml2ServerXMLHTTP30 = "Msxml2.ServerXMLHTTP.3.0"
$PROGID_Msxml2ServerXMLHTTP40 = "Msxml2.ServerXMLHTTP.4.0"
$PROGID_Msxml2ServerXMLHTTP60 = "Msxml2.ServerXMLHTTP.6.0"
$PROGID_Msxml2XMLHTTP = "Msxml2.XMLHTTP"
$PROGID_Msxml2XMLHTTP26 = "Msxml2.XMLHTTP.2.6"
$PROGID_Msxml2XMLHTTP30 = "Msxml2.XMLHTTP.3.0"
$PROGID_Msxml2XMLHTTP40 = "Msxml2.XMLHTTP.4.0"
$PROGID_Msxml2XMLHTTP60 = "Msxml2.XMLHTTP.6.0"
$PROGID_Msxml2XMLSchemaCache = "Msxml2.XMLSchemaCache"
$PROGID_Msxml2XMLSchemaCache26 = "Msxml2.XMLSchemaCache.2.6"
$PROGID_Msxml2XMLSchemaCache30 = "Msxml2.XMLSchemaCache.3.0"
$PROGID_Msxml2XMLSchemaCache40 = "Msxml2.XMLSchemaCache.4.0"
$PROGID_Msxml2XMLSchemaCache60 = "Msxml2.XMLSchemaCache.6.0"
$PROGID_Msxml2XSLTemplate = "Msxml2.XSLTemplate"
$PROGID_Msxml2XSLTemplate26 = "Msxml2.XSLTemplate.2.6"
$PROGID_Msxml2XSLTemplate30 = "Msxml2.XSLTemplate.3.0"
$PROGID_Msxml2XSLTemplate40 = "Msxml2.XSLTemplate.4.0"
$PROGID_Msxml2XSLTemplate60 = "Msxml2.XSLTemplate.6.0"

' ****************************************************************************************
' ClsIDs (Class identifiers)
' ****************************************************************************************

$CLSID_DOMDocument = GUID$("{F6D90F11-9C73-11D3-B32E-00C04F990BB4}")
$CLSID_DOMDocument26 = GUID$("{F5078F1B-C551-11D3-89B9-0000F81FE221}")
$CLSID_DOMDocument30 = GUID$("{F5078F32-C551-11D3-89B9-0000F81FE221}")
$CLSID_DOMDocument40 = GUID$("{88D969C0-F192-11D4-A65F-0040963251E5}")
$CLSID_DOMDocument60 = GUID$("{88D96A05-F192-11D4-A65F-0040963251E5}")
$CLSID_FreeThreadedDOMDocument = GUID$("{F6D90F12-9C73-11D3-B32E-00C04F990BB4}")
$CLSID_FreeThreadedDOMDocument26 = GUID$("{F5078F1C-C551-11D3-89B9-0000F81FE221}")
$CLSID_FreeThreadedDOMDocument30 = GUID$("{F5078F33-C551-11D3-89B9-0000F81FE221}")
$CLSID_FreeThreadedDOMDocument40 = GUID$("{88D969C1-F192-11D4-A65F-0040963251E5}")
$CLSID_FreeThreadedDOMDocument60 = GUID$("{88D96A06-F192-11D4-A65F-0040963251E5}")
$CLSID_MXHTMLWriter = GUID$("{A4C23EC3-6B70-4466-9127-550077239978}")
$CLSID_MXHTMLWriter30 = GUID$("{853D1540-C1A7-4AA9-A226-4D3BD301146D}")
$CLSID_MXHTMLWriter40 = GUID$("{88D969C9-F192-11D4-A65F-0040963251E5}")
$CLSID_MXHTMLWriter60 = GUID$("{88D96A10-F192-11D4-A65F-0040963251E5}")
$CLSID_MXNamespaceManager = GUID$("{88D969D5-F192-11D4-A65F-0040963251E5}")
$CLSID_MXNamespaceManager40 = GUID$("{88D969D6-F192-11D4-A65F-0040963251E5}")
$CLSID_MXNamespaceManager60 = GUID$("{88D96A11-F192-11D4-A65F-0040963251E5}")
$CLSID_MXXMLWriter = GUID$("{FC220AD8-A72A-4EE8-926E-0B7AD152A020}")
$CLSID_MXXMLWriter30 = GUID$("{3D813DFE-6C91-4A4E-8F41-04346A841D9C}")
$CLSID_MXXMLWriter40 = GUID$("{88D969C8-F192-11D4-A65F-0040963251E5}")
$CLSID_MXXMLWriter60 = GUID$("{88D96A0F-F192-11D4-A65F-0040963251E5}")
$CLSID_SAXAttributes = GUID$("{4DD441AD-526D-4A77-9F1B-9841ED802FB0}")
$CLSID_SAXAttributes30 = GUID$("{3E784A01-F3AE-4DC0-9354-9526B9370EBA}")
$CLSID_SAXAttributes40 = GUID$("{88D969CA-F192-11D4-A65F-0040963251E5}")
$CLSID_SAXAttributes60 = GUID$("{88D96A0E-F192-11D4-A65F-0040963251E5}")
$CLSID_SAXXMLReader = GUID$("{079AA557-4A18-424A-8EEE-E39F0A8D41B9}")
$CLSID_SAXXMLReader30 = GUID$("{3124C396-FB13-4836-A6AD-1317F1713688}")
$CLSID_SAXXMLReader40 = GUID$("{7C6E29BC-8B8B-4C3D-859E-AF6CD158BE0F}")
$CLSID_SAXXMLReader60 = GUID$("{88D96A0C-F192-11D4-A65F-0040963251E5}")
$CLSID_ServerXMLHTTP = GUID$("{AFBA6B42-5692-48EA-8141-DC517DCF0EF1}")
$CLSID_ServerXMLHTTP30 = GUID$("{AFB40FFD-B609-40A3-9828-F88BBE11E4E3}")
$CLSID_ServerXMLHTTP40 = GUID$("{88D969C6-F192-11D4-A65F-0040963251E5}")
$CLSID_ServerXMLHTTP60 = GUID$("{88D96A0B-F192-11D4-A65F-0040963251E5}")
$CLSID_XMLHTTP = GUID$("{F6D90F16-9C73-11D3-B32E-00C04F990BB4}")
$CLSID_XMLHTTP26 = GUID$("{F5078F1E-C551-11D3-89B9-0000F81FE221}")
$CLSID_XMLHTTP30 = GUID$("{F5078F35-C551-11D3-89B9-0000F81FE221}")
$CLSID_XMLHTTP40 = GUID$("{88D969C5-F192-11D4-A65F-0040963251E5}")
$CLSID_XMLHTTP60 = GUID$("{88D96A0A-F192-11D4-A65F-0040963251E5}")
$CLSID_XMLSchemaCache = GUID$("{373984C9-B845-449B-91E7-45AC83036ADE}")
$CLSID_XMLSchemaCache26 = GUID$("{F5078F1D-C551-11D3-89B9-0000F81FE221}")
$CLSID_XMLSchemaCache30 = GUID$("{F5078F34-C551-11D3-89B9-0000F81FE221}")
$CLSID_XMLSchemaCache40 = GUID$("{88D969C2-F192-11D4-A65F-0040963251E5}")
$CLSID_XMLSchemaCache60 = GUID$("{88D96A07-F192-11D4-A65F-0040963251E5}")
$CLSID_XSLTemplate = GUID$("{2933BF94-7B36-11D2-B20E-00C04F983E60}")
$CLSID_XSLTemplate26 = GUID$("{F5078F21-C551-11D3-89B9-0000F81FE221}")
$CLSID_XSLTemplate30 = GUID$("{F5078F36-C551-11D3-89B9-0000F81FE221}")
$CLSID_XSLTemplate40 = GUID$("{88D969C3-F192-11D4-A65F-0040963251E5}")
$CLSID_XSLTemplate60 = GUID$("{88D96A08-F192-11D4-A65F-0040963251E5}")

' ****************************************************************************************
' IIDs (Interface identifiers)
' ****************************************************************************************

$IID_IMXAttributes = GUID$("{F10D27CC-3EC0-415C-8ED8-77AB1C5E7262}")
$IID_IMXNamespaceManager = GUID$("{C90352F6-643C-4FBC-BB23-E996EB2D51FD}")
$IID_IMXNamespacePrefixes = GUID$("{C90352F4-643C-4FBC-BB23-E996EB2D51FD}")
$IID_IMXReaderControl = GUID$("{808F4E35-8D5A-4FBE-8466-33A41279ED30}")
$IID_IMXSchemaDeclHandler = GUID$("{FA4BB38C-FAF9-4CCA-9302-D1DD0FE520DB}")
$IID_IMXWriter = GUID$("{4D7FF4BA-1565-4EA8-94E1-6E724A46F98D}")
$IID_IMXXMLFilter = GUID$("{C90352F7-643C-4FBC-BB23-E996EB2D51FD}")
$IID_ISAXAttributes = GUID$("{F078ABE1-45D2-4832-91EA-4466CE2F25C9}")
$IID_ISAXContentHandler = GUID$("{1545CDFA-9E4E-4497-A8A4-2BF7D0112C44}")
$IID_ISAXDeclHandler = GUID$("{862629AC-771A-47B2-8337-4E6843C1BE90}")
$IID_ISAXDTDHandler = GUID$("{E15C1BAF-AFB3-4D60-8C36-19A8C45DEFED}")
$IID_ISAXEntityResolver = GUID$("{99BCA7BD-E8C4-4D5F-A0CF-6D907901FF07}")
$IID_ISAXErrorHandler = GUID$("{A60511C4-CCF5-479E-98A3-DC8DC545B7D0}")
$IID_ISAXLexicalHandler = GUID$("{7F85D5F5-47A8-4497-BDA5-84BA04819EA6}")
$IID_ISAXLocator = GUID$("{9B7E472A-0DE4-4640-BFF3-84D38A051C31}")
$IID_ISAXXMLFilter = GUID$("{70409222-CA09-4475-ACB8-40312FE8D145}")
$IID_ISAXXMLReader = GUID$("{A4F96ED0-F829-476E-81C0-CDC7BD2A0802}")
$IID_ISchema = GUID$("{50EA08B4-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaAny = GUID$("{50EA08BC-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaAttribute = GUID$("{50EA08B6-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaAttributeGroup = GUID$("{50EA08BA-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaComplexType = GUID$("{50EA08B9-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaElement = GUID$("{50EA08B7-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaIdentityConstraint = GUID$("{50EA08BD-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaItem = GUID$("{50EA08B3-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaItemCollection = GUID$("{50EA08B2-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaModelGroup = GUID$("{50EA08BB-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaNotation = GUID$("{50EA08BE-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaParticle = GUID$("{50EA08B5-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaStringCollection = GUID$("{50EA08B1-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_ISchemaType = GUID$("{50EA08B8-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_IServerXMLHTTPRequest = GUID$("{2E9196BF-13BA-4DD4-91CA-6C571F281495}")
$IID_IServerXMLHTTPRequest2 = GUID$("{2E01311B-C322-4B0A-BD77-B90CFDC8DCE7}")
$IID_IVBMXNamespaceManager = GUID$("{C90352F5-643C-4FBC-BB23-E996EB2D51FD}")
$IID_IVBSAXAttributes = GUID$("{10DC0586-132B-4CAC-8BB3-DB00AC8B7EE0}")
$IID_IVBSAXContentHandler = GUID$("{2ED7290A-4DD5-4B46-BB26-4E4155E77FAA}")
$IID_IVBSAXDeclHandler = GUID$("{E8917260-7579-4BE1-B5DD-7AFBFA6F077B}")
$IID_IVBSAXDTDHandler = GUID$("{24FB3297-302D-4620-BA39-3A732D850558}")
$IID_IVBSAXEntityResolver = GUID$("{0C05D096-F45B-4ACA-AD1A-AA0BC25518DC}")
$IID_IVBSAXErrorHandler = GUID$("{D963D3FE-173C-4862-9095-B92F66995F52}")
$IID_IVBSAXLexicalHandler = GUID$("{032AAC35-8C0E-4D9D-979F-E3B702935576}")
$IID_IVBSAXLocator = GUID$("{796E7AC5-5AA2-4EFF-ACAD-3FAAF01A3288}")
$IID_IVBSAXXMLFilter = GUID$("{1299EB1B-5B88-433E-82DE-82CA75AD4E04}")
$IID_IVBSAXXMLReader = GUID$("{8C033CAA-6CD6-4F73-B728-4531AF74945F}")
$IID_IXMLDOMAttribute = GUID$("{2933BF85-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMCDATASection = GUID$("{2933BF8A-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMCharacterData = GUID$("{2933BF84-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMComment = GUID$("{2933BF88-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMDocument = GUID$("{2933BF81-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMDocument2 = GUID$("{2933BF95-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMDocument3 = GUID$("{2933BF96-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMDocumentFragment = GUID$("{3EFAA413-272F-11D2-836F-0000F87A7782}")
$IID_IXMLDOMDocumentType = GUID$("{2933BF8B-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMElement = GUID$("{2933BF86-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMEntity = GUID$("{2933BF8D-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMEntityReference = GUID$("{2933BF8E-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMImplementation = GUID$("{2933BF8F-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMNamedNodeMap = GUID$("{2933BF83-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMNode = GUID$("{2933BF80-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMNodeList = GUID$("{2933BF82-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMNotation = GUID$("{2933BF8C-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMParseError = GUID$("{3EFAA426-272F-11D2-836F-0000F87A7782}")
$IID_IXMLDOMParseError2 = GUID$("{3EFAA428-272F-11D2-836F-0000F87A7782}")
$IID_IXMLDOMParseErrorCollection = GUID$("{3EFAA429-272F-11D2-836F-0000F87A7782}")
$IID_IXMLDOMProcessingInstruction = GUID$("{2933BF89-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLDOMSchemaCollection = GUID$("{373984C8-B845-449B-91E7-45AC83036ADE}")
$IID_IXMLDOMSchemaCollection2 = GUID$("{50EA08B0-DD1B-4664-9A50-C2F40F4BD79A}")
$IID_IXMLDOMSelection = GUID$("{AA634FC7-5888-44A7-A257-3A47150D3A0E}")
$IID_IXMLDOMText = GUID$("{2933BF87-7B36-11D2-B20E-00C04F983E60}")
$IID_IXMLHTTPRequest = GUID$("{ED8C108D-4349-11D2-91A4-00C04F7969E8}")
$IID_IXSLProcessor = GUID$("{2933BF92-7B36-11D2-B20E-00C04F983E60}")
$IID_IXSLTemplate = GUID$("{2933BF93-7B36-11D2-B20E-00C04F983E60}")
$IID_IXTLRuntime = GUID$("{3EFAA425-272F-11D2-836F-0000F87A7782}")
$IID_XMLDOMDocumentEvents = GUID$("{3EFAA427-272F-11D2-836F-0000F87A7782}")

' ****************************************************************************************
' DOMNodeType enum <alias> tagDOMNodeType
' Constants that define a node's type
' ****************************************************************************************

%NODE_INVALID                                           = 0            ' &H0
%NODE_ELEMENT                                           = 1            ' &H1
%NODE_ATTRIBUTE                                         = 2            ' &H2
%NODE_TEXT                                              = 3            ' &H3
%NODE_CDATA_SECTION                                     = 4            ' &H4
%NODE_ENTITY_REFERENCE                                  = 5            ' &H5
%NODE_ENTITY                                            = 6            ' &H6
%NODE_PROCESSING_INSTRUCTION                            = 7            ' &H7
%NODE_COMMENT                                           = 8            ' &H8
%NODE_DOCUMENT                                          = 9            ' &H9
%NODE_DOCUMENT_TYPE                                     = 10           ' &HA
%NODE_DOCUMENT_FRAGMENT                                 = 11           ' &HB
%NODE_NOTATION                                          = 12           ' &HC

' ****************************************************************************************
' SOMITEMTYPE enum <alias> _SOMITEMTYPE
' Schema Object Model Item Types
' ****************************************************************************************

%SOMITEM_SCHEMA                                         = 4096         ' &H1000
%SOMITEM_ATTRIBUTE                                      = 4097         ' &H1001
%SOMITEM_ATTRIBUTEGROUP                                 = 4098         ' &H1002
%SOMITEM_NOTATION                                       = 4099         ' &H1003
%SOMITEM_ANNOTATION                                     = 4100         ' &H1004
%SOMITEM_IDENTITYCONSTRAINT                             = 4352         ' &H1100
%SOMITEM_KEY                                            = 4353         ' &H1101
%SOMITEM_KEYREF                                         = 4354         ' &H1102
%SOMITEM_UNIQUE                                         = 4355         ' &H1103
%SOMITEM_ANYTYPE                                        = 8192         ' &H2000
%SOMITEM_DATATYPE                                       = 8448         ' &H2100
%SOMITEM_DATATYPE_ANYTYPE                               = 8449         ' &H2101
%SOMITEM_DATATYPE_ANYURI                                = 8450         ' &H2102
%SOMITEM_DATATYPE_BASE64BINARY                          = 8451         ' &H2103
%SOMITEM_DATATYPE_BOOLEAN                               = 8452         ' &H2104
%SOMITEM_DATATYPE_BYTE                                  = 8453         ' &H2105
%SOMITEM_DATATYPE_DATE                                  = 8454         ' &H2106
%SOMITEM_DATATYPE_DATETIME                              = 8455         ' &H2107
%SOMITEM_DATATYPE_DAY                                   = 8456         ' &H2108
%SOMITEM_DATATYPE_DECIMAL                               = 8457         ' &H2109
%SOMITEM_DATATYPE_DOUBLE                                = 8458         ' &H210A
%SOMITEM_DATATYPE_DURATION                              = 8459         ' &H210B
%SOMITEM_DATATYPE_ENTITIES                              = 8460         ' &H210C
%SOMITEM_DATATYPE_ENTITY                                = 8461         ' &H210D
%SOMITEM_DATATYPE_FLOAT                                 = 8462         ' &H210E
%SOMITEM_DATATYPE_HEXBINARY                             = 8463         ' &H210F
%SOMITEM_DATATYPE_ID                                    = 8464         ' &H2110
%SOMITEM_DATATYPE_IDREF                                 = 8465         ' &H2111
%SOMITEM_DATATYPE_IDREFS                                = 8466         ' &H2112
%SOMITEM_DATATYPE_INT                                   = 8467         ' &H2113
%SOMITEM_DATATYPE_INTEGER                               = 8468         ' &H2114
%SOMITEM_DATATYPE_LANGUAGE                              = 8469         ' &H2115
%SOMITEM_DATATYPE_LONG                                  = 8470         ' &H2116
%SOMITEM_DATATYPE_MONTH                                 = 8471         ' &H2117
%SOMITEM_DATATYPE_MONTHDAY                              = 8472         ' &H2118
%SOMITEM_DATATYPE_NAME                                  = 8473         ' &H2119
%SOMITEM_DATATYPE_NCNAME                                = 8474         ' &H211A
%SOMITEM_DATATYPE_NEGATIVEINTEGER                       = 8475         ' &H211B
%SOMITEM_DATATYPE_NMTOKEN                               = 8476         ' &H211C
%SOMITEM_DATATYPE_NMTOKENS                              = 8477         ' &H211D
%SOMITEM_DATATYPE_NONNEGATIVEINTEGER                    = 8478         ' &H211E
%SOMITEM_DATATYPE_NONPOSITIVEINTEGER                    = 8479         ' &H211F
%SOMITEM_DATATYPE_NORMALIZEDSTRING                      = 8480         ' &H2120
%SOMITEM_DATATYPE_NOTATION                              = 8481         ' &H2121
%SOMITEM_DATATYPE_POSITIVEINTEGER                       = 8482         ' &H2122
%SOMITEM_DATATYPE_QNAME                                 = 8483         ' &H2123
%SOMITEM_DATATYPE_SHORT                                 = 8484         ' &H2124
%SOMITEM_DATATYPE_STRING                                = 8485         ' &H2125
%SOMITEM_DATATYPE_TIME                                  = 8486         ' &H2126
%SOMITEM_DATATYPE_TOKEN                                 = 8487         ' &H2127
%SOMITEM_DATATYPE_UNSIGNEDBYTE                          = 8488         ' &H2128
%SOMITEM_DATATYPE_UNSIGNEDINT                           = 8489         ' &H2129
%SOMITEM_DATATYPE_UNSIGNEDLONG                          = 8490         ' &H212A
%SOMITEM_DATATYPE_UNSIGNEDSHORT                         = 8491         ' &H212B
%SOMITEM_DATATYPE_YEAR                                  = 8492         ' &H212C
%SOMITEM_DATATYPE_YEARMONTH                             = 8493         ' &H212D
%SOMITEM_DATATYPE_ANYSIMPLETYPE                         = 8703         ' &H21FF
%SOMITEM_SIMPLETYPE                                     = 8704         ' &H2200
%SOMITEM_COMPLEXTYPE                                    = 9216         ' &H2400
%SOMITEM_PARTICLE                                       = 16384        ' &H4000
%SOMITEM_ANY                                            = 16385        ' &H4001
%SOMITEM_ANYATTRIBUTE                                   = 16386        ' &H4002
%SOMITEM_ELEMENT                                        = 16387        ' &H4003
%SOMITEM_GROUP                                          = 16640        ' &H4100
%SOMITEM_ALL                                            = 16641        ' &H4101
%SOMITEM_CHOICE                                         = 16642        ' &H4102
%SOMITEM_SEQUENCE                                       = 16643        ' &H4103
%SOMITEM_EMPTYPARTICLE                                  = 16644        ' &H4104
%SOMITEM_NULL                                           = 2048         ' &H800
%SOMITEM_NULL_TYPE                                      = 10240        ' &H2800
%SOMITEM_NULL_ANY                                       = 18433        ' &H4801
%SOMITEM_NULL_ANYATTRIBUTE                              = 18434        ' &H4802
%SOMITEM_NULL_ELEMENT                                   = 18435        ' &H4803

' ****************************************************************************************
' SCHEMADERIVATIONMETHOD enum <alias> _SCHEMADERIVATIONMETHOD
' Schema Object Model Filters
' ****************************************************************************************

%SCHEMADERIVATIONMETHOD_EMPTY                           = 0            ' &H0
%SCHEMADERIVATIONMETHOD_SUBSTITUTION                    = 1            ' &H1
%SCHEMADERIVATIONMETHOD_EXTENSION                       = 2            ' &H2
%SCHEMADERIVATIONMETHOD_RESTRICTION                     = 4            ' &H4
%SCHEMADERIVATIONMETHOD_LIST                            = 8            ' &H8
%SCHEMADERIVATIONMETHOD_UNION                           = 16           ' &H10
%SCHEMADERIVATIONMETHOD_ALL                             = 255          ' &HFF
%SCHEMADERIVATIONMETHOD_NONE                            = 256          ' &H100

' ****************************************************************************************
' SCHEMATYPEVARIETY enum <alias> _SCHEMATYPEVARIETY
' Schema Object Model Type variety values
' ****************************************************************************************

%SCHEMATYPEVARIETY_NONE                                 = -1           ' &HFFFFFFFF
%SCHEMATYPEVARIETY_ATOMIC                               = 0            ' &H0
%SCHEMATYPEVARIETY_LIST                                 = 1            ' &H1
%SCHEMATYPEVARIETY_UNION                                = 2            ' &H2

' ****************************************************************************************
' SCHEMAWHITESPACE enum <alias> _SCHEMAWHITESPACE
' Schema Object Model Whitespace facet values
' ****************************************************************************************

%SCHEMAWHITESPACE_NONE                                  = -1           ' &HFFFFFFFF
%SCHEMAWHITESPACE_PRESERVE                              = 0            ' &H0
%SCHEMAWHITESPACE_REPLACE                               = 1            ' &H1
%SCHEMAWHITESPACE_COLLAPSE                              = 2            ' &H2

' ****************************************************************************************
' SCHEMAPROCESSCONTENTS enum <alias> _SCHEMAPROCESSCONTENTS
' Schema Object Model Process Contents
' ****************************************************************************************

%SCHEMAPROCESSCONTENTS_NONE                             = 0            ' &H0
%SCHEMAPROCESSCONTENTS_SKIP                             = 1            ' &H1
%SCHEMAPROCESSCONTENTS_LAX                              = 2            ' &H2
%SCHEMAPROCESSCONTENTS_STRICT                           = 3            ' &H3

' ****************************************************************************************
' SCHEMACONTENTTYPE enum <alias> _SCHEMACONTENTTYPE
' Schema Object Model Content Types
' ****************************************************************************************

%SCHEMACONTENTTYPE_EMPTY                                = 0            ' &H0
%SCHEMACONTENTTYPE_TEXTONLY                             = 1            ' &H1
%SCHEMACONTENTTYPE_ELEMENTONLY                          = 2            ' &H2
%SCHEMACONTENTTYPE_MIXED                                = 3            ' &H3

' ****************************************************************************************
' SCHEMAUSE enum <alias> _SCHEMAUSE
' Schema Object Model Attribute Uses
' ****************************************************************************************

%SCHEMAUSE_OPTIONAL                                     = 0            ' &H0
%SCHEMAUSE_PROHIBITED                                   = 1            ' &H1
%SCHEMAUSE_REQUIRED                                     = 2            ' &H2

' ****************************************************************************************
' SERVERXMLHTTP_OPTION enum <alias> _SERVERXMLHTTP_OPTION
' Options for ServerXMLHTTPRequest Option property
' ****************************************************************************************

%SXH_OPTION_URL                                         = -1           ' &HFFFFFFFF
%SXH_OPTION_URL_CODEPAGE                                = 0            ' &H0
%SXH_OPTION_ESCAPE_PERCENT_IN_URL                       = 1            ' &H1
%SXH_OPTION_IGNORE_SERVER_SSL_CERT_ERROR_FLAGS          = 2            ' &H2
%SXH_OPTION_SELECT_CLIENT_SSL_CERT                      = 3            ' &H3

' ****************************************************************************************
' SXH_SERVER_CERT_OPTION enum <alias> _SXH_SERVER_CERT_OPTION
' Flags for SXH_OPTION_IGNORE_SERVER_SSL_CERT_ERROR_FLAGS option
' ****************************************************************************************

%SXH_SERVER_CERT_IGNORE_UNKNOWN_CA                      = 256          ' &H100
%SXH_SERVER_CERT_IGNORE_WRONG_USAGE                     = 512          ' &H200
%SXH_SERVER_CERT_IGNORE_CERT_CN_INVALID                 = 4096         ' &H1000
%SXH_SERVER_CERT_IGNORE_CERT_DATE_INVALID               = 8192         ' &H2000
%SXH_SERVER_CERT_IGNORE_ALL_SERVER_ERRORS               = 13056        ' &H3300

' ****************************************************************************************
' SXH_PROXY_SETTING enum <alias> _SXH_PROXY_SETTING
' Settings for setProxy
' ****************************************************************************************

%SXH_PROXY_SET_DEFAULT                                  = 0            ' &H0
%SXH_PROXY_SET_PRECONFIG                                = 0            ' &H0
%SXH_PROXY_SET_DIRECT                                   = 1            ' &H1
%SXH_PROXY_SET_PROXY                                    = 2            ' &H2

' ****************************************************************************************
DECLARE FUNCTION XmlError LIB "TB_XML60.DLL" ALIAS "XmlError" () AS LONG
DECLARE FUNCTION XmlResult LIB "TB_XML60.DLL" ALIAS "XmlResult" () AS LONG
DECLARE FUNCTION XmlQueryInterface LIB "TB_XML60.DLL" ALIAS "XmlQueryInterface" (BYVAL pthis AS DWORD PTR, BYREF riid AS GUID) AS DWORD
DECLARE FUNCTION XmlAddRef LIB "TB_XML60.DLL" ALIAS "XmlAddRef" (BYVAL pthis AS DWORD PTR) AS DWORD
DECLARE FUNCTION XmlRelease LIB "TB_XML60.DLL" ALIAS "XmlRelease" (BYVAL pthis AS DWORD PTR) AS DWORD
DECLARE FUNCTION XmlCreateObject LIB "TB_XML60.DLL" ALIAS "XmlCreateObject" (BYVAL strProgID AS STRING) AS DWORD
DECLARE FUNCTION XmlGetExePath LIB "TB_XML60.DLL" ALIAS "XmlGetExePath" () AS STRING
' ****************************************************************************************


' ########################################################################################
'                              XML Helper Objects/Interfaces
' ########################################################################################


' ########################################################################################
' Interface name = IMXNamespacePrefixes
' IID = {C90352F4-643C-4FBC-BB23-E996EB2D51FD}
' IMXNamespacePrefixes interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IMXNamespacePrefixes_get_item LIB "TB_XML60.DLL" ALIAS "IMXNamespacePrefixes_get_item" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL index AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IMXNamespacePrefixes_get_length LIB "TB_XML60.DLL" ALIAS "IMXNamespacePrefixes_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IMXNamespacePrefixes_get_newEnum LIB "TB_XML60.DLL" ALIAS "IMXNamespacePrefixes_get_newEnum" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' *%VT_UNKNOWN <IUNKNOWN> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = IVBMXNamespaceManager
' IID = {C90352F5-643C-4FBC-BB23-E996EB2D51FD}
' IVBMXNamespaceManager interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE SUB IVBMXNamespaceManager_put_allowOverride LIB "TB_XML60.DLL" ALIAS "IVBMXNamespaceManager_put_allowOverride" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL fOverride AS INTEGER _                        ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IVBMXNamespaceManager_get_allowOverride LIB "TB_XML60.DLL" ALIAS "IVBMXNamespaceManager_get_allowOverride" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IVBMXNamespaceManager_reset LIB "TB_XML60.DLL" ALIAS "IVBMXNamespaceManager_reset" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE SUB IVBMXNamespaceManager_pushContext LIB "TB_XML60.DLL" ALIAS "IVBMXNamespaceManager_pushContext" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE SUB IVBMXNamespaceManager_pushNodeContext LIB "TB_XML60.DLL" ALIAS "IVBMXNamespaceManager_pushNodeContext" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL contextNode AS DWORD _                        ' *IXMLDOMNode <dispinterface> [in]
  , OPTIONAL BYVAL fDeep AS INTEGER _                   ' %VT_BOOL <INTEGER> [opt] [in] [hasdefault = -1]
    )
' ****************************************************************************************
DECLARE SUB IVBMXNamespaceManager_popContext LIB "TB_XML60.DLL" ALIAS "IVBMXNamespaceManager_popContext" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE SUB IVBMXNamespaceManager_declarePrefix LIB "TB_XML60.DLL" ALIAS "IVBMXNamespaceManager_declarePrefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL prefix AS STRING _                            ' <ANSI STRING> [in]
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IVBMXNamespaceManager_getDeclaredPrefixes LIB "TB_XML60.DLL" ALIAS "IVBMXNamespaceManager_getDeclaredPrefixes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IMXNamespacePrefixes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IVBMXNamespaceManager_getPrefixes LIB "TB_XML60.DLL" ALIAS "IVBMXNamespaceManager_getPrefixes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IMXNamespacePrefixes <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IVBMXNamespaceManager_getURI LIB "TB_XML60.DLL" ALIAS "IVBMXNamespaceManager_getURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL prefix AS STRING _                            ' <ANSI STRING> [in]
  , BYREF uri AS VARIANT _                              ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IVBMXNamespaceManager_getURIFromNode LIB "TB_XML60.DLL" ALIAS "IVBMXNamespaceManager_getURIFromNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strPrefix AS STRING _                         ' <ANSI STRING> [in]
  , BYVAL contextNode AS DWORD _                        ' *IXMLDOMNode <dispinterface> [in]
  , BYREF uri AS VARIANT _                              ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IMXNamespaceManager
' IID = {C90352F6-643C-4FBC-BB23-E996EB2D51FD}
' IMXNamespaceManager interface
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

' ****************************************************************************************
DECLARE SUB IMXNamespaceManager_putAllowOverride LIB "TB_XML60.DLL" ALIAS "IMXNamespaceManager_putAllowOverride" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL fOverride AS INTEGER _                        ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXNamespaceManager_getAllowOverride LIB "TB_XML60.DLL" ALIAS "IMXNamespaceManager_getAllowOverride" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS INTEGER                                        ' *%VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IMXNamespaceManager_reset LIB "TB_XML60.DLL" ALIAS "IMXNamespaceManager_reset" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    )
' ****************************************************************************************
DECLARE SUB IMXNamespaceManager_pushContext LIB "TB_XML60.DLL" ALIAS "IMXNamespaceManager_pushContext" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    )
' ****************************************************************************************
DECLARE SUB IMXNamespaceManager_pushNodeContext LIB "TB_XML60.DLL" ALIAS "IMXNamespaceManager_pushNodeContext" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL contextNode AS DWORD _                        ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL fDeep AS INTEGER _                            ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXNamespaceManager_popContext LIB "TB_XML60.DLL" ALIAS "IMXNamespaceManager_popContext" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    )
' ****************************************************************************************
DECLARE SUB IMXNamespaceManager_declarePrefix LIB "TB_XML60.DLL" ALIAS "IMXNamespaceManager_declarePrefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL prefix AS STRING _                            ' *%VT_PTR <Pointer> <WORD>
  , BYVAL namespaceURI AS STRING _                      ' *%VT_PTR <Pointer> <WORD>
    )
' ****************************************************************************************
DECLARE FUNCTION IMXNamespaceManager_getDeclaredPrefix LIB "TB_XML60.DLL" ALIAS "IMXNamespaceManager_getDeclaredPrefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL nIndex AS LONG _                              ' %VT_I4 <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IMXNamespaceManager_getPrefix LIB "TB_XML60.DLL" ALIAS "IMXNamespaceManager_getPrefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwszNamespaceURI AS STRING _                  ' *%VT_PTR <Pointer> <WORD>
  , BYVAL nIndex AS LONG _                              ' %VT_I4 <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IMXNamespaceManager_getURI LIB "TB_XML60.DLL" ALIAS "IMXNamespaceManager_getURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchPrefix AS STRING _                        ' *%VT_PTR <Pointer> <WORD>
  , BYVAL pContextNode AS DWORD _                       ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLHTTPRequest
' IID = {ED8C108D-4349-11D2-91A4-00C04F7969E8}
' IXMLHTTPRequest Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE SUB IXMLHTTPRequest_open LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_open" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrMethod AS STRING _                        ' <ANSI STRING> [in]
  , BYVAL bstrUrl AS STRING _                           ' <ANSI STRING> [in]
  , OPTIONAL BYVAL varAsync AS VARIANT _                ' %VT_VARIANT <VARIANT> [opt] [in]
  , OPTIONAL BYVAL bstrUser AS VARIANT _                ' %VT_VARIANT <VARIANT> [opt] [in]
  , OPTIONAL BYVAL bstrPassword AS VARIANT _            ' %VT_VARIANT <VARIANT> [opt] [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLHTTPRequest_setRequestHeader LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_setRequestHeader" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrHeader AS STRING _                        ' <ANSI STRING> [in]
  , BYVAL bstrValue AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLHTTPRequest_getResponseHeader LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_getResponseHeader" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrHeader AS STRING _                        ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLHTTPRequest_getAllResponseHeaders LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_getAllResponseHeaders" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLHTTPRequest_send LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_send" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , OPTIONAL BYVAL varBody AS VARIANT _                 ' %VT_VARIANT <VARIANT> [opt] [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLHTTPRequest_abort LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_abort" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLHTTPRequest_get_status LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_status" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLHTTPRequest_get_statusText LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_statusText" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLHTTPRequest_get_responseXML LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_responseXML" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' *%VT_DISPATCH <IDISPATCH> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLHTTPRequest_get_responseText LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_responseText" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLHTTPRequest_get_responseBody LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_responseBody" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF pvarBody AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLHTTPRequest_get_responseStream LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_responseStream" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF pvarBody AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLHTTPRequest_get_readyState LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_readyState" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE SUB IXMLHTTPRequest_put_onreadystatechange LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_put_onreadystatechange" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pDispatch AS DWORD _                          ' %VT_DISPATCH <IDISPATCH> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXSLProcessor
' IID = {2933BF92-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE SUB IXSLProcessor_put_input LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_put_input" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pVar AS VARIANT _                             ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXSLProcessor_get_input LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_get_input" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF pVar AS VARIANT _                             ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION IXSLProcessor_get_ownerTemplate LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_get_ownerTemplate" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXSLTemplate <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXSLProcessor_setStartMode LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_setStartMode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL mode AS STRING _                              ' <ANSI STRING> [in]
  , OPTIONAL BYVAL namespaceURI AS STRING _             ' <ANSI STRING> [opt] [in] [hasdefault = ""]
    )
' ****************************************************************************************
DECLARE FUNCTION IXSLProcessor_get_startMode LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_get_startMode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXSLProcessor_get_startModeURI LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_get_startModeURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXSLProcessor_put_output LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_put_output" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pOutput AS VARIANT _                          ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXSLProcessor_get_output LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_get_output" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF pOutput AS VARIANT _                          ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION IXSLProcessor_transform LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_transform" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE SUB IXSLProcessor_reset LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_reset" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE FUNCTION IXSLProcessor_get_readyState LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_get_readyState" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE SUB IXSLProcessor_addParameter LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_addParameter" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL baseName AS STRING _                          ' <ANSI STRING> [in]
  , BYVAL parameter AS VARIANT _                        ' %VT_VARIANT <VARIANT> [in]
  , OPTIONAL BYVAL namespaceURI AS STRING _             ' <ANSI STRING> [opt] [in] [hasdefault = ""]
    )
' ****************************************************************************************
DECLARE SUB IXSLProcessor_addObject LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_addObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL obj AS DWORD _                                ' %VT_DISPATCH <IDISPATCH> [in]
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXSLProcessor_get_stylesheet LIB "TB_XML60.DLL" ALIAS "IXSLProcessor_get_stylesheet" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = IXSLTemplate
' IID = {2933BF93-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE SUB IXSLTemplate_putref_stylesheet LIB "TB_XML60.DLL" ALIAS "IXSLTemplate_putref_stylesheet" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXSLTemplate_get_stylesheet LIB "TB_XML60.DLL" ALIAS "IXSLTemplate_get_stylesheet" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXSLTemplate_createProcessor LIB "TB_XML60.DLL" ALIAS "IXSLTemplate_createProcessor" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXSLProcessor <dispinterface> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = IServerXMLHTTPRequest
' IID = {2E9196BF-13BA-4DD4-91CA-6C571F281495}
' IServerXMLHTTPRequest Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IXMLHTTPRequest
' ########################################################################################

' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest_open LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_open" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrMethod AS STRING _                        ' <ANSI STRING> [in]
  , BYVAL bstrUrl AS STRING _                           ' <ANSI STRING> [in]
  , OPTIONAL BYVAL varAsync AS VARIANT _                ' %VT_VARIANT <VARIANT> [opt] [in]
  , OPTIONAL BYVAL bstrUser AS VARIANT _                ' %VT_VARIANT <VARIANT> [opt] [in]
  , OPTIONAL BYVAL bstrPassword AS VARIANT _            ' %VT_VARIANT <VARIANT> [opt] [in]
    )
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest_setRequestHeader LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_setRequestHeader" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrHeader AS STRING _                        ' <ANSI STRING> [in]
  , BYVAL bstrValue AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest_getResponseHeader LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_getResponseHeader" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrHeader AS STRING _                        ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest_getAllResponseHeaders LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_getAllResponseHeaders" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest_send LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_send" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , OPTIONAL BYVAL varBody AS VARIANT _                 ' %VT_VARIANT <VARIANT> [opt] [in]
    )
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest_abort LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_abort" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest_get_status LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_status" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest_get_statusText LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_statusText" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest_get_responseXML LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_responseXML" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' *%VT_DISPATCH <IDISPATCH> [out]
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest_get_responseText LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_responseText" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest_get_responseBody LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_responseBody" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF pvarBody AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest_get_responseStream LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_responseStream" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF pvarBody AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest_get_readyState LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_readyState" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest_put_onreadystatechange LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_put_onreadystatechange" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pDispatch AS DWORD _                          ' %VT_DISPATCH <IDISPATCH> [in]
    )
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest_setTimeouts LIB "TB_XML60.DLL" ALIAS "IServerXMLHTTPRequest_setTimeouts" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL resolveTimeout AS LONG _                      ' %VT_I4 <LONG> [in]
  , BYVAL connectTimeout AS LONG _                      ' %VT_I4 <LONG> [in]
  , BYVAL sendTimeout AS LONG _                         ' %VT_I4 <LONG> [in]
  , BYVAL receiveTimeout AS LONG _                      ' %VT_I4 <LONG> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest_waitForResponse LIB "TB_XML60.DLL" ALIAS "IServerXMLHTTPRequest_waitForResponse" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , OPTIONAL BYVAL timeoutInSeconds AS VARIANT _        ' %VT_VARIANT <VARIANT> [opt] [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest_getOption LIB "TB_XML60.DLL" ALIAS "IServerXMLHTTPRequest_getOption" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL noption AS LONG _                             ' SERVERXMLHTTP_OPTION <enum> [in]
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest_setOption LIB "TB_XML60.DLL" ALIAS "IServerXMLHTTPRequest_setOption" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL noption AS LONG _                             ' SERVERXMLHTTP_OPTION <enum> [in]
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IServerXMLHTTPRequest2
' IID = {2E01311B-C322-4B0A-BD77-B90CFDC8DCE7}
' IServerXMLHTTPRequest2 Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IServerXMLHTTPRequest
' ########################################################################################

' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest2_open LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_open" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrMethod AS STRING _                        ' <ANSI STRING> [in]
  , BYVAL bstrUrl AS STRING _                           ' <ANSI STRING> [in]
  , OPTIONAL BYVAL varAsync AS VARIANT _                ' %VT_VARIANT <VARIANT> [opt] [in]
  , OPTIONAL BYVAL bstrUser AS VARIANT _                ' %VT_VARIANT <VARIANT> [opt] [in]
  , OPTIONAL BYVAL bstrPassword AS VARIANT _            ' %VT_VARIANT <VARIANT> [opt] [in]
    )
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest2_setRequestHeader LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_setRequestHeader" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrHeader AS STRING _                        ' <ANSI STRING> [in]
  , BYVAL bstrValue AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest2_getResponseHeader LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_getResponseHeader" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrHeader AS STRING _                        ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest2_getAllResponseHeaders LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_getAllResponseHeaders" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest2_send LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_send" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , OPTIONAL BYVAL varBody AS VARIANT _                 ' %VT_VARIANT <VARIANT> [opt] [in]
    )
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest2_abort LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_abort" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest2_get_status LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_status" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest2_get_statusText LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_statusText" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest2_get_responseXML LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_responseXML" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' *%VT_DISPATCH <IDISPATCH> [out]
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest2_get_responseText LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_responseText" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest2_get_responseBody LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_responseBody" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF pvarBody AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest2_get_responseStream LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_responseStream" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF pvarBody AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest2_get_readyState LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_get_readyState" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest2_put_onreadystatechange LIB "TB_XML60.DLL" ALIAS "IXMLHTTPRequest_put_onreadystatechange" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pDispatch AS DWORD _                          ' %VT_DISPATCH <IDISPATCH> [in]
    )
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest2_setTimeouts LIB "TB_XML60.DLL" ALIAS "IServerXMLHTTPRequest_setTimeouts" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL resolveTimeout AS LONG _                      ' %VT_I4 <LONG> [in]
  , BYVAL connectTimeout AS LONG _                      ' %VT_I4 <LONG> [in]
  , BYVAL sendTimeout AS LONG _                         ' %VT_I4 <LONG> [in]
  , BYVAL receiveTimeout AS LONG _                      ' %VT_I4 <LONG> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IServerXMLHTTPRequest2_waitForResponse LIB "TB_XML60.DLL" ALIAS "IServerXMLHTTPRequest_waitForResponse" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , OPTIONAL BYVAL timeoutInSeconds AS VARIANT _        ' %VT_VARIANT <VARIANT> [opt] [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest2_getOption LIB "TB_XML60.DLL" ALIAS "IServerXMLHTTPRequest_getOption" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL noption AS LONG _                             ' SERVERXMLHTTP_OPTION <enum> [in]
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest2_setOption LIB "TB_XML60.DLL" ALIAS "IServerXMLHTTPRequest_setOption" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL noption AS LONG _                             ' SERVERXMLHTTP_OPTION <enum> [in]
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest2_setProxy LIB "TB_XML60.DLL" ALIAS "IServerXMLHTTPRequest2_setProxy" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL proxySetting AS LONG _                        ' SXH_PROXY_SETTING <enum> [in]
  , OPTIONAL BYVAL varProxyServer AS VARIANT _          ' %VT_VARIANT <VARIANT> [opt] [in]
  , OPTIONAL BYVAL varBypassList AS VARIANT _           ' %VT_VARIANT <VARIANT> [opt] [in]
    )
' ****************************************************************************************
DECLARE SUB IServerXMLHTTPRequest2_setProxyCredentials LIB "TB_XML60.DLL" ALIAS "IServerXMLHTTPRequest2_setProxyCredentials" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrUserName AS STRING _                      ' <ANSI STRING> [in]
  , BYVAL bstrPassword AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXTLRuntime
' IID = {3EFAA425-272F-11D2-836F-0000F87A7782}
' XTL runtime object
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMNode
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXTLRuntime_uniqueID LIB "TB_XML60.DLL" ALIAS "IXTLRuntime_uniqueID" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pNode AS DWORD _                              ' *IXMLDOMNode <dispinterface> [in]
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXTLRuntime_depth LIB "TB_XML60.DLL" ALIAS "IXTLRuntime_depth" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pNode AS DWORD _                              ' *IXMLDOMNode <dispinterface> [in]
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXTLRuntime_childNumber LIB "TB_XML60.DLL" ALIAS "IXTLRuntime_childNumber" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pNode AS DWORD _                              ' *IXMLDOMNode <dispinterface> [in]
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXTLRuntime_ancestorChildNumber LIB "TB_XML60.DLL" ALIAS "IXTLRuntime_ancestorChildNumber" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrNodeName AS STRING _                      ' <ANSI STRING> [in]
  , BYVAL pNode AS DWORD _                              ' *IXMLDOMNode <dispinterface> [in]
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXTLRuntime_absoluteChildNumber LIB "TB_XML60.DLL" ALIAS "IXTLRuntime_absoluteChildNumber" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pNode AS DWORD _                              ' *IXMLDOMNode <dispinterface> [in]
    ) AS LONG                                           ' %VT_HRESULT <LONG>
' ****************************************************************************************
DECLARE FUNCTION IXTLRuntime_formatIndex LIB "TB_XML60.DLL" ALIAS "IXTLRuntime_formatIndex" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL lIndex AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL bstrFormat AS STRING _                        ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXTLRuntime_formatNumber LIB "TB_XML60.DLL" ALIAS "IXTLRuntime_formatNumber" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dblNumber AS DOUBLE _                         ' %VT_R8 <DOUBLE> [in]
  , BYVAL bstrFormat AS STRING _                        ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXTLRuntime_formatDate LIB "TB_XML60.DLL" ALIAS "IXTLRuntime_formatDate" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varDate AS VARIANT _                          ' %VT_VARIANT <VARIANT> [in]
  , BYVAL bstrFormat AS STRING _                        ' <ANSI STRING> [in]
  , OPTIONAL BYVAL varDestLocale AS VARIANT _           ' %VT_VARIANT <VARIANT> [opt] [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXTLRuntime_formatTime LIB "TB_XML60.DLL" ALIAS "IXTLRuntime_formatTime" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varTime AS VARIANT _                          ' %VT_VARIANT <VARIANT> [in]
  , BYVAL bstrFormat AS STRING _                        ' <ANSI STRING> [in]
  , OPTIONAL BYVAL varDestLocale AS VARIANT _           ' %VT_VARIANT <VARIANT> [opt] [in]
    ) AS STRING
' ****************************************************************************************


' ########################################################################################
'                             XML DOM Core Objects/Interfaces
' ########################################################################################


' ########################################################################################
' Interface name = IXMLDOMDocument
' IID = {2933BF81-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMNode
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_doctype LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_doctype" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocumentType <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_implementation LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_implementation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMImplementation <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_documentElement LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_documentElement" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMElement <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_putref_documentElement LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_putref_documentElement" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL DOMElement AS DWORD _                         ' *IXMLDOMElement <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_createElement LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createElement" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL tagName AS STRING _                           ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMElement <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_createDocumentFragment LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createDocumentFragment" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocumentFragment <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_createTextNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createTextNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMText <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_createComment LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createComment" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMComment <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_createCDATASection LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createCDATASection" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMCDATASection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_createProcessingInstruction LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createProcessingInstruction" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstr_target AS STRING _                      ' <ANSI STRING> [in]
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMProcessingInstruction <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_createAttribute LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createAttribute" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMAttribute <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_createEntityReference LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createEntityReference" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMEntityReference <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_getElementsByTagName LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_getElementsByTagName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL tagName AS STRING _                           ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_createNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL vtype AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_nodeFromID LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_nodeFromID" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL idString AS STRING _                          ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_load LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_load" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL xmlSource AS VARIANT _                        ' %VT_VARIANT <VARIANT> [in]
    ) AS INTEGER                                        ' *%VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_readyState LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_readyState" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_parseError LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_parseError" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMParseError <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_url LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_url" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_async LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_async" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' *%VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_put_async LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_async" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL isAsync AS INTEGER _                          ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_abort LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_abort" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_loadXML LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_loadXML" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrXML AS STRING _                           ' <ANSI STRING> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_save LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_save" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL destination AS VARIANT _                      ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_validateOnParse LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_validateOnParse" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_put_validateOnParse LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_validateOnParse" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL isValidating AS INTEGER _                     ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_resolveExternals LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_resolveExternals" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_put_resolveExternals LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_resolveExternals" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL isResolving AS INTEGER _                      ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument_get_preserveWhiteSpace LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_preserveWhiteSpace" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' *%VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_put_preserveWhiteSpace LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_preserveWhiteSpace" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL isPreserving AS INTEGER _                     ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_put_onreadystatechange LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_onreadystatechange" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varonreadystatechange AS VARIANT _            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_put_ondataavailable LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_ondataavailable" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varondataavailable AS VARIANT _               ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument_put_ontransformnode LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_ontransformnode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varontransformnode AS VARIANT _               ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMDocument2
' IID = {2933BF95-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMDocument
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument2 <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_doctype LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_doctype" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocumentType <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_implementation LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_implementation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMImplementation <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_documentElement LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_documentElement" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMElement <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_putref_documentElement LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_putref_documentElement" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL DOMElement AS DWORD _                         ' *IXMLDOMElement <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_createElement LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createElement" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL tagName AS STRING _                           ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMElement <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_createDocumentFragment LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createDocumentFragment" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument2Fragment <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_createTextNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createTextNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMText <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_createComment LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createComment" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMComment <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_createCDATASection LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createCDATASection" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMCDATASection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_createProcessingInstruction LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createProcessingInstruction" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstr_target AS STRING _                      ' <ANSI STRING> [in]
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMProcessingInstruction <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_createAttribute LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createAttribute" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMAttribute <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_createEntityReference LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createEntityReference" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMEntityReference <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_getElementsByTagName LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_getElementsByTagName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL tagName AS STRING _                           ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_createNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL vtype AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_nodeFromID LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_nodeFromID" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL idString AS STRING _                          ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_load LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_load" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL xmlSource AS VARIANT _                        ' %VT_VARIANT <VARIANT> [in]
    ) AS INTEGER                                        ' *%VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_readyState LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_readyState" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_parseError LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_parseError" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMParseError <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_url LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_url" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_async LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_async" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' *%VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_put_async LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_async" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL isAsync AS INTEGER _                          ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_abort LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_abort" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_loadXML LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_loadXML" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrXML AS STRING _                           ' <ANSI STRING> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_save LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_save" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL destination AS VARIANT _                      ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_validateOnParse LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_validateOnParse" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_put_validateOnParse LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_validateOnParse" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL isValidating AS INTEGER _                     ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_resolveExternals LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_resolveExternals" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_put_resolveExternals LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_resolveExternals" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL isResolving AS INTEGER _                      ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_preserveWhiteSpace LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_preserveWhiteSpace" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' *%VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_put_preserveWhiteSpace LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_preserveWhiteSpace" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL isPreserving AS INTEGER _                     ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_put_onreadystatechange LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_onreadystatechange" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varonreadystatechange AS VARIANT _            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_put_ondataavailable LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_ondataavailable" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varondataavailable AS VARIANT _               ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_put_ontransformnode LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_ontransformnode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varontransformnode AS VARIANT _               ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_get_namespaces LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument2_get_namespaces" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMSchemaCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_get_schemas LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument2_get_schemas" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF otherCollection AS VARIANT _                  ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_putref_schemas LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument2_putref_schemas" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL otherCollection AS VARIANT _                  ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument2_validate LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument2_validate" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMParseError <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_setProperty LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument2_setProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument2_getProperty LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument2_getProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMDocument3
' IID = {2933BF96-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMDocument2
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument3 <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_doctype LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_doctype" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocumentType <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_implementation LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_implementation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMImplementation <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_documentElement LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_documentElement" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMElement <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_putref_documentElement LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_putref_documentElement" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL DOMElement AS DWORD _                         ' *IXMLDOMElement <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_createElement LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createElement" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL tagName AS STRING _                           ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMElement <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_createDocumentFragment LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createDocumentFragment" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument3Fragment <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_createTextNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createTextNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMText <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_createComment LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createComment" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMComment <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_createCDATASection LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createCDATASection" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMCDATASection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_createProcessingInstruction LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createProcessingInstruction" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstr_target AS STRING _                      ' <ANSI STRING> [in]
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMProcessingInstruction <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_createAttribute LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createAttribute" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMAttribute <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_createEntityReference LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createEntityReference" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMEntityReference <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_getElementsByTagName LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_getElementsByTagName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL tagName AS STRING _                           ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_createNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_createNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL vtype AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_nodeFromID LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_nodeFromID" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL idString AS STRING _                          ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_load LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_load" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL xmlSource AS VARIANT _                        ' %VT_VARIANT <VARIANT> [in]
    ) AS INTEGER                                        ' *%VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_readyState LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_readyState" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_parseError LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_parseError" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMParseError <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_url LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_url" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_async LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_async" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' *%VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_put_async LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_async" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL isAsync AS INTEGER _                          ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_abort LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_abort" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_loadXML LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_loadXML" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL bstrXML AS STRING _                           ' <ANSI STRING> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_save LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_save" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL destination AS VARIANT _                      ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_validateOnParse LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_validateOnParse" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_put_validateOnParse LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_validateOnParse" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL isValidating AS INTEGER _                     ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_resolveExternals LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_resolveExternals" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_put_resolveExternals LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_resolveExternals" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL isResolving AS INTEGER _                      ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_preserveWhiteSpace LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_get_preserveWhiteSpace" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' *%VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_put_preserveWhiteSpace LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_preserveWhiteSpace" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL isPreserving AS INTEGER _                     ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_put_onreadystatechange LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_onreadystatechange" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varonreadystatechange AS VARIANT _            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_put_ondataavailable LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_ondataavailable" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varondataavailable AS VARIANT _               ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_put_ontransformnode LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument_put_ontransformnode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varontransformnode AS VARIANT _               ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_get_namespaces LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument2_get_namespaces" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMSchemaCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_get_schemas LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument2_get_schemas" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF otherCollection AS VARIANT _                  ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_putref_schemas LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument2_putref_schemas" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL otherCollection AS VARIANT _                  ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_validate LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument2_validate" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMParseError <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_setProperty LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument2_setProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocument3_getProperty LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument2_getProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_validateNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument3_validateNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL node AS DWORD _                               ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMParseError <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocument3_importNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocument3_importNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL node AS DWORD _                               ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMNamedNodeMap
' IID = {2933BF83-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNamedNodeMap_getNamedItem LIB "TB_XML60.DLL" ALIAS "IXMLDOMNamedNodeMap_getNamedItem" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNamedNodeMap_setNamedItem LIB "TB_XML60.DLL" ALIAS "IXMLDOMNamedNodeMap_setNamedItem" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newItem AS DWORD _                            ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNamedNodeMap_removeNamedItem LIB "TB_XML60.DLL" ALIAS "IXMLDOMNamedNodeMap_removeNamedItem" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNamedNodeMap_get_item LIB "TB_XML60.DLL" ALIAS "IXMLDOMNamedNodeMap_get_item" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL index AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNamedNodeMap_get_length LIB "TB_XML60.DLL" ALIAS "IXMLDOMNamedNodeMap_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNamedNodeMap_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "IXMLDOMNamedNodeMap_getQualifiedItem" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL baseName AS STRING _                          ' <ANSI STRING> [in]
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNamedNodeMap_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "IXMLDOMNamedNodeMap_removeQualifiedItem" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL baseName AS STRING _                          ' <ANSI STRING> [in]
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNamedNodeMap_nextNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNamedNodeMap_nextNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMNamedNodeMap_reset LIB "TB_XML60.DLL" ALIAS "IXMLDOMNamedNodeMap_reset" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNamedNodeMap_get_newEnum LIB "TB_XML60.DLL" ALIAS "IXMLDOMNamedNodeMap_get_newEnum" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' *%VT_UNKNOWN <IUNKNOWN> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMNode
' IID = {2933BF80-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMNode_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMNode_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMNode_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMNode_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMNode_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMNode_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMNode_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNode_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMNode_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMNodeList
' IID = {2933BF82-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNodeList_get_item LIB "TB_XML60.DLL" ALIAS "IXMLDOMNodeList_get_item" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL index AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNodeList_get_length LIB "TB_XML60.DLL" ALIAS "IXMLDOMNodeList_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNodeList_nextNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNodeList_nextNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMNodeList_reset LIB "TB_XML60.DLL" ALIAS "IXMLDOMNodeList_reset" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNodeList_get_newEnum LIB "TB_XML60.DLL" ALIAS "IXMLDOMNodeList_get_newEnum" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' *%VT_UNKNOWN <IUNKNOWN> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMParseError
' IID = {3EFAA426-272F-11D2-836F-0000F87A7782}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError_get_errorCode LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_errorCode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError_get_url LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_url" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError_get_reason LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_reason" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError_get_srcText LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_srcText" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError_get_line LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_line" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError_get_linepos LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_linepos" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError_get_filepos LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_filepos" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMParseError2
' IID = {3EFAA428-272F-11D2-836F-0000F87A7782}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMParseError
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError2_get_errorCode LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_errorCode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError2_get_url LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_url" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError2_get_reason LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_reason" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError2_get_srcText LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_srcText" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError2_get_line LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_line" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError2_get_linepos LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_linepos" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError2_get_filepos LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError_get_filepos" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError2_get_errorXPath LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError2_get_errorXPath" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError2_get_allErrors LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError2_get_allErrors" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMParseErrorCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError2_errorParameters LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError2_errorParameters" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL index AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseError2_get_errorParametersCount LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseError2_get_errorParametersCount" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMParseErrorCollection
' IID = {3EFAA429-272F-11D2-836F-0000F87A7782}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseErrorCollection_get_item LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseErrorCollection_get_item" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL index AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS DWORD                                          ' **IXMLDOMParseError2 <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseErrorCollection_get_length LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseErrorCollection_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseErrorCollection_get_next LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseErrorCollection_get_next" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMParseError2 <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMParseErrorCollection_reset LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseErrorCollection_reset" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMParseErrorCollection_get_newEnum LIB "TB_XML60.DLL" ALIAS "IXMLDOMParseErrorCollection_get_newEnum" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' *%VT_UNKNOWN <IUNKNOWN> [out]
' ****************************************************************************************



' ########################################################################################
'                         XML DOM Implemented Objects/Interfaces
' ########################################################################################


' ########################################################################################
' Interface name = IXMLDOMAttribute
' IID = {2933BF85-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMNode
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMAttribute_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMAttribute_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMAttribute_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMAttribute_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMAttribute_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMAttribute_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMAttribute_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMAttribute_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMAttribute_get_name LIB "TB_XML60.DLL" ALIAS "IXMLDOMAttribute_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMAttribute_get_value LIB "TB_XML60.DLL" ALIAS "IXMLDOMAttribute_get_value" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF attributeValue AS VARIANT _                   ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMAttribute_put_value LIB "TB_XML60.DLL" ALIAS "IXMLDOMAttribute_put_value" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL attributeValue AS VARIANT _                   ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMCDATASection
' IID = {2933BF8A-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMText
' Note: It has the same methods that the IXMLDOMText interface.
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_data LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_get_data" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_put_data LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_put_data" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_get_length LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_substringData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_substringData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL count AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_appendData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_appendData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_insertData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_insertData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_deleteData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_deleteData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL count AS LONG _                               ' %VT_I4 <LONG> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCDATASection_replaceData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_replaceData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL count AS LONG _                               ' %VT_I4 <LONG> [in]
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCDATASection_splitText LIB "TB_XML60.DLL" ALIAS "IXMLDOMText_splitText" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
    ) AS DWORD                                          ' **IXMLDOMText <dispinterface> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMCharacterData
' IID = {2933BF84-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMNode
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_data LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_get_data" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_put_data LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_put_data" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_get_length LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMCharacterData_substringData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_substringData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL count AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_appendData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_appendData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_insertData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_insertData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_deleteData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_deleteData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL count AS LONG _                               ' %VT_I4 <LONG> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMCharacterData_replaceData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_replaceData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL count AS LONG _                               ' %VT_I4 <LONG> [in]
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMComment
' IID = {2933BF88-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMCharacterData
' Note: It has the same methods that the IXMLDOMCharacterData interface.
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_data LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_get_data" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_put_data LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_put_data" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_get_length LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMComment_substringData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_substringData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL count AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_appendData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_appendData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_insertData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_insertData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_deleteData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_deleteData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL count AS LONG _                               ' %VT_I4 <LONG> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMComment_replaceData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_replaceData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL count AS LONG _                               ' %VT_I4 <LONG> [in]
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMDocumentFragment
' IID = {3EFAA413-272F-11D2-836F-0000F87A7782}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMNode
' Note: It has the same methods that the IXMLDOMNode interface.
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentFragment_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentFragment_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentFragment_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentFragment_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentFragment_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentFragment_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentFragment_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentFragment_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentFragment_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMDocumentType
' IID = {2933BF8B-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMNode
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentType_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentType_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentType_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentType_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentType_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentType_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentType_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMDocumentType_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_name LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocumentType_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_entities LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocumentType_get_entities" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMDocumentType_get_notations LIB "TB_XML60.DLL" ALIAS "IXMLDOMDocumentType_get_notations" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMElement
' IID = {2933BF86-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMNode
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMElement_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMElement_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMElement_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMElement_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMElement_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMElement_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMElement_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMElement_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_get_tagName LIB "TB_XML60.DLL" ALIAS "IXMLDOMElement_get_tagName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING                                         ' <ANSI STRING> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMElement_getAttribute LIB "TB_XML60.DLL" ALIAS "IXMLDOMElement_getAttribute" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMElement_setAttribute LIB "TB_XML60.DLL" ALIAS "IXMLDOMElement_setAttribute" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMElement_removeAttribute LIB "TB_XML60.DLL" ALIAS "IXMLDOMElement_removeAttribute" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_getAttributeNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMElement_getAttributeNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMAttribute <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_setAttributeNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMElement_setAttributeNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL DOMAttribute AS DWORD _                       ' *IXMLDOMAttribute <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMAttribute <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_removeAttributeNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMElement_removeAttributeNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL DOMAttribute AS DWORD _                       ' *IXMLDOMAttribute <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMAttribute <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMElement_getElementsByTagName LIB "TB_XML60.DLL" ALIAS "IXMLDOMElement_getElementsByTagName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL tagName AS STRING _                           ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMElement_normalize LIB "TB_XML60.DLL" ALIAS "IXMLDOMElement_normalize" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMEntity
' IID = {2933BF8D-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMNode
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMEntity_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMEntity_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMEntity_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMEntity_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMEntity_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMEntity_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMEntity_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMEntity_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMEntity_get_publicId LIB "TB_XML60.DLL" ALIAS "IXMLDOMEntity_get_publicId" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF publicId AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMEntity_get_systemId LIB "TB_XML60.DLL" ALIAS "IXMLDOMEntity_get_systemId" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF systemId AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntity_get_notationName LIB "TB_XML60.DLL" ALIAS "IXMLDOMEntity_get_notationName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMEntityReference
' IID = {2933BF8E-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMNode
' Note; It has the same methods that the IXMLDOMNode interface.
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMEntityReference_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMEntityReference_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMEntityReference_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMEntityReference_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMEntityReference_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMEntityReference_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMEntityReference_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMEntityReference_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMEntityReference_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMImplementation
' IID = {2933BF8F-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMImplementation_hasFeature LIB "TB_XML60.DLL" ALIAS "IXMLDOMImplementation_hasFeature" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL feature AS STRING _                           ' <ANSI STRING> [in]
  , BYVAL version AS STRING _                           ' <ANSI STRING> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMNotation
' IID = {2933BF8C-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMNode
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMNotation_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMNotation_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMNotation_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMNotation_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMNotation_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMNotation_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMNotation_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMNotation_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMNotation_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMNotation_get_publicId LIB "TB_XML60.DLL" ALIAS "IXMLDOMNotation_get_publicId" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF publicId AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMNotation_get_systemId LIB "TB_XML60.DLL" ALIAS "IXMLDOMNotation_get_systemId" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF systemId AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMProcessingInstruction
' IID = {2933BF89-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMNode
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMProcessingInstruction_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMProcessingInstruction_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMProcessingInstruction_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMProcessingInstruction_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMProcessingInstruction_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMProcessingInstruction_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMProcessingInstruction_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMProcessingInstruction_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_target LIB "TB_XML60.DLL" ALIAS "IXMLDOMProcessingInstruction_get_target" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMProcessingInstruction_get_data LIB "TB_XML60.DLL" ALIAS "IXMLDOMProcessingInstruction_get_data" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMProcessingInstruction_put_data LIB "TB_XML60.DLL" ALIAS "IXMLDOMProcessingInstruction_put_data" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS STRING _                             ' <ANSI STRING> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMSchemaCollection
' IID = {373984C8-B845-449B-91E7-45AC83036ADE}
' XML Schemas Collection
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE SUB IXMLDOMSchemaCollection_add LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_add" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
  , BYVAL var AS VARIANT _                              ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSchemaCollection_get LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_get" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMSchemaCollection_remove LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_remove" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSchemaCollection_get_length LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSchemaCollection_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL index AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMSchemaCollection_addCollection LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_addCollection" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL otherCollection AS DWORD _                    ' *IXMLDOMSchemaCollection <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSchemaCollection_get_newEnum LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_get_newEnum" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' *%VT_UNKNOWN <IUNKNOWN> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMSchemaCollection2
' IID = {50EA08B0-DD1B-4664-9A50-C2F40F4BD79A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMSchemaCollection
' ########################################################################################

' ****************************************************************************************
DECLARE SUB IXMLDOMSchemaCollection2_add LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_add" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
  , BYVAL var AS VARIANT _                              ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSchemaCollection2_get LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_get" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMSchemaCollection2_remove LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_remove" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSchemaCollection2_get_length LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSchemaCollection2_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL index AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMSchemaCollection2_addCollection LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_addCollection" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL otherCollection AS DWORD _                    ' *IXMLDOMSchemaCollection <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSchemaCollection2_get_newEnum LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection_get_newEnum" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' *%VT_UNKNOWN <IUNKNOWN> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMSchemaCollection2_validate LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection2_validate" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMSchemaCollection2_put_validateOnLoad LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection2_put_validateOnLoad" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL validateOnLoad AS INTEGER _                   ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSchemaCollection2_get_validateOnLoad LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection2_get_validateOnLoad" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSchemaCollection2_getSchema LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection2_getSchema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSchemaCollection2_getDeclaration LIB "TB_XML60.DLL" ALIAS "IXMLDOMSchemaCollection2_getDeclaration" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL node AS DWORD _                               ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **ISchemaItem <dispinterface> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMSelection
' IID = {AA634FC7-5888-44A7-A257-3A47150D3A0E}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMNodeList
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSelection_get_item LIB "TB_XML60.DLL" ALIAS "IXMLDOMNodeList_get_item" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL index AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSelection_get_length LIB "TB_XML60.DLL" ALIAS "IXMLDOMNodeList_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSelection_nextNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNodeList_nextNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMSelection_reset LIB "TB_XML60.DLL" ALIAS "IXMLDOMNodeList_reset" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSelection_get_newEnum LIB "TB_XML60.DLL" ALIAS "IXMLDOMNodeList_get_newEnum" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' *%VT_UNKNOWN <IUNKNOWN> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSelection_get_expr LIB "TB_XML60.DLL" ALIAS "IXMLDOMSelection_get_expr" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING                                         ' <ANSI STRING> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMSelection_put_expr LIB "TB_XML60.DLL" ALIAS "IXMLDOMSelection_put_expr" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL expression AS STRING _                        ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSelection_get_context LIB "TB_XML60.DLL" ALIAS "IXMLDOMSelection_get_context" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMSelection_putref_context LIB "TB_XML60.DLL" ALIAS "IXMLDOMSelection_putref_context" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL ppNode AS DWORD _                             ' *IXMLDOMNode <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSelection_peekNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMSelection_peekNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSelection_matches LIB "TB_XML60.DLL" ALIAS "IXMLDOMSelection_matches" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pNode AS DWORD _                              ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSelection_removeNext LIB "TB_XML60.DLL" ALIAS "IXMLDOMSelection_removeNext" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMSelection_removeAll LIB "TB_XML60.DLL" ALIAS "IXMLDOMSelection_removeAll" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMSelection_clone LIB "TB_XML60.DLL" ALIAS "IXMLDOMSelection_clone" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMSelection <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMSelection_getProperty LIB "TB_XML60.DLL" ALIAS "IXMLDOMSelection_getProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMSelection_setProperty LIB "TB_XML60.DLL" ALIAS "IXMLDOMSelection_setProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IXMLDOMText
' IID = {2933BF87-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMCharacterData
' ########################################################################################

' ****************************************************************************************
' Interface name = IXMLDOMText
' IID = {2933BF87-7B36-11D2-B20E-00C04F983E60}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IXMLDOMCharacterData
' ****************************************************************************************

' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_nodeName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMText_get_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF value AS VARIANT _                            ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMText_put_nodeValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL value AS VARIANT _                            ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_nodeType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *DOMNodeType <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_parentNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parentNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_childNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_childNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_firstChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_firstChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_lastChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_lastChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_previousSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_previousSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_nextSibling LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nextSibling" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_attributes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNamedNodeMap <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_insertBefore LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_insertBefore" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL refChild AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_replaceChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_replaceChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL oldChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_removeChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_removeChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL childNode AS DWORD _                          ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_appendChild LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_appendChild" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL newChild AS DWORD _                           ' *IXMLDOMNode <dispinterface> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_hasChildNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_hasChildNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_ownerDocument LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_ownerDocument" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMDocument <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_cloneNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_cloneNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL deep AS INTEGER _                             ' %VT_BOOL <INTEGER> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_nodeTypeString LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypeString" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMText_put_text LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_text" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrtext AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_specified LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_specified" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_definition LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_definition" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IXMLDOMText_get_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF typedValue AS VARIANT _                       ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMText_put_nodeTypedValue LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_nodeTypedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL typedValue AS VARIANT _                       ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMText_get_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF dataTypeName AS VARIANT _                     ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMText_put_dataType LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_put_dataType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL dataTypeName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_xml LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_xml" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_transformNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_selectNodes LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectNodes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNodeList <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_selectSingleNode LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_selectSingleNode" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL queryString AS STRING _                       ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **IXMLDOMNode <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_parsed LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_parsed" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER>
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_prefix LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_prefix" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_baseName LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_get_baseName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMText_transformNodeToObject LIB "TB_XML60.DLL" ALIAS "IXMLDOMNode_transformNodeToObject" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL stylesheet AS DWORD _                         ' *IXMLDOMNode <dispinterface> [in]
  , BYVAL outputObject AS VARIANT _                     ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_data LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_get_data" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMText_put_data LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_put_data" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_get_length LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_substringData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_substringData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL count AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IXMLDOMText_appendData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_appendData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMText_insertData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_insertData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMText_deleteData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_deleteData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL count AS LONG _                               ' %VT_I4 <LONG> [in]
    )
' ****************************************************************************************
DECLARE SUB IXMLDOMText_replaceData LIB "TB_XML60.DLL" ALIAS "IXMLDOMCharacterData_replaceData" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
  , BYVAL count AS LONG _                               ' %VT_I4 <LONG> [in]
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IXMLDOMText_splitText LIB "TB_XML60.DLL" ALIAS "IXMLDOMText_splitText" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL offset AS LONG _                              ' %VT_I4 <LONG> [in]
    ) AS DWORD                                          ' **IXMLDOMText <dispinterface> [out]
' ****************************************************************************************



' ########################################################################################
'                              Schema Object Model (SOM)
' ########################################################################################


' ########################################################################################
' Interface name = ISchema
' IID = {50EA08B4-DD1B-4664-9A50-C2F40F4BD79A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISchemaItem
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchema_get_name LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_schema LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_schema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_id LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_id" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_itemType LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_itemType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SOMITEMTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_unhandledAttributes LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_unhandledAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXAttributes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchema_writeAnnotation LIB "TB_XML60.DLL" ALIAS "ISchemaItem_writeAnnotation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL annotationSink AS DWORD _                     ' %VT_UNKNOWN <IUNKNOWN> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_targetNamespace LIB "TB_XML60.DLL" ALIAS "ISchema_get_targetNamespace" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_version LIB "TB_XML60.DLL" ALIAS "ISchema_get_version" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_types LIB "TB_XML60.DLL" ALIAS "ISchema_get_types" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                         ' **ISchemaItemCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_elements LIB "TB_XML60.DLL" ALIAS "ISchema_get_elements" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaItemCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_attributes LIB "TB_XML60.DLL" ALIAS "ISchema_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaItemCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_attributeGroups LIB "TB_XML60.DLL" ALIAS "ISchema_get_attributeGroups" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaItemCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_modelGroups LIB "TB_XML60.DLL" ALIAS "ISchema_get_modelGroups" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaItemCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_notations LIB "TB_XML60.DLL" ALIAS "ISchema_get_notations" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaItemCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchema_get_schemaLocations LIB "TB_XML60.DLL" ALIAS "ISchema_get_schemaLocations" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaStringCollection <dispinterface> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaAny
' IID = {50EA08BC-DD1B-4664-9A50-C2F40F4BD79A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISchemaParticle
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaAny_get_name LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaAny_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaAny_get_schema LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_schema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAny_get_id LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_id" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaAny_get_itemType LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_itemType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SOMITEMTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAny_get_unhandledAttributes LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_unhandledAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXAttributes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAny_writeAnnotation LIB "TB_XML60.DLL" ALIAS "ISchemaItem_writeAnnotation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL annotationSink AS DWORD _                     ' %VT_UNKNOWN <IUNKNOWN> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB ISchemaAny_get_minOccurs LIB "TB_XML60.DLL" ALIAS "ISchemaParticle_get_minOccurs" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF minOccurs AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISchemaAny_get_maxOccurs LIB "TB_XML60.DLL" ALIAS "ISchemaParticle_get_maxOccurs" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF maxOccurs AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION ISchemaAny_get_namespaces LIB "TB_XML60.DLL" ALIAS "ISchemaAny_get_namespaces" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaStringCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAny_get_processContents LIB "TB_XML60.DLL" ALIAS "ISchemaAny_get_processContents" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMAPROCESSCONTENTS <enum> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaAttribute
' IID = {50EA08B6-DD1B-4664-9A50-C2F40F4BD79A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISchemaItem
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_get_name LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_get_schema LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_schema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_get_id LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_id" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_get_itemType LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_itemType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SOMITEMTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_get_unhandledAttributes LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_unhandledAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXAttributes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_writeAnnotation LIB "TB_XML60.DLL" ALIAS "ISchemaItem_writeAnnotation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL annotationSink AS DWORD _                     ' %VT_UNKNOWN <IUNKNOWN> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_get_type LIB "TB_XML60.DLL" ALIAS "ISchemaAttribute_get_type" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaType <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_get_scope LIB "TB_XML60.DLL" ALIAS "ISchemaAttribute_get_scope" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaComplexType <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_get_defaultValue LIB "TB_XML60.DLL" ALIAS "ISchemaAttribute_get_defaultValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_get_fixedValue LIB "TB_XML60.DLL" ALIAS "ISchemaAttribute_get_fixedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_get_use LIB "TB_XML60.DLL" ALIAS "ISchemaAttribute_get_use" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMAUSE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttribute_get_isReference LIB "TB_XML60.DLL" ALIAS "ISchemaAttribute_get_isReference" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaAttributeGroup
' IID = {50EA08BA-DD1B-4664-9A50-C2F40F4BD79A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISchemaItem
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaAttributeGroup_get_name LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttributeGroup_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttributeGroup_get_schema LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_schema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttributeGroup_get_id LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_id" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttributeGroup_get_itemType LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_itemType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SOMITEMTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttributeGroup_get_unhandledAttributes LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_unhandledAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXAttributes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttributeGroup_writeAnnotation LIB "TB_XML60.DLL" ALIAS "ISchemaItem_writeAnnotation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL annotationSink AS DWORD _                     ' %VT_UNKNOWN <IUNKNOWN> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttributeGroup_get_anyAttribute LIB "TB_XML60.DLL" ALIAS "ISchemaAttributeGroup_get_anyAttribute" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaAny <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaAttributeGroup_get_attributes LIB "TB_XML60.DLL" ALIAS "ISchemaAttributeGroup_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaItemCollection <dispinterface> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaComplexType
' IID = {50EA08B9-DD1B-4664-9A50-C2F40F4BD79A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISchemaType
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_name LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_schema LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_schema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_id LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_id" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_itemType LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_itemType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SOMITEMTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_unhandledAttributes LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_unhandledAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXAttributes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_writeAnnotation LIB "TB_XML60.DLL" ALIAS "ISchemaItem_writeAnnotation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL annotationSink AS DWORD _                     ' %VT_UNKNOWN <IUNKNOWN> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_baseTypes LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_baseTypes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaItemCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_final LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_final" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMADERIVATIONMETHOD <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_variety LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_variety" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMATYPEVARIETY <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_derivedBy LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_derivedBy" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMADERIVATIONMETHOD <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_isValid LIB "TB_XML60.DLL" ALIAS "ISchemaType_isValid" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_minExclusive LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_minExclusive" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_minInclusive LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_minInclusive" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_maxExclusive LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_maxExclusive" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_maxInclusive LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_maxInclusive" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB ISchemaComplexType_get_totalDigits LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_totalDigits" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF totalDigits AS VARIANT _                      ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISchemaComplexType_get_fractionDigits LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_fractionDigits" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF fractionDigits AS VARIANT _                   ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISchemaComplexType_get_length LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF length AS VARIANT _                           ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISchemaComplexType_get_minLength LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_minLength" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF minLength AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISchemaComplexType_get_maxLength LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_maxLength" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF maxLength AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_enumeration LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_enumeration" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaStringCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_whitespace LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_whitespace" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMAWHITESPACE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_patterns LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_patterns" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaStringCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_isAbstract LIB "TB_XML60.DLL" ALIAS "ISchemaComplexType_get_isAbstract" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_anyAttribute LIB "TB_XML60.DLL" ALIAS "ISchemaComplexType_get_anyAttribute" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaAny <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_attributes LIB "TB_XML60.DLL" ALIAS "ISchemaComplexType_get_attributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaItemCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_contentType LIB "TB_XML60.DLL" ALIAS "ISchemaComplexType_get_contentType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMACONTENTTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_contentModel LIB "TB_XML60.DLL" ALIAS "ISchemaComplexType_get_contentModel" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaModelGroup <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaComplexType_get_prohibitedSubstitutions LIB "TB_XML60.DLL" ALIAS "ISchemaComplexType_get_prohibitedSubstitutions" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMADERIVATIONMETHOD <enum> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaElement
' IID = {50EA08B7-DD1B-4664-9A50-C2F40F4BD79A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISchemaParticle
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_name LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_schema LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_schema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_id LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_id" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_itemType LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_itemType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SOMITEMTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_unhandledAttributes LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_unhandledAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXAttributes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_writeAnnotation LIB "TB_XML60.DLL" ALIAS "ISchemaItem_writeAnnotation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL annotationSink AS DWORD _                     ' %VT_UNKNOWN <IUNKNOWN> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB ISchemaElement_get_minOccurs LIB "TB_XML60.DLL" ALIAS "ISchemaParticle_get_minOccurs" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF minOccurs AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISchemaElement_get_maxOccurs LIB "TB_XML60.DLL" ALIAS "ISchemaParticle_get_maxOccurs" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF maxOccurs AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_type LIB "TB_XML60.DLL" ALIAS "ISchemaElement_get_type" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaType <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_scope LIB "TB_XML60.DLL" ALIAS "ISchemaElement_get_scope" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaComplexType <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_defaultValue LIB "TB_XML60.DLL" ALIAS "ISchemaElement_get_defaultValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_fixedValue LIB "TB_XML60.DLL" ALIAS "ISchemaElement_get_fixedValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_isNillable LIB "TB_XML60.DLL" ALIAS "ISchemaElement_get_isNillable" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_identityConstraints LIB "TB_XML60.DLL" ALIAS "ISchemaElement_get_identityConstraints" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaItemCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_substitutionGroup LIB "TB_XML60.DLL" ALIAS "ISchemaElement_get_substitutionGroup" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaElement <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_substitutionGroupExclusions LIB "TB_XML60.DLL" ALIAS "ISchemaElement_get_substitutionGroupExclusions" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMADERIVATIONMETHOD <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_disallowedSubstitutions LIB "TB_XML60.DLL" ALIAS "ISchemaElement_get_disallowedSubstitutions" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMADERIVATIONMETHOD <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_isAbstract LIB "TB_XML60.DLL" ALIAS "ISchemaElement_get_isAbstract" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaElement_get_isReference LIB "TB_XML60.DLL" ALIAS "ISchemaElement_get_isReference" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaIdentityConstraint
' IID = {50EA08BD-DD1B-4664-9A50-C2F40F4BD79A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISchemaItem
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaIdentityConstraint_get_name LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaIdentityConstraint_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaIdentityConstraint_get_schema LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_schema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaIdentityConstraint_get_id LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_id" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaIdentityConstraint_get_itemType LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_itemType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SOMITEMTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaIdentityConstraint_get_unhandledAttributes LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_unhandledAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXAttributes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaIdentityConstraint_writeAnnotation LIB "TB_XML60.DLL" ALIAS "ISchemaItem_writeAnnotation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL annotationSink AS DWORD _                     ' %VT_UNKNOWN <IUNKNOWN> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaIdentityConstraint_get_selector LIB "TB_XML60.DLL" ALIAS "ISchemaIdentityConstraint_get_selector" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaIdentityConstraint_get_fields LIB "TB_XML60.DLL" ALIAS "ISchemaIdentityConstraint_get_fields" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaStringCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaIdentityConstraint_get_referencedKey LIB "TB_XML60.DLL" ALIAS "ISchemaIdentityConstraint_get_referencedKey" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaIdentityConstraint <dispinterface> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaItem
' IID = {50EA08B3-DD1B-4664-9A50-C2F40F4BD79A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaItem_get_name LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaItem_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaItem_get_schema LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_schema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaItem_get_id LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_id" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaItem_get_itemType LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_itemType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SOMITEMTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaItem_get_unhandledAttributes LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_unhandledAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXAttributes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaItem_writeAnnotation LIB "TB_XML60.DLL" ALIAS "ISchemaItem_writeAnnotation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL annotationSink AS DWORD _                     ' %VT_UNKNOWN <IUNKNOWN> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaItemCollection
' IID = {50EA08B2-DD1B-4664-9A50-C2F40F4BD79A}
' XML Schema Item Collection
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaItemCollection_get_item LIB "TB_XML60.DLL" ALIAS "ISchemaItemCollection_get_item" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL index AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS DWORD                                          ' **ISchemaItem <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaItemCollection_itemByName LIB "TB_XML60.DLL" ALIAS "ISchemaItemCollection_itemByName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **ISchemaItem <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaItemCollection_itemByQName LIB "TB_XML60.DLL" ALIAS "ISchemaItemCollection_itemByQName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrname AS STRING _                         ' <ANSI STRING> [in]
  , BYVAL namespaceURI AS STRING _                      ' <ANSI STRING> [in]
    ) AS DWORD                                          ' **ISchemaItem <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaItemCollection_get_length LIB "TB_XML60.DLL" ALIAS "ISchemaItemCollection_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION ISchemaItemCollection_get_newEnum LIB "TB_XML60.DLL" ALIAS "ISchemaItemCollection_get_newEnum" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' *%VT_UNKNOWN <IUNKNOWN> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaModelGroup
' IID = {50EA08BB-DD1B-4664-9A50-C2F40F4BD79A}
' XML Schema Type
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISchemaParticle
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaModelGroup_get_name LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaModelGroup_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaModelGroup_get_schema LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_schema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaModelGroup_get_id LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_id" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaModelGroup_get_itemType LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_itemType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SOMITEMTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaModelGroup_get_unhandledAttributes LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_unhandledAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXAttributes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaModelGroup_writeAnnotation LIB "TB_XML60.DLL" ALIAS "ISchemaItem_writeAnnotation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL annotationSink AS DWORD _                     ' %VT_UNKNOWN <IUNKNOWN> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB ISchemaModelGroup_get_minOccurs LIB "TB_XML60.DLL" ALIAS "ISchemaParticle_get_minOccurs" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF minOccurs AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISchemaModelGroup_get_maxOccurs LIB "TB_XML60.DLL" ALIAS "ISchemaParticle_get_maxOccurs" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF maxOccurs AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION ISchemaModelGroup_get_particles LIB "TB_XML60.DLL" ALIAS "ISchemaModelGroup_get_particles" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaItemCollection <dispinterface> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaNotation
' IID = {50EA08BE-DD1B-4664-9A50-C2F40F4BD79A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISchemaItem
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaNotation_get_name LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaNotation_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaNotation_get_schema LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_schema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaNotation_get_id LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_id" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaNotation_get_itemType LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_itemType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SOMITEMTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaNotation_get_unhandledAttributes LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_unhandledAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXAttributes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaNotation_writeAnnotation LIB "TB_XML60.DLL" ALIAS "ISchemaItem_writeAnnotation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL annotationSink AS DWORD _                     ' %VT_UNKNOWN <IUNKNOWN> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaNotation_get_systemIdentifier LIB "TB_XML60.DLL" ALIAS "ISchemaNotation_get_systemIdentifier" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaNotation_get_publicIdentifier LIB "TB_XML60.DLL" ALIAS "ISchemaNotation_get_publicIdentifier" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaParticle
' IID = {50EA08B5-DD1B-4664-9A50-C2F40F4BD79A}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISchemaItem
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaParticle_get_name LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaParticle_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaParticle_get_schema LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_schema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaParticle_get_id LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_id" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaParticle_get_itemType LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_itemType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SOMITEMTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaParticle_get_unhandledAttributes LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_unhandledAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXAttributes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaParticle_writeAnnotation LIB "TB_XML60.DLL" ALIAS "ISchemaItem_writeAnnotation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL annotationSink AS DWORD _                     ' %VT_UNKNOWN <IUNKNOWN> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB ISchemaParticle_get_minOccurs LIB "TB_XML60.DLL" ALIAS "ISchemaParticle_get_minOccurs" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF minOccurs AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISchemaParticle_get_maxOccurs LIB "TB_XML60.DLL" ALIAS "ISchemaParticle_get_maxOccurs" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF maxOccurs AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaStringCollection
' IID = {50EA08B1-DD1B-4664-9A50-C2F40F4BD79A}
' XML Schema String Collection
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaStringCollection_get_item LIB "TB_XML60.DLL" ALIAS "ISchemaStringCollection_get_item" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL index AS LONG _                               ' %VT_I4 <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaStringCollection_get_length LIB "TB_XML60.DLL" ALIAS "ISchemaStringCollection_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION ISchemaStringCollection_get_newEnum LIB "TB_XML60.DLL" ALIAS "ISchemaStringCollection_get_newEnum" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' *%VT_UNKNOWN <IUNKNOWN> [out]
' ****************************************************************************************


' ########################################################################################
' Interface name = ISchemaType
' IID = {50EA08B8-DD1B-4664-9A50-C2F40F4BD79A}
' XML Schema Type
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = ISchemaItem
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_name LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_name" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_namespaceURI LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_namespaceURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_schema LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_schema" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchema <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_id LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_id" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_itemType LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_itemType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SOMITEMTYPE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_unhandledAttributes LIB "TB_XML60.DLL" ALIAS "ISchemaItem_get_unhandledAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXAttributes <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_writeAnnotation LIB "TB_XML60.DLL" ALIAS "ISchemaItem_writeAnnotation" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL annotationSink AS DWORD _                     ' %VT_UNKNOWN <IUNKNOWN> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_baseTypes LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_baseTypes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaItemCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_final LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_final" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMADERIVATIONMETHOD <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_variety LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_variety" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMATYPEVARIETY <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_derivedBy LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_derivedBy" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMADERIVATIONMETHOD <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_isValid LIB "TB_XML60.DLL" ALIAS "ISchemaType_isValid" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL pbstrdata AS STRING _                         ' <ANSI STRING> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_minExclusive LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_minExclusive" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_minInclusive LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_minInclusive" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_maxExclusive LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_maxExclusive" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_maxInclusive LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_maxInclusive" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB ISchemaType_get_totalDigits LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_totalDigits" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF totalDigits AS VARIANT _                      ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISchemaType_get_fractionDigits LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_fractionDigits" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF fractionDigits AS VARIANT _                   ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISchemaType_get_length LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF length AS VARIANT _                           ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISchemaType_get_minLength LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_minLength" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF minLength AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISchemaType_get_maxLength LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_maxLength" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF maxLength AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_enumeration LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_enumeration" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaStringCollection <dispinterface> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_whitespace LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_whitespace" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG                                           ' *SCHEMAWHITESPACE <enum> [out]
' ****************************************************************************************
DECLARE FUNCTION ISchemaType_get_patterns LIB "TB_XML60.DLL" ALIAS "ISchemaType_get_patterns" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **ISchemaStringCollection <dispinterface> [out]
' ****************************************************************************************


' ########################################################################################
'                                SAX2 Objects/Interfaces
' ########################################################################################


' ########################################################################################
' Interface name = IMXAttributes
' IID = {F10D27CC-3EC0-415C-8ED8-77AB1C5E7262}
' IMXAttributes interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE SUB IMXAttributes_addAttribute LIB "TB_XML60.DLL" ALIAS "IMXAttributes_addAttribute" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strURI AS STRING _                            ' <ANSI STRING> [in]
  , BYVAL strLocalName AS STRING _                      ' <ANSI STRING> [in]
  , BYVAL strQName AS STRING _                          ' <ANSI STRING> [in]
  , BYVAL strType AS STRING _                           ' <ANSI STRING> [in]
  , BYVAL strValue AS STRING _                          ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXAttributes_addAttributeFromIndex LIB "TB_XML60.DLL" ALIAS "IMXAttributes_addAttributeFromIndex" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varAtts AS VARIANT _                          ' %VT_VARIANT <VARIANT> [in]
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXAttributes_clear LIB "TB_XML60.DLL" ALIAS "IMXAttributes_clear" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************
DECLARE SUB IMXAttributes_removeAttribute LIB "TB_XML60.DLL" ALIAS "IMXAttributes_removeAttribute" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXAttributes_setAttribute LIB "TB_XML60.DLL" ALIAS "IMXAttributes_setAttribute" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
  , BYVAL strURI AS STRING _                            ' <ANSI STRING> [in]
  , BYVAL strLocalName AS STRING _                      ' <ANSI STRING> [in]
  , BYVAL strQName AS STRING _                          ' <ANSI STRING> [in]
  , BYVAL strType AS STRING _                           ' <ANSI STRING> [in]
  , BYVAL strValue AS STRING _                          ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXAttributes_setAttributes LIB "TB_XML60.DLL" ALIAS "IMXAttributes_setAttributes" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varAtts AS VARIANT _                          ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXAttributes_setLocalName LIB "TB_XML60.DLL" ALIAS "IMXAttributes_setLocalName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
  , BYVAL strLocalName AS STRING _                      ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXAttributes_setQName LIB "TB_XML60.DLL" ALIAS "IMXAttributes_setQName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
  , BYVAL strQName AS STRING _                          ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXAttributes_setType LIB "TB_XML60.DLL" ALIAS "IMXAttributes_setType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
  , BYVAL strType AS STRING _                           ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXAttributes_setURI LIB "TB_XML60.DLL" ALIAS "IMXAttributes_setURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
  , BYVAL strURI AS STRING _                            ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXAttributes_setValue LIB "TB_XML60.DLL" ALIAS "IMXAttributes_setValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
  , BYVAL strValue AS STRING _                          ' <ANSI STRING> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IMXWriter
' IID = {4D7FF4BA-1565-4EA8-94E1-6E724A46F98D}
' IMXWriter interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE SUB IMXWriter_put_output LIB "TB_XML60.DLL" ALIAS "IMXWriter_put_output" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varDestination AS VARIANT _                   ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXWriter_get_output LIB "TB_XML60.DLL" ALIAS "IMXWriter_get_output" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF varDestination AS VARIANT _                   ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IMXWriter_put_encoding LIB "TB_XML60.DLL" ALIAS "IMXWriter_put_encoding" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strEncoding AS STRING _                       ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXWriter_get_encoding LIB "TB_XML60.DLL" ALIAS "IMXWriter_get_encoding" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IMXWriter_put_byteOrderMark LIB "TB_XML60.DLL" ALIAS "IMXWriter_put_byteOrderMark" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL fWriteByteOrderMark AS INTEGER _              ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXWriter_get_byteOrderMark LIB "TB_XML60.DLL" ALIAS "IMXWriter_get_byteOrderMark" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IMXWriter_put_indent LIB "TB_XML60.DLL" ALIAS "IMXWriter_put_indent" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL fIndentMode AS INTEGER _                      ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXWriter_get_indent LIB "TB_XML60.DLL" ALIAS "IMXWriter_get_indent" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IMXWriter_put_standalone LIB "TB_XML60.DLL" ALIAS "IMXWriter_put_standalone" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL fValue AS INTEGER _                           ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXWriter_get_standalone LIB "TB_XML60.DLL" ALIAS "IMXWriter_get_standalone" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IMXWriter_put_omitXMLDeclaration LIB "TB_XML60.DLL" ALIAS "IMXWriter_put_omitXMLDeclaration" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL fValue AS INTEGER _                           ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXWriter_get_omitXMLDeclaration LIB "TB_XML60.DLL" ALIAS "IMXWriter_get_omitXMLDeclaration" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IMXWriter_put_version LIB "TB_XML60.DLL" ALIAS "IMXWriter_put_version" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strVersion AS STRING _                        ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXWriter_get_version LIB "TB_XML60.DLL" ALIAS "IMXWriter_get_version" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IMXWriter_put_disableOutputEscaping LIB "TB_XML60.DLL" ALIAS "IMXWriter_put_disableOutputEscaping" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL fValue AS INTEGER _                           ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXWriter_get_disableOutputEscaping LIB "TB_XML60.DLL" ALIAS "IMXWriter_get_disableOutputEscaping" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IMXWriter_flush LIB "TB_XML60.DLL" ALIAS "IMXWriter_flush" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IVBSAXAttributes
' IID = {10DC0586-132B-4CAC-8BB3-DB00AC8B7EE0}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IVBSAXAttributes_get_length LIB "TB_XML60.DLL" ALIAS "IVBSAXAttributes_get_length" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IVBSAXAttributes_getURI LIB "TB_XML60.DLL" ALIAS "IVBSAXAttributes_getURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IVBSAXAttributes_getLocalName LIB "TB_XML60.DLL" ALIAS "IVBSAXAttributes_getLocalName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IVBSAXAttributes_getQName LIB "TB_XML60.DLL" ALIAS "IVBSAXAttributes_getQName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IVBSAXAttributes_getIndexFromName LIB "TB_XML60.DLL" ALIAS "IVBSAXAttributes_getIndexFromName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strURI AS STRING _                            ' <ANSI STRING> [in]
  , BYVAL strLocalName AS STRING _                      ' <ANSI STRING> [in]
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IVBSAXAttributes_getIndexFromQName LIB "TB_XML60.DLL" ALIAS "IVBSAXAttributes_getIndexFromQName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strQName AS STRING _                          ' <ANSI STRING> [in]
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IVBSAXAttributes_getType LIB "TB_XML60.DLL" ALIAS "IVBSAXAttributes_getType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IVBSAXAttributes_getTypeFromName LIB "TB_XML60.DLL" ALIAS "IVBSAXAttributes_getTypeFromName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strURI AS STRING _                            ' <ANSI STRING> [in]
  , BYVAL strLocalName AS STRING _                      ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IVBSAXAttributes_getTypeFromQName LIB "TB_XML60.DLL" ALIAS "IVBSAXAttributes_getTypeFromQName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strQName AS STRING _                          ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IVBSAXAttributes_getValue LIB "TB_XML60.DLL" ALIAS "IVBSAXAttributes_getValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IVBSAXAttributes_getValueFromName LIB "TB_XML60.DLL" ALIAS "IVBSAXAttributes_getValueFromName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strURI AS STRING _                            ' <ANSI STRING> [in]
  , BYVAL strLocalName AS STRING _                      ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IVBSAXAttributes_getValueFromQName LIB "TB_XML60.DLL" ALIAS "IVBSAXAttributes_getValueFromQName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strQName AS STRING _                          ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************


' ########################################################################################
' Interface name = ISAXAttributes
' IID = {F078ABE1-45D2-4832-91EA-4466CE2F25C9}
' ISAXAttributes interface
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISAXAttributes_getLength LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getLength" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION ISAXAttributes_getURI LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getURI" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISAXAttributes_getLocalName LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getLocalName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISAXAttributes_getQName LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getQName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE SUB ISAXAttributes_getName LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
  , BYREF strUri AS STRING _                            ' <ANSI STRING> [out]
  , BYREF strLocalName AS STRING _                      ' <ANSI STRING> [out]
  , BYREF strQName AS STRING _                          ' <ANSI STRING> [out]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXAttributes_getIndexFromName LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getIndexFromName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL strUri AS STRING _                            ' <ANSI STRING> [in]
  , BYVAL strLocalName AS STRING _                      ' <ANSI STRING> [in]
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION ISAXAttributes_getIndexFromQName LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getIndexFromQName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL strQName AS STRING _                          ' <ANSI STRING> [in]
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION ISAXAttributes_getType LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getType" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISAXAttributes_getTypeFromName LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getTypeFromName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL strUri AS STRING _                            ' <ANSI STRING> [in]
  , BYVAL strLocalName AS STRING _                      ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISAXAttributes_getTypeFromQName LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getTypeFromQName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL strQName AS STRING _                          ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISAXAttributes_getValue LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getValue" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL nIndex AS LONG _                              ' %VT_INT <LONG> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISAXAttributes_getValueFromName LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getValueFromName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL strUri AS STRING _                            ' <ANSI STRING> [in]
  , BYVAL strLocalName AS STRING _                      ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION ISAXAttributes_getValueFromQName LIB "TB_XML60.DLL" ALIAS "ISAXAttributes_getValueFromQName" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL strQName AS STRING _                         ' <ANSI STRING> [in]
    ) AS STRING
' ****************************************************************************************


' ########################################################################################
' Interface name = IVBSAXEntityResolver
' IID = {0C05D096-F45B-4ACA-AD1A-AA0BC25518DC}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE SUB IVBSAXEntityResolver_resolveEntity LIB "TB_XML60.DLL" ALIAS "IVBSAXEntityResolver_resolveEntity" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYREF strPublicId AS STRING _                       ' *<ANSI STRING> [in] [out]
  , BYREF strSystemId AS STRING _                       ' *<ANSI STRING> [in] [out]
  , BYREF varInput AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = ISAXEntityResolver
' IID = {99BCA7BD-E8C4-4D5F-A0CF-6D907901FF07}
' ISAXEntityResolver interface
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

' ****************************************************************************************
DECLARE SUB ISAXEntityResolver_resolveEntity LIB "TB_XML60.DLL" ALIAS "ISAXEntityResolver_resolveEntity" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchPublicId AS STRING _                      ' <ANSI STRING> [in]
  , BYVAL pwchSystemId AS STRING _                      ' <ANSI STRING> [in]
  , BYREF pvarInput AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IVBSAXLocator
' IID = {796E7AC5-5AA2-4EFF-ACAD-3FAAF01A3288}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IVBSAXLocator_get_columnNumber LIB "TB_XML60.DLL" ALIAS "IVBSAXLocator_get_columnNumber" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IVBSAXLocator_get_lineNumber LIB "TB_XML60.DLL" ALIAS "IVBSAXLocator_get_lineNumber" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS LONG
' ****************************************************************************************
DECLARE FUNCTION IVBSAXLocator_get_publicId LIB "TB_XML60.DLL" ALIAS "IVBSAXLocator_get_publicId" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE FUNCTION IVBSAXLocator_get_systemId LIB "TB_XML60.DLL" ALIAS "IVBSAXLocator_get_systemId" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************


' ########################################################################################
' Interface name = ISAXLocator
' IID = {9B7E472A-0DE4-4640-BFF3-84D38A051C31}
' ISAXLocator interface
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISAXLocator_getColumnNumber LIB "TB_XML60.DLL" ALIAS "ISAXLocator_getColumnNumber" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS LONG
DECLARE FUNCTION ISAXLocator_getLineNumber LIB "TB_XML60.DLL" ALIAS "ISAXLocator_getLineNumber" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS LONG
DECLARE FUNCTION ISAXLocator_getPublicId LIB "TB_XML60.DLL" ALIAS "ISAXLocator_getPublicId" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS STRING
DECLARE FUNCTION ISAXLocator_getSystemId LIB "TB_XML60.DLL" ALIAS "ISAXLocator_getSystemId" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS STRING
' ****************************************************************************************


' ########################################################################################
' Interface name = IVBSAXXMLFilter
' IID = {1299EB1B-5B88-433E-82DE-82CA75AD4E04}
' IVBSAXXMLFilter interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IVBSAXXMLFilter_get_parent LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLFilter_get_parent" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXXMLReader <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IVBSAXXMLFilter_putref_parent LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLFilter_putref_parent" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL oReader AS DWORD _                            ' *IVBSAXXMLReader <dispinterface> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = ISAXXMLFilter
' IID = {70409222-CA09-4475-ACB8-40312FE8D145}
' ISAXXMLFilter interface
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = ISAXXMLReader
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISAXXMLFilter_getFeature LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getFeature" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchName AS STRING _                          ' <ANSI STRING> [in]
    ) AS INTEGER                                        ' *%VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLFilter_putFeature LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putFeature" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchName AS STRING _                          ' <ANSI STRING> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [in]
' ****************************************************************************************
DECLARE SUB ISAXXMLFilter_getProperty LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchName AS STRING _                          ' <ANSI STRING> [in]
  , BYREF pvarValue AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISAXXMLFilter_putProperty LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchName AS STRING _                          ' <ANSI STRING> [in]
  , BYVAL varValue AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLFilter_getEntityResolver LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getEntityResolver" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS DWORD                                          ' **ISAXEntityResolver <interface> [out]
' ****************************************************************************************
DECLARE SUB ISAXXMLFilter_putEntityResolver LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putEntityResolver" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pResolver AS DWORD _                          ' *ISAXEntityResolver <interface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLFilter_getContentHandler LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getContentHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS DWORD                                          ' **ISAXContentHandler <interface> [out]
' ****************************************************************************************
DECLARE SUB ISAXXMLFilter_putContentHandler LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putContentHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pHandler AS DWORD _                           ' *ISAXContentHandler <interface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLFilter_getDTDHandler LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getDTDHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS DWORD                                          ' **ISAXDTDHandler <interface> [out]
' ****************************************************************************************
DECLARE SUB ISAXXMLFilter_putDTDHandler LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putDTDHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pHandler AS DWORD _                           ' *ISAXDTDHandler <interface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLFilter_getErrorHandler LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getErrorHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS DWORD                                          ' **ISAXErrorHandler <interface> [out]
' ****************************************************************************************
DECLARE SUB ISAXXMLFilter_putErrorHandler LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putErrorHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pHandler AS DWORD _                           ' *ISAXErrorHandler <interface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLFilter_getBaseURL LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getBaseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB ISAXXMLFilter_putBaseURL LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putBaseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchBaseUrl AS STRING _                       ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLFilter_getSecureBaseURL LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getSecureBaseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB ISAXXMLFilter_putSecureBaseURL LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putSecureBaseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchSecureBaseUrl AS STRING _                 ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB ISAXXMLFilter_parse LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_parse" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL varInput AS VARIANT _                         ' %VT_VARIANT <VARIANT> [opt] [in]
    )
' ****************************************************************************************
DECLARE SUB ISAXXMLFilter_parseURL LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_parseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchUrl AS STRING _                           ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLFilter_getParent LIB "TB_XML60.DLL" ALIAS "ISAXXMLFilter_getParent" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS DWORD                                          ' **ISAXXMLReader <interface> [out]
' ****************************************************************************************
DECLARE SUB ISAXXMLFilter_putParent LIB "TB_XML60.DLL" ALIAS "ISAXXMLFilter_putParent" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pReader AS DWORD _                            ' *ISAXXMLReader <interface> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IVBSAXXMLReader
' IID = {8C033CAA-6CD6-4F73-B728-4531AF74945F}
' IVBSAXXMLReader interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IVBSAXXMLReader_getFeature LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_getFeature" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strName AS STRING _                           ' <ANSI STRING> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IVBSAXXMLReader_putFeature LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_putFeature" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strName AS STRING _                           ' <ANSI STRING> [in]
  , BYVAL fValue AS INTEGER _                           ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE SUB IVBSAXXMLReader_getProperty LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_getProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strName AS STRING _                           ' <ANSI STRING> [in]
  , BYREF varValue AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IVBSAXXMLReader_putProperty LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_putProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strName AS STRING _                           ' <ANSI STRING> [in]
  , BYVAL varValue AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IVBSAXXMLReader_get_entityResolver LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_get_entityResolver" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXEntityResolver <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IVBSAXXMLReader_putref_entityResolver LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_putref_entityResolver" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL oResolver AS DWORD _                          ' *IVBSAXEntityResolver <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IVBSAXXMLReader_get_contentHandler LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_get_contentHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXContentHandler <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IVBSAXXMLReader_putref_contentHandler LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_putref_contentHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL oHandler AS DWORD _                           ' *IVBSAXContentHandler <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IVBSAXXMLReader_get_dtdHandler LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_get_dtdHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXDTDHandler <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IVBSAXXMLReader_putref_dtdHandler LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_putref_dtdHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL oHandler AS DWORD _                           ' *IVBSAXDTDHandler <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IVBSAXXMLReader_get_errorHandler LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_get_errorHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXErrorHandler <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IVBSAXXMLReader_putref_errorHandler LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_putref_errorHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL oHandler AS DWORD _                           ' *IVBSAXErrorHandler <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IVBSAXXMLReader_get_baseURL LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_get_baseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IVBSAXXMLReader_put_baseURL LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_put_baseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strBaseURL AS STRING _                        ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IVBSAXXMLReader_get_secureBaseURL LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_get_secureBaseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IVBSAXXMLReader_put_secureBaseURL LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_put_secureBaseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strSecureBaseURL AS STRING _                  ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IVBSAXXMLReader_parse LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_parse" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varInput AS VARIANT _                         ' %VT_VARIANT <VARIANT> [opt] [in]
    )
' ****************************************************************************************
DECLARE SUB IVBSAXXMLReader_parseURL LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_parseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strURL AS STRING _                            ' <ANSI STRING> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = IMXXMLFilter
' IID = {C90352F7-643C-4FBC-BB23-E996EB2D51FD}
' IMXXMLFilter interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION IMXXMLFilter_getFeature LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_getFeature" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strName AS STRING _                           ' <ANSI STRING> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE SUB IMXXMLFilter_putFeature LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_putFeature" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strName AS STRING _                           ' <ANSI STRING> [in]
  , BYVAL fValue AS INTEGER _                           ' %VT_BOOL <INTEGER> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXXMLFilter_getProperty LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_getProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strName AS STRING _                           ' <ANSI STRING> [in]
  , BYREF varValue AS VARIANT _                         ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB IMXXMLFilter_putProperty LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_putProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strName AS STRING _                           ' <ANSI STRING> [in]
  , BYVAL varValue AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXXMLFilter_get_entityResolver LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_get_entityResolver" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXEntityResolver <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IMXXMLFilter_putref_entityResolver LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_putref_entityResolver" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL oResolver AS DWORD _                          ' *IVBSAXEntityResolver <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXXMLFilter_get_contentHandler LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_get_contentHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXContentHandler <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IMXXMLFilter_putref_contentHandler LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_putref_contentHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL oHandler AS DWORD _                           ' *IVBSAXContentHandler <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXXMLFilter_get_dtdHandler LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_get_dtdHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXDTDHandler <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IMXXMLFilter_putref_dtdHandler LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_putref_dtdHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL oHandler AS DWORD _                           ' *IVBSAXDTDHandler <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXXMLFilter_get_errorHandler LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_get_errorHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS DWORD                                          ' **IVBSAXErrorHandler <dispinterface> [out]
' ****************************************************************************************
DECLARE SUB IMXXMLFilter_putref_errorHandler LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_putref_errorHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL oHandler AS DWORD _                           ' *IVBSAXErrorHandler <dispinterface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXXMLFilter_get_baseURL LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_get_baseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IMXXMLFilter_put_baseURL LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_put_baseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strBaseURL AS STRING _                        ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION IMXXMLFilter_get_secureBaseURL LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_get_secureBaseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB IMXXMLFilter_put_secureBaseURL LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_put_secureBaseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strSecureBaseURL AS STRING _                  ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB IMXXMLFilter_parse LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_parse" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL varInput AS VARIANT _                         ' %VT_VARIANT <VARIANT> [opt] [in]
    )
' ****************************************************************************************
DECLARE SUB IMXXMLFilter_parseURL LIB "TB_XML60.DLL" ALIAS "IVBSAXXMLReader_parseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_DISPATCH <dispinterface>
  , BYVAL strURL AS STRING _                            ' <ANSI STRING> [in]
    )
' ****************************************************************************************


' ########################################################################################
' Interface name = ISAXXMLReader
' IID = {A4F96ED0-F829-476E-81C0-CDC7BD2A0802}
' ISAXXMLReader interface
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

' ****************************************************************************************
DECLARE FUNCTION ISAXXMLReader_getFeature LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getFeature" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchName AS STRING _                          ' <ANSI STRING> [in]
    ) AS INTEGER                                        ' *%VT_BOOL <INTEGER> [out]
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLReader_putFeature LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putFeature" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchName AS STRING _                          ' <ANSI STRING> [in]
    ) AS INTEGER                                        ' %VT_BOOL <INTEGER> [in]
' ****************************************************************************************
DECLARE SUB ISAXXMLReader_getProperty LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchName AS STRING _                          ' <ANSI STRING> [in]
  , BYREF pvarValue AS VARIANT _                        ' *%VT_VARIANT <VARIANT> [out]
    )
' ****************************************************************************************
DECLARE SUB ISAXXMLReader_putProperty LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putProperty" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchName AS STRING _                          ' <ANSI STRING> [in]
  , BYVAL varValue AS VARIANT _                         ' %VT_VARIANT <VARIANT> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLReader_getEntityResolver LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getEntityResolver" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS DWORD                                          ' **ISAXEntityResolver <interface> [out]
' ****************************************************************************************
DECLARE SUB ISAXXMLReader_putEntityResolver LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putEntityResolver" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pResolver AS DWORD _                          ' *ISAXEntityResolver <interface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLReader_getContentHandler LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getContentHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS DWORD                                          ' **ISAXContentHandler <interface> [out]
' ****************************************************************************************
DECLARE SUB ISAXXMLReader_putContentHandler LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putContentHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pHandler AS DWORD _                           ' *ISAXContentHandler <interface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLReader_getDTDHandler LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getDTDHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS DWORD                                          ' **ISAXDTDHandler <interface> [out]
' ****************************************************************************************
DECLARE SUB ISAXXMLReader_putDTDHandler LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putDTDHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pHandler AS DWORD _                           ' *ISAXDTDHandler <interface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLReader_getErrorHandler LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getErrorHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS DWORD                                          ' **ISAXErrorHandler <interface> [out]
' ****************************************************************************************
DECLARE SUB ISAXXMLReader_putErrorHandler LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putErrorHandler" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pHandler AS DWORD _                           ' *ISAXErrorHandler <interface> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLReader_getBaseURL LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getBaseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB ISAXXMLReader_putBaseURL LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putBaseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchBaseUrl AS STRING _                       ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE FUNCTION ISAXXMLReader_getSecureBaseURL LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_getSecureBaseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
    ) AS STRING
' ****************************************************************************************
DECLARE SUB ISAXXMLReader_putSecureBaseURL LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_putSecureBaseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchSecureBaseUrl AS STRING _                 ' <ANSI STRING> [in]
    )
' ****************************************************************************************
DECLARE SUB ISAXXMLReader_parse LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_parse" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL varInput AS VARIANT _                         ' %VT_VARIANT <VARIANT> [opt] [in]
    )
' ****************************************************************************************
DECLARE SUB ISAXXMLReader_parseURL LIB "TB_XML60.DLL" ALIAS "ISAXXMLReader_parseURL" ( _
    BYVAL pthis AS DWORD PTR _                          ' %VT_UNKNOWN <interface>
  , BYVAL pwchUrl AS STRING _                           ' <ANSI STRING> [in]
    )
' ****************************************************************************************


' ########################################################################################
'                            Additional Wrapper Functions
' ########################################################################################

DECLARE FUNCTION XmlParseError_get_errorCode LIB "TB_XML60.DLL" ALIAS "XmlParseError_get_errorCode" (BYVAL pXmlDoc AS DWORD) AS LONG
DECLARE FUNCTION XmlParseError_get_url LIB "TB_XML60.DLL" ALIAS "XmlParseError_get_url" (BYVAL pXmlDoc AS DWORD) AS STRING
DECLARE FUNCTION XmlParseError_get_reason LIB "TB_XML60.DLL" ALIAS "XmlParseError_get_reason" (BYVAL pXmlDoc AS DWORD) AS STRING
DECLARE FUNCTION XmlParseError_get_srcText LIB "TB_XML60.DLL" ALIAS "XmlParseError_get_srcText" (BYVAL pXmlDoc AS DWORD) AS STRING
DECLARE FUNCTION XmlParseError_get_line LIB "TB_XML60.DLL" ALIAS "XmlParseError_get_line" (BYVAL pXmlDoc AS DWORD) AS LONG
DECLARE FUNCTION XmlParseError_get_linepos LIB "TB_XML60.DLL" ALIAS "XmlParseError_get_linepos" (BYVAL pXmlDoc AS DWORD) AS LONG
DECLARE FUNCTION XmlParseError_get_filepos LIB "TB_XML60.DLL" ALIAS "XmlParseError_get_filepos" (BYVAL pXmlDoc AS DWORD) AS LONG
DECLARE FUNCTION XmlParseError_get_errorXPath LIB "TB_XML60.DLL" ALIAS "XmlParseError_get_errorXPath" (BYVAL pXmlDoc AS DWORD) AS STRING
DECLARE FUNCTION XmlParseError_get_allErrors LIB "TB_XML60.DLL" ALIAS "XmlParseError_get_allErrors" (BYVAL pXmlDoc AS DWORD) AS DWORD
DECLARE FUNCTION XmlParseError_get_errorParameters LIB "TB_XML60.DLL" ALIAS "XmlParseError_get_errorParameters" (BYVAL pXmlDoc AS DWORD, BYVAL index AS LONG) AS STRING
DECLARE FUNCTION XmlParseError_get_errorParametersCount LIB "TB_XML60.DLL" ALIAS "XmlParseError_get_errorParametersCount" (BYVAL pXmlDoc AS DWORD) AS LONG

' ########################################################################################
' This wrapper function allows to call the splitText method passing a reference to a
' IXMLDOMNode interface.
' ########################################################################################

DECLARE FUNCTION XMLDOMNodeText_splitText LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeText_splitText" (BYVAL pDOMNode AS DWORD, BYVAL offset AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMNodeCDATASection_splitText LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeText_splitText" (BYVAL pDOMNode AS DWORD, BYVAL offset AS LONG) AS DWORD

' ########################################################################################
' The following wrapper functions allow to use the methods and properties of the
' IXMLDOMElement interface passing a reference to a node object (IXMLDOMNode interface).
' ########################################################################################

DECLARE FUNCTION XMLDOMNodeElement_get_tagName LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeElement_get_tagName" (BYVAL pDOMNode AS DWORD) AS STRING
DECLARE SUB XMLDOMNodeElement_getAttribute LIB "TB_XML60.DLL"ALIAS "XMLDOMNodeElement_getAttribute" (BYVAL pDOMNode AS DWORD, BYVAL pbstrname AS STRING, BYREF value AS VARIANT)
DECLARE SUB XMLDOMNodeElement_setAttribute LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeElement_setAttribute" (BYVAL pDOMNode AS DWORD, BYVAL pbstrname AS STRING, BYVAL value AS VARIANT)
DECLARE SUB XMLDOMNodeElement_removeAttribute LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeElement_removeAttribute" (BYVAL pDOMNode AS DWORD, BYVAL pbstrname AS STRING)
DECLARE FUNCTION XMLDOMNodeElement_getAttributeNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeElement_getAttributeNode" (BYVAL pDOMNode AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMNodeElement_setAttributeNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeElement_setAttributeNode" (BYVAL pDOMNode AS DWORD, BYVAL DOMAttribute AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMNodeElement_removeAttributeNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeElement_removeAttributeNode" (BYVAL pDOMNode AS DWORD, BYVAL DOMAttribute AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMNodeElement_getElementsByTagName LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeElement_getElementsByTagName" (BYVAL pDOMNode AS DWORD, BYVAL tagName AS STRING) AS DWORD
DECLARE SUB XMLDOMNodeElement_normalize LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeElement_normalize" (BYVAL pDOMNode AS DWORD)

' ########################################################################################
' The following wrapper functions allow to use the methods and properties of the
' IXMLDOMAttribute interface passing a reference to a node object (IXMLDOMNode interface).
' ########################################################################################

DECLARE FUNCTION XMLDOMNodeAttribute_get_name LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttribute_get_name" (BYVAL pDOMNode AS DWORD) AS STRING
DECLARE SUB XMLDOMNodeAttribute_get_value LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttribute_get_value" (BYVAL pDOMNode AS DWORD, BYREF attributeValue AS VARIANT)
DECLARE SUB XMLDOMNodeAttribute_put_value LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttribute_put_value" (BYVAL pDOMNode AS DWORD, BYVAL attributeValue AS VARIANT)

' ########################################################################################
' The following wrapper functions allow to retrieve the attributes of a node avoiding the
' use of the intermediate IXMLDOMNamedNodeMap interface (the calls to retrieve and release
' this interface are performed inside the function).
' ########################################################################################

DECLARE FUNCTION XMLDOMNodeAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pDOMNode AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMNodeAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pDOMNode AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMNodeAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pDOMNode AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMNodeAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pDOMNode AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMNodeAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pDOMNode AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMNodeAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pDOMNode AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMNodeAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pDOMNode AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMNodeAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pDOMNode AS DWORD) AS DWORD
DECLARE SUB XMLDOMNodeAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pDOMNode AS DWORD)
DECLARE FUNCTION XMLDOMNodeAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pDOMNode AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMDocumentAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pXmlDoc AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pXmlDoc AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMDocumentAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pXmlDoc AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pXmlDoc AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pXmlDoc AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocumentAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pXmlDoc AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pXmlDoc AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pXmlDoc AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocumentAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pXmlDoc AS DWORD)
DECLARE FUNCTION XMLDOMDocumentAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pXmlDoc AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMDocument2Attributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pXmlDoc2 AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocument2Attributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pXmlDoc2 AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMDocument2Attributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pXmlDoc2 AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocument2Attributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pXmlDoc2 AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocument2Attributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pXmlDoc2 AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocument2Attributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pXmlDoc2 AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocument2Attributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pXmlDoc2 AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocument2Attributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pXmlDoc2 AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocument2Attributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pXmlDoc2 AS DWORD)
DECLARE FUNCTION XMLDOMDocument2Attributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pXmlDoc2 AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMDocument3Attributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pXmlDoc3 AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocument3Attributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pXmlDoc3 AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMDocument3Attributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pXmlDoc3 AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocument3Attributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pXmlDoc3 AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocument3Attributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pXmlDoc3 AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocument3Attributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pXmlDoc3 AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocument3Attributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pXmlDoc3 AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocument3Attributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pXmlDoc3 AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocument3Attributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pXmlDoc3 AS DWORD)
DECLARE FUNCTION XMLDOMDocument3Attributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pXmlDoc3 AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMCDATASectionAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pDataSection AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMCDATASectionAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pDataSection AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMCDATASectionAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pDataSection AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMCDATASectionAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pDataSection AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMCDATASectionAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pDataSection AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMCDATASectionAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pDataSection AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMCDATASectionAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pDataSection AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMCDATASectionAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pDataSection AS DWORD) AS DWORD
DECLARE SUB XMLDOMCDATASectionAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pDataSection AS DWORD)
DECLARE FUNCTION XMLDOMCDATASectionAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pDataSection AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMCharacterDataAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pCharData AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMCharacterDataAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pCharData AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMCharacterDataAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pCharData AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMCharacterDataAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pCharData AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMCharacterDataAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pCharData AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMCharacterDataAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pCharData AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMCharacterDataAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pCharData AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMCharacterDataAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pCharData AS DWORD) AS DWORD
DECLARE SUB XMLDOMCharacterDataAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pCharData AS DWORD)
DECLARE FUNCTION XMLDOMCharacterDataAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pCharData AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMCommentAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pComment AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMCommentAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pComment AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMCommentAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pComment AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMCommentAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pComment AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMCommentAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pComment AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMCommentAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pComment AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMCommentAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pComment AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMCommentAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pComment AS DWORD) AS DWORD
DECLARE SUB XMLDOMCommentAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pComment AS DWORD)
DECLARE FUNCTION XMLDOMCommentAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pComment AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMDocumentFragmentAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pDocFragment AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentFragmentAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pDocFragment AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMDocumentFragmentAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pDocFragment AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentFragmentAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pDocFragment AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentFragmentAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pDocFragment AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocumentFragmentAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pDocFragment AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentFragmentAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pDocFragment AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentFragmentAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pDocFragment AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocumentFragmentAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pDocFragment AS DWORD)
DECLARE FUNCTION XMLDOMDocumentFragmentAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pDocFragment AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMDocumentTypeAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pDocTyhpe AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pDocTyhpe AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pDocTyhpe AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pDocTyhpe AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pDocTyhpe AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocumentTypeAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pDocTyhpe AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pDocTyhpe AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pDocTyhpe AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocumentTypeAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pDocTyhpe AS DWORD)
DECLARE FUNCTION XMLDOMDocumentTypeAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pDocTyhpe AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMElementAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pDomElement AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMElementAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pDomElement AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMElementAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pDomElement AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMElementAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pDomElement AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMElementAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pDomElement AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMElementAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pDomElement AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMElementAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pDomElement AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMElementAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pDomElement AS DWORD) AS DWORD
DECLARE SUB XMLDOMElementAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pDomElement AS DWORD)
DECLARE FUNCTION XMLDOMElementAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pDomElement AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMEntityAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pDOMEntity AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMEntityAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pDOMEntity AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMEntityAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pDOMEntity AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMEntityAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pDOMEntity AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMEntityAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pDOMEntity AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMEntityAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pDOMEntity AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMEntityAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pDOMEntity AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMEntityAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pDOMEntity AS DWORD) AS DWORD
DECLARE SUB XMLDOMEntityAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pDOMEntity AS DWORD)
DECLARE FUNCTION XMLDOMEntityAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pDOMEntity AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMEntityReferenceAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pDOMEntityRef AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMEntityReferenceAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pDOMEntityRef AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMEntityReferenceAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pDOMEntityRef AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMEntityReferenceAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pDOMEntityRef AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMEntityReferenceAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pDOMEntityRef AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMEntityReferenceAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pDOMEntityRef AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMEntityReferenceAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pDOMEntityRef AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMEntityReferenceAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pDOMEntityRef AS DWORD) AS DWORD
DECLARE SUB XMLDOMEntityReferenceAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pDOMEntityRef AS DWORD)
DECLARE FUNCTION XMLDOMEntityReferenceAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pDOMEntityRef AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMNotationAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pNotation AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMNotationAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pNotation AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMNotationAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pNotation AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMNotationAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pNotation AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMNotationAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pNotation AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMNotationAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pNotation AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMNotationAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pNotation AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMNotationAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pNotation AS DWORD) AS DWORD
DECLARE SUB XMLDOMNotationAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pNotation AS DWORD)
DECLARE FUNCTION XMLDOMNotationAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pNotation AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMProcessingInstructionAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pProcInstr AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMProcessingInstructionAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pProcInstr AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMProcessingInstructionAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pProcInstr AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMProcessingInstructionAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pProcInstr AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMProcessingInstructionAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pProcInstr AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMProcessingInstructionAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pProcInstr AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMProcessingInstructionAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pProcInstr AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMProcessingInstructionAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pProcInstr AS DWORD) AS DWORD
DECLARE SUB XMLDOMProcessingInstructionAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pProcInstr AS DWORD)
DECLARE FUNCTION XMLDOMProcessingInstructionAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pProcInstr AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMTextAttributes_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getNamedItem" (BYVAL pDOMText AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMTextAttributes_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_setNamedItem" (BYVAL pDOMText AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMTextAttributes_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeNamedItem" (BYVAL pDOMText AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMTextAttributes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_item" (BYVAL pDOMText AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMTextAttributes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_length" (BYVAL pDOMText AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMTextAttributes_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_getQualifiedItem" (BYVAL pDOMText AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMTextAttributes_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_removeQualifiedItem" (BYVAL pDOMText AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMTextAttributes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_nextNode" (BYVAL pDOMText AS DWORD) AS DWORD
DECLARE SUB XMLDOMTextAttributes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_reset" (BYVAL pDOMText AS DWORD)
DECLARE FUNCTION XMLDOMTextAttributes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeAttributes_get_newEnum" (BYVAL pDOMText AS DWORD) AS DWORD


' ########################################################################################
' The following wrapper functions allow to work with child nodes without having to use an
' intermediate IXMLDONNodeList reference (the calls to retrieve and release this interface
' are performed inside the function).
' ########################################################################################

DECLARE FUNCTION XMLDOMNodeChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pDOMNode AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMNodeChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pDOMNode AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMNodeChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pDOMNode AS DWORD) AS DWORD
DECLARE SUB XMLDOMNodeChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pDOMNode AS DWORD)
DECLARE FUNCTION XMLDOMNodeChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pDOMNode AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMDocumentChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pXmlDoc AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pXmlDoc AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocumentChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pXmlDoc AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocumentChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pXmlDoc AS DWORD)
DECLARE FUNCTION XMLDOMDocumentChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pXmlDoc AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMDocument2ChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pXmlDoc2 AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocument2ChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pXmlDoc2 AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocument2ChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pXmlDoc2 AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocument2ChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pXmlDoc2 AS DWORD)
DECLARE FUNCTION XMLDOMDocument2ChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pXmlDoc2 AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMDocument3ChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pXmlDoc3 AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocument3ChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pXmlDoc3 AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocument3ChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pXmlDoc3 AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocument3ChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pXmlDoc3 AS DWORD)
DECLARE FUNCTION XMLDOMDocument3ChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pXmlDoc3 AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMAttributeChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pDOMAttribute AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMAttributeChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pDOMAttribute AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMAttributeChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pDOMAttribute AS DWORD) AS DWORD
DECLARE SUB XMLDOMAttributeChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pDOMAttribute AS DWORD)
DECLARE FUNCTION XMLDOMAttributeChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pDOMAttribute AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMCDATASectionChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pCDataSection AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMCDATASectionChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pCDataSection AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMCDATASectionChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pCDataSection AS DWORD) AS DWORD
DECLARE SUB XMLDOMCDATASectionChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pCDataSection AS DWORD)
DECLARE FUNCTION XMLDOMCDATASectionChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pCDataSection AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMCharacterDataChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pCharData AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMCharacterDataChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pCharData AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMCharacterDataChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pCharData AS DWORD) AS DWORD
DECLARE SUB XMLDOMCharacterDataChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pCharData AS DWORD)
DECLARE FUNCTION XMLDOMCharacterDataChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pCharData AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMCommentChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pComment AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMCommentChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pComment AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMCommentChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pComment AS DWORD) AS DWORD
DECLARE SUB XMLDOMCommentChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pComment AS DWORD)
DECLARE FUNCTION XMLDOMCommentChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pComment AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMDocumentFragmentChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pDocFragment AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentFragmentChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pDocFragment AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocumentFragmentChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pDocFragment AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocumentFragmentChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pDocFragment AS DWORD)
DECLARE FUNCTION XMLDOMDocumentFragmentChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pDocFragment AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMDocumentTypeChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pDocTyhpe AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pDocTyhpe AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocumentTypeChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pDocTyhpe AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocumentTypeChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pDocTyhpe AS DWORD)
DECLARE FUNCTION XMLDOMDocumentTypeChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pDocTyhpe AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMElementChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pDOMElement AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMElementChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pDOMElement AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMElementChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pDOMElement AS DWORD) AS DWORD
DECLARE SUB XMLDOMElementChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pDOMElement AS DWORD)
DECLARE FUNCTION XMLDOMElementChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pDOMElement AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMEntityChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pDOMEntity AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMEntityChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pDOMEntity AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMEntityChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pDOMEntity AS DWORD) AS DWORD
DECLARE SUB XMLDOMEntityChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pDOMEntity AS DWORD)
DECLARE FUNCTION XMLDOMEntityChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pDOMEntity AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMEntityReferenceChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pDOMEntityRef AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMEntityReferenceChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pDOMEntityRef AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMEntityReferenceChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pDOMEntityRef AS DWORD) AS DWORD
DECLARE SUB XMLDOMEntityReferenceChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pDOMEntityRef AS DWORD)
DECLARE FUNCTION XMLDOMEntityReferenceChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pDOMEntityRef AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMNotationChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pDOMNotation AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMNotationChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pDOMNotation AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMNotationChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pDOMNotation AS DWORD) AS DWORD
DECLARE SUB XMLDOMNotationChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pDOMNotation AS DWORD)
DECLARE FUNCTION XMLDOMNotationChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pDOMNotation AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMProcessingInstructionChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pProcInstr AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMProcessingInstructionChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pProcInstr AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMProcessingInstructionChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pProcInstr AS DWORD) AS DWORD
DECLARE SUB XMLDOMProcessingInstructionChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pProcInstr AS DWORD)
DECLARE FUNCTION XMLDOMProcessingInstructionChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pProcInstr AS DWORD) AS DWORD

DECLARE FUNCTION XMLDOMTextChildNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_item" (BYVAL pDOMText AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMTextChildNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_length" (BYVAL pDOMText AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMTextChildNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_nextNode" (BYVAL pDOMText AS DWORD) AS DWORD
DECLARE SUB XMLDOMTextChildNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_reset" (BYVAL pDOMText AS DWORD)
DECLARE FUNCTION XMLDOMTextChildNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeChildNodes_get_newEnum" (BYVAL pDOMText AS DWORD) AS DWORD


' ########################################################################################
' The following wrapper functions allow to work with selected nodes without having to use
' an intermediate IXMLDONNodeList reference.
' ########################################################################################

DECLARE FUNCTION XMLDOMNodeSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pDOMNode AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMNodeSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pDOMNode AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMNodeSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pDOMNode AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMNodeSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pDOMNode AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMNodeSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pDOMNode AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMDocumentSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pXmlDoc AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pXmlDoc AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMDocumentSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pXmlDoc AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMDocumentSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pXmlDoc AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMDocumentSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pXmlDoc AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMDocument2SelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pXmlDoc2 AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocument2SelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pXmlDoc2 AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMDocument2SelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pXmlDoc2 AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMDocument2SelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pXmlDoc2 AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMDocument2SelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pXmlDoc2 AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMDocument3SelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pXmlDoc3 AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocument3SelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pXmlDoc3 AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMDocument3SelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pXmlDoc3 AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMDocument3SelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pXmlDoc3 AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMDocument3SelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pXmlDoc3 AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMAttributeSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pDOMAttribute AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMAttributeSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pDOMAttribute AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMAttributeSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pDOMAttribute AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMAttributeSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pDOMAttribute AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMAttributeSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pDOMAttribute AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMCDATASectionSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pCDataSection AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMCDATASectionSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pCDataSection AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMCDATASectionSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pCDataSection AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMCDATASectionSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pCDataSection AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMCDATASectionSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pCDataSection AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMCharacterDataSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pCharData AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMCharacterDataSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pCharData AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMCharacterDataSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pCharData AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMCharacterDataSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pCharData AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMCharacterDataSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pCharData AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMCommentSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pComment AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMCommentSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pComment AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMCommentSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pComment AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMCommentSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pComment AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMCommentSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pComment AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMDocumentFragmentSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pDocFragment AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentFragmentSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pDocFragment AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMDocumentFragmentSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pDocFragment AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMDocumentFragmentSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pDocFragment AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMDocumentFragmentSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pDocFragment AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMDocumentTypeSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pDocType AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pDocType AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMDocumentTypeSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pDocType AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMDocumentTypeSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pDocType AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMDocumentTypeSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pDocType AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMElementSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pDOMElement AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMElementSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pDOMElement AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMElementSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pDOMElement AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMElementSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pDOMElement AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMElementSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pDOMElement AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMEntitySelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pDOMEntity AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMEntitySelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pDOMEntity AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMEntitySelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pDOMEntity AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMEntitySelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pDOMEntity AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMEntitySelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pDOMEntity AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMEntityReferenceSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pDOMEntityRef AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMEntityReferenceSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pDOMEntityRef AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMEntityReferenceSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pDOMEntityRef AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMEntityReferenceSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pDOMEntityRef AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMEntityReferenceSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pDOMEntityRef AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMNotationSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pDOMNotation AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMNotationSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pDOMNotation AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMNotationSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pDOMNotation AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMNotationSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pDOMNotation AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMNotationSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pDOMNotation AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMProcessingInstructionSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pProcInstr AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMProcessingInstructionSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pProcInstr AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMProcessingInstructionSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pProcInstr AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMProcessingInstructionSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pProcInstr AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMProcessingInstructionSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pProcInstr AS DWORD, BYVAL queryString AS STRING) AS DWORD

DECLARE FUNCTION XMLDOMTextSelectNodes_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_item" (BYVAL pDOMText AS DWORD, BYVAL queryString AS STRING, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMTextSelectNodes_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_length" (BYVAL pDOMText AS DWORD, BYVAL queryString AS STRING) AS LONG
DECLARE FUNCTION XMLDOMTextSelectNodes_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_nextNode" (BYVAL pDOMText AS DWORD, BYVAL queryString AS STRING) AS DWORD
DECLARE SUB XMLDOMTextSelectNodes_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_reset" (BYVAL pDOMText AS DWORD, BYVAL queryString AS STRING)
DECLARE FUNCTION XMLDOMTextSelectNodes_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeSelectNodes_get_newEnum" (BYVAL pDOMText AS DWORD, BYVAL queryString AS STRING) AS DWORD

' ########################################################################################
' The following wrapper functions allow to use the members of the IXMLDOMEntity interface
' passing a reference to a DOMNode interface.
' ########################################################################################

DECLARE SUB XMLDOMNodeEntity_get_publicId LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeEntity_get_publicId" (BYVAL pDOMNode AS DWORD, BYREF publicId AS VARIANT)
DECLARE SUB XMLDOMNodeEntity_get_systemId LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeEntity_get_systemId" (BYVAL pDOMNode AS DWORD, BYREF systemId AS VARIANT)
DECLARE FUNCTION XMLDOMNodeEntity_get_notationName LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeEntity_get_notationName" (BYVAL pDOMNode AS DWORD) AS STRING

' ########################################################################################
' The following wrapper functions allow to use the members of the IXMLDOMNotation
' interface passing a reference to a DOMNode interface.
' ########################################################################################

DECLARE SUB XMLDOMNodeNotation_get_publicId LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeNotation_get_publicId" (BYVAL pDOMNode AS DWORD, BYREF publicId AS VARIANT)
DECLARE SUB XMLDOMNodeNotation_get_systemId LIB "TB_XML60.DLL" ALIAS "XMLDOMNodeNotation_get_systemId" (BYVAL pDOMNode AS DWORD, BYREF systemId AS VARIANT)

' ########################################################################################
' The following wrapper functions allow to retrieve the entities of a document passing a
' a reference to a IXMLDOMDocumentType interface instead of having to call the
' IXMLDOMDocumentType_get_entities function to get a reference to the IXMLDOMNamedNodeMap
' interface. However, if they are going to be used in a loop, is more eficient to first
' retrieve the reference to the IXMLDOMNamedNodeMap interface outside the loop and then
' use the methods and properties of that interface instead of the wrapper functions below,
' since it involves less calls and memory allocations.
' ########################################################################################

DECLARE FUNCTION XMLDOMDocumentTypeEntities_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeEntities_getNamedItem" (BYVAL pDOMDocType AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeEntities_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeEntities_setNamedItem" (BYVAL pDOMDocType AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeEntities_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeEntities_removeNamedItem" (BYVAL pDOMDocType AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeEntities_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeEntities_get_item" (BYVAL pDOMDocType AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeEntities_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeEntities_get_length" (BYVAL pDOMDocType AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocumentTypeEntities_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeEntities_getQualifiedItem" (BYVAL pDOMDocType AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeEntities_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeEntities_removeQualifiedItem" (BYVAL pDOMDocType AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeEntities_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeEntities_nextNode" (BYVAL pDOMDocType AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocumentTypeEntities_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeEntities_reset" (BYVAL pDOMDocType AS DWORD)
DECLARE FUNCTION XMLDOMDocumentTypeEntities_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeEntities_get_newEnum" (BYVAL pDOMDocType AS DWORD) AS DWORD

' ########################################################################################
' The following wrapper functions allow to retrieve the notations of a document passing a
' a reference to a IXMLDOMDocumentType interface instead of having to call the
' IXMLDOMDocumentType_get_notations function to get a reference to the IXMLDOMNamedNodeMap
' interface. However, if they are going to be used in a loop, is more eficient to first
' retrieve the reference to the IXMLDOMNamedNodeMap interface outside the loop and then
' use the methods and properties of that interface instead of the wrapper functions below,
' since it involves less calls and memory allocations.
' ########################################################################################

DECLARE FUNCTION XMLDOMDocumentTypeNotations_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeNotations_getNamedItem" (BYVAL pDOMDocType AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeNotations_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeNotations_setNamedItem" (BYVAL pDOMDocType AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeNotations_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeNotations_removeNamedItem" (BYVAL pDOMDocType AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeNotations_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeNotations_get_item" (BYVAL pDOMDocType AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeNotations_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeNotations_get_length" (BYVAL pDOMDocType AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocumentTypeNotations_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeNotations_getQualifiedItem" (BYVAL pDOMDocType AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeNotations_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeNotations_removeQualifiedItem" (BYVAL pDOMDocType AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentTypeNotations_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeNotations_nextNode" (BYVAL pDOMDocType AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocumentTypeNotations_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeNotations_reset" (BYVAL pDOMDocType AS DWORD)
DECLARE FUNCTION XMLDOMDocumentTypeNotations_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentTypeNotations_get_newEnum" (BYVAL pDOMDocType AS DWORD) AS DWORD

' ########################################################################################
' The following wrapper functions allow to retrieve the entities of a document passing a
' a reference to a IXMLDOMDocument interface instead of having to call the
' IXMLDOMDocument_get_doctype and IXMLDOMDocumentType_get_entities functions to get a
' reference to the IXMLDOMNamedNodeMap interface.
' ########################################################################################

DECLARE FUNCTION XMLDOMDocumentEntities_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentEntities_getNamedItem" (BYVAL pXmlDoc AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentEntities_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentEntities_setNamedItem" (BYVAL pXmlDoc AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMDocumentEntities_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentEntities_removeNamedItem" (BYVAL pXmlDoc AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentEntities_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentEntities_get_item" (BYVAL pXmlDoc AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentEntities_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentEntities_get_length" (BYVAL pXmlDoc AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocumentEntities_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentEntities_getQualifiedItem" (BYVAL pXmlDoc AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentEntities_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentEntities_removeQualifiedItem" (BYVAL pXmlDoc AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentEntities_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentEntities_nextNode" (BYVAL pXmlDoc AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocumentEntities_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentEntities_reset" (BYVAL pXmlDoc AS DWORD)
DECLARE FUNCTION XMLDOMDocumentEntities_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentEntities_get_newEnum" (BYVAL pXmlDoc AS DWORD) AS DWORD

' ########################################################################################
' The following wrapper functions allow to retrieve the notations of a document passing a
' a reference to a IXMLDOMDocument interface instead of having to call the
' IXMLDOMDocument_get_doctype and IXMLDOMDocumentType_get_notations functions to get a
' reference to the IXMLDOMNamedNodeMap interface.
' ########################################################################################

DECLARE FUNCTION XMLDOMDocumentNotations_getNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentNotations_getNamedItem" (BYVAL pXmlDoc AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentNotations_setNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentNotations_setNamedItem" (BYVAL pXmlDoc AS DWORD, BYVAL newItem AS DWORD) AS DWORD
DECLARE FUNCTION XMLDOMDocumentNotations_removeNamedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentNotations_removeNamedItem" (BYVAL pXmlDoc AS DWORD, BYVAL pbstrname AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentNotations_get_item LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentNotations_get_item" (BYVAL pXmlDoc AS DWORD, BYVAL index AS LONG) AS DWORD
DECLARE FUNCTION XMLDOMDocumentNotations_get_length LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentNotations_get_length" (BYVAL pXmlDoc AS DWORD) AS LONG
DECLARE FUNCTION XMLDOMDocumentNotations_getQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentNotations_getQualifiedItem" (BYVAL pXmlDoc AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentNotations_removeQualifiedItem LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentNotations_removeQualifiedItem" (BYVAL pXmlDoc AS DWORD, BYVAL baseName AS STRING, BYVAL namespaceURI AS STRING) AS DWORD
DECLARE FUNCTION XMLDOMDocumentNotations_nextNode LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentNotations_nextNode" (BYVAL pXmlDoc AS DWORD) AS DWORD
DECLARE SUB XMLDOMDocumentNotations_reset LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentNotations_reset" (BYVAL pXmlDoc AS DWORD)
DECLARE FUNCTION XMLDOMDocumentNotations_get_newEnum LIB "TB_XML60.DLL" ALIAS "XMLDOMDocumentNotations_get_newEnum" (BYVAL pXmlDoc AS DWORD) AS DWORD
