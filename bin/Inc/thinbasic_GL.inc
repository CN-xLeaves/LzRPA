  '*********************************************************
  '*              OpenGL "gl.h" for thinBASIC              *
  '*                                                       *
  '*           based on work of Scott Martindale           *
  '*          thinBASIC version by Petr Schreiber          *
  '*                                                       *
  '*              Release 16th January 2013                *
  '*********************************************************


'Datatypes

    ALIAS DWORD AS GLenum      '32-Bit unsigned
    ALIAS BYTE  AS GLboolean   '8-Bit  unsigned
    ALIAS DWORD AS GLbitfield  '32-Bit unsigned
    ALIAS BYTE  AS GLbyte      '8-Bit  signed
    ALIAS INTEGER AS GLshort   '16-Bit signed
    ALIAS LONG    AS GLint     '32-Bit signed
    ALIAS BYTE    AS GLubyte   '8-Bit  unsigned
    ALIAS WORD    AS GLushort  '16-Bit unsigned
    ALIAS DWORD   AS GLuint    '32-Bit unsigned
    ALIAS LONG    AS GLsizei   '32-Bit signed
    ALIAS SINGLE  AS GLfloat   'single precision float
    ALIAS SINGLE  AS GLclampf  'single precision float in [0,1]
    ALIAS DOUBLE  AS GLdouble  'double precision float
    ALIAS DOUBLE  AS GLclampd  'double precision float in [0,1]
    ALIAS ANY     AS GLvoid    'No real need, but why not...
    Alias DWord   As GLpointer 
'*********************************************************************************

'** Extensions **
    %GL_VERSION_1_1                      = 1
    %GL_EXT_blend_color                  = 1
    %GL_EXT_blend_minmax                 = 1
    %GL_EXT_blend_subtract               = 1
    %GL_EXT_abgr                         = 1
    %GL_EXT_bgra                         = 1
    %GL_EXT_clip_volume_hint             = 1
    %GL_EXT_color_table                  = 1
    %GL_EXT_convolution                  = 1
    %GL_EXT_compiled_vertex_array        = 1
    %GL_EXT_cull_vertex                  = 1
    %GL_EXT_histogram                    = 1
    %GL_EXT_packed_pixels                = 1
    %GL_EXT_paletted_texture             = 1
    %GL_EXT_polygon_offset               = 1
    %GL_EXT_secondary_color              = 1
    %GL_EXT_separate_specular_color      = 1
    %GL_EXT_vertex_array                 = 1
    %GL_WIN_swap_hint                    = 1

'** AttribMask **
    %GL_CURRENT_BIT                      = &H000000001
    %GL_POINT_BIT                        = &H000000002
    %GL_LINE_BIT                         = &H000000004
    %GL_POLYGON_BIT                      = &H000000008
    %GL_POLYGON_STIPPLE_BIT              = &H000000010
    %GL_PIXEL_MODE_BIT                   = &H000000020
    %GL_LIGHTING_BIT                     = &H000000040
    %GL_FOG_BIT                          = &H000000080
    %GL_DEPTH_BUFFER_BIT                 = &H000000100
    %GL_ACCUM_BUFFER_BIT                 = &H000000200
    %GL_STENCIL_BUFFER_BIT               = &H000000400
    %GL_VIEWPORT_BIT                     = &H000000800
    %GL_TRANSFORM_BIT                    = &H000001000
    %GL_ENABLE_BIT                       = &H000002000
    %GL_COLOR_BUFFER_BIT                 = &H000004000
    %GL_HINT_BIT                         = &H000008000
    %GL_EVAL_BIT                         = &H000010000
    %GL_LIST_BIT                         = &H000020000
    %GL_TEXTURE_BIT                      = &H000040000
    %GL_SCISSOR_BIT                      = &H000080000
    %GL_ALL_ATTRIB_BITS                  = &H0000fffff

'** ClientAttribMask **
    %GL_CLIENT_PIXEL_STORE_BIT           = &H000000001
    %GL_CLIENT_VERTEX_ARRAY_BIT          = &H000000002
    %GL_CLIENT_ALL_ATTRIB_BITS           = &H0FFFFFFFF

'** Boolean **
    %GL_FALSE                            = 0
    %GL_TRUE                             = 1

'** BeginMode **
    %GL_POINTS                           = &H00000
    %GL_LINES                            = &H00001
    %GL_LINE_LOOP                        = &H00002
    %GL_LINE_STRIP                       = &H00003
    %GL_TRIANGLES                        = &H00004
    %GL_TRIANGLE_STRIP                   = &H00005
    %GL_TRIANGLE_FAN                     = &H00006
    %GL_QUADS                            = &H00007
    %GL_QUAD_STRIP                       = &H00008
    %GL_POLYGON                          = &H00009

'** AccumOp **
    %GL_ACCUM                            = &H00100
    %GL_LOAD                             = &H00101
    %GL_RETURN                           = &H00102
    %GL_MULT                             = &H00103
    %GL_ADD                              = &H00104

'** AlphaFunction **
    %GL_NEVER                            = &H00200
    %GL_LESS                             = &H00201
    %GL_EQUAL                            = &H00202
    %GL_LEQUAL                           = &H00203
    %GL_GREATER                          = &H00204
    %GL_NOTEQUAL                         = &H00205
    %GL_GEQUAL                           = &H00206
    %GL_ALWAYS                           = &H00207

'** BlendingFactorDest **
    %GL_ZERO                             = 0
    %GL_ONE                              = 1
    %GL_SRC_COLOR                        = &H00300
    %GL_ONE_MINUS_SRC_COLOR              = &H00301
    %GL_SRC_ALPHA                        = &H00302
    %GL_ONE_MINUS_SRC_ALPHA              = &H00303
    %GL_DST_ALPHA                        = &H00304
    %GL_ONE_MINUS_DST_ALPHA              = &H00305


'** BlendingFactorSrc **
    %GL_DST_COLOR                        = &H00306
    %GL_ONE_MINUS_DST_COLOR              = &H00307
    %GL_SRC_ALPHA_SATURATE               = &H00308

'** DrawBufferMode **
    %GL_NONE                             = 0
    %GL_FRONT_LEFT                       = &H00400
    %GL_FRONT_RIGHT                      = &H00401
    %GL_BACK_LEFT                        = &H00402
    %GL_BACK_RIGHT                       = &H00403
    %GL_FRONT                            = &H00404
    %GL_BACK                             = &H00405
    %GL_LEFT                             = &H00406
    %GL_RIGHT                            = &H00407
    %GL_FRONT_AND_BACK                   = &H00408
    %GL_AUX0                             = &H00409
    %GL_AUX1                             = &H0040A
    %GL_AUX2                             = &H0040B
    %GL_AUX3                             = &H0040C

'** ErrorCode **
    %GL_NO_ERROR                         = 0
    %GL_INVALID_ENUM                     = &H00500
    %GL_INVALID_VALUE                    = &H00501
    %GL_INVALID_OPERATION                = &H00502
    %GL_STACK_OVERFLOW                   = &H00503
    %GL_STACK_UNDERFLOW                  = &H00504
    %GL_OUT_OF_MEMORY                    = &H00505


'** FeedbackType **
    %GL_2D                               = &H00600
    %GL_3D                               = &H00601
    %GL_3D_COLOR                         = &H00602
    %GL_3D_COLOR_TEXTURE                 = &H00603
    %GL_4D_COLOR_TEXTURE                 = &H00604

'** FeedBackToken **
    %GL_PASS_THROUGH_TOKEN               = &H00700
    %GL_POINT_TOKEN                      = &H00701
    %GL_LINE_TOKEN                       = &H00702
    %GL_POLYGON_TOKEN                    = &H00703
    %GL_BITMAP_TOKEN                     = &H00704
    %GL_DRAW_PIXEL_TOKEN                 = &H00705
    %GL_COPY_PIXEL_TOKEN                 = &H00706
    %GL_LINE_RESET_TOKEN                 = &H00707

'** FogMode **
    %GL_EXP                              = &H00800
    %GL_EXP2                             = &H00801

'** FrontFaceDirection **
    %GL_CW                               = &H00900
    %GL_CCW                              = &H00901

'** GetMapQuery **
    %GL_COEFF                            = &H00A00
    %GL_ORDER                            = &H00A01
    %GL_DOMAIN                           = &H00A02

'** GetPixelMap **
    %GL_PIXEL_MAP_I_TO_I                 = &H00C70
    %GL_PIXEL_MAP_S_TO_S                 = &H00C71
    %GL_PIXEL_MAP_I_TO_R                 = &H00C72
    %GL_PIXEL_MAP_I_TO_G                 = &H00C73
    %GL_PIXEL_MAP_I_TO_B                 = &H00C74
    %GL_PIXEL_MAP_I_TO_A                 = &H00C75
    %GL_PIXEL_MAP_R_TO_R                 = &H00C76
    %GL_PIXEL_MAP_G_TO_G                 = &H00C77
    %GL_PIXEL_MAP_B_TO_B                 = &H00C78
    %GL_PIXEL_MAP_A_TO_A                 = &H00C79

'** GetPointervPName **
    %GL_VERTEX_ARRAY_POINTER             = &H0808E
    %GL_NORMAL_ARRAY_POINTER             = &H0808F
    %GL_COLOR_ARRAY_POINTER              = &H08090
    %GL_INDEX_ARRAY_POINTER              = &H08091
    %GL_TEXTURE_COORD_ARRAY_POINTER      = &H08092
    %GL_EDGE_FLAG_ARRAY_POINTER          = &H08093

'** GetPName **
    %GL_CURRENT_COLOR                    = &H00B00
    %GL_CURRENT_INDEX                    = &H00B01
    %GL_CURRENT_NORMAL                   = &H00B02
    %GL_CURRENT_TEXTURE_COORDS           = &H00B03
    %GL_CURRENT_RASTER_COLOR             = &H00B04
    %GL_CURRENT_RASTER_INDEX             = &H00B05
    %GL_CURRENT_RASTER_TEXTURE_COORDS    = &H00B06
    %GL_CURRENT_RASTER_POSITION          = &H00B07
    %GL_CURRENT_RASTER_POSITION_VALID    = &H00B08
    %GL_CURRENT_RASTER_DISTANCE          = &H00B09
    %GL_POINT_SMOOTH                     = &H00B10
    %GL_POINT_SIZE                       = &H00B11
    %GL_POINT_SIZE_RANGE                 = &H00B12
    %GL_POINT_SIZE_GRANULARITY           = &H00B13
    %GL_LINE_SMOOTH                      = &H00B20
    %GL_LINE_WIDTH                       = &H00B21
    %GL_LINE_WIDTH_RANGE                 = &H00B22
    %GL_LINE_WIDTH_GRANULARITY           = &H00B23
    %GL_LINE_STIPPLE                     = &H00B24
    %GL_LINE_STIPPLE_PATTERN             = &H00B25
    %GL_LINE_STIPPLE_REPEAT              = &H00B26
    %GL_LIST_MODE                        = &H00B30
    %GL_MAX_LIST_NESTING                 = &H00B31
    %GL_LIST_BASE                        = &H00B32
    %GL_LIST_INDEX                       = &H00B33
    %GL_POLYGON_MODE                     = &H00B40
    %GL_POLYGON_SMOOTH                   = &H00B41
    %GL_POLYGON_STIPPLE                  = &H00B42
    %GL_EDGE_FLAG                        = &H00B43
    %GL_CULL_FACE                        = &H00B44
    %GL_CULL_FACE_MODE                   = &H00B45
    %GL_FRONT_FACE                       = &H00B46
    %GL_LIGHTING                         = &H00B50
    %GL_LIGHT_MODEL_LOCAL_VIEWER         = &H00B51
    %GL_LIGHT_MODEL_TWO_SIDE             = &H00B52
    %GL_LIGHT_MODEL_AMBIENT              = &H00B53
    %GL_SHADE_MODEL                      = &H00B54
    %GL_COLOR_MATERIAL_FACE              = &H00B55
    %GL_COLOR_MATERIAL_PARAMETER         = &H00B56
    %GL_COLOR_MATERIAL                   = &H00B57
    %GL_FOG                              = &H00B60
    %GL_FOG_INDEX                        = &H00B61
    %GL_FOG_DENSITY                      = &H00B62
    %GL_FOG_START                        = &H00B63
    %GL_FOG_END                          = &H00B64
    %GL_FOG_MODE                         = &H00B65
    %GL_FOG_COLOR                        = &H00B66
    %GL_DEPTH_RANGE                      = &H00B70
    %GL_DEPTH_TEST                       = &H00B71
    %GL_DEPTH_WRITEMASK                  = &H00B72
    %GL_DEPTH_CLEAR_VALUE                = &H00B73
    %GL_DEPTH_FUNC                       = &H00B74
    %GL_ACCUM_CLEAR_VALUE                = &H00B80
    %GL_STENCIL_TEST                     = &H00B90
    %GL_STENCIL_CLEAR_VALUE              = &H00B91
    %GL_STENCIL_FUNC                     = &H00B92
    %GL_STENCIL_VALUE_MASK               = &H00B93
    %GL_STENCIL_FAIL                     = &H00B94
    %GL_STENCIL_PASS_DEPTH_FAIL          = &H00B95
    %GL_STENCIL_PASS_DEPTH_PASS          = &H00B96
    %GL_STENCIL_REF                      = &H00B97
    %GL_STENCIL_WRITEMASK                = &H00B98
    %GL_MATRIX_MODE                      = &H00BA0
    %GL_NORMALIZE                        = &H00BA1
    %GL_VIEWPORT                         = &H00BA2
    %GL_MODELVIEW_STACK_DEPTH            = &H00BA3
    %GL_PROJECTION_STACK_DEPTH           = &H00BA4
    %GL_TEXTURE_STACK_DEPTH              = &H00BA5
    %GL_MODELVIEW_MATRIX                 = &H00BA6
    %GL_PROJECTION_MATRIX                = &H00BA7
    %GL_TEXTURE_MATRIX                   = &H00BA8
    %GL_ATTRIB_STACK_DEPTH               = &H00BB0
    %GL_CLIENT_ATTRIB_STACK_DEPTH        = &H00BB1
    %GL_ALPHA_TEST                       = &H00BC0
    %GL_ALPHA_TEST_FUNC                  = &H00BC1
    %GL_ALPHA_TEST_REF                   = &H00BC2
    %GL_DITHER                           = &H00BD0
    %GL_BLEND_DST                        = &H00BE0
    %GL_BLEND_SRC                        = &H00BE1
    %GL_BLEND                            = &H00BE2
    %GL_LOGIC_OP_MODE                    = &H00BF0
    %GL_INDEX_LOGIC_OP                   = &H00BF1
    %GL_LOGIC_OP                         = %GL_INDEX_LOGIC_OP
    %GL_COLOR_LOGIC_OP                   = &H00BF2
    %GL_AUX_BUFFERS                      = &H00C00
    %GL_DRAW_BUFFER                      = &H00C01
    %GL_READ_BUFFER                      = &H00C02
    %GL_SCISSOR_BOX                      = &H00C10
    %GL_SCISSOR_TEST                     = &H00C11
    %GL_INDEX_CLEAR_VALUE                = &H00C20
    %GL_INDEX_WRITEMASK                  = &H00C21
    %GL_COLOR_CLEAR_VALUE                = &H00C22
    %GL_COLOR_WRITEMASK                  = &H00C23
    %GL_INDEX_MODE                       = &H00C30
    %GL_RGBA_MODE                        = &H00C31
    %GL_DOUBLEBUFFER                     = &H00C32
    %GL_STEREO                           = &H00C33
    %GL_RENDER_MODE                      = &H00C40
    %GL_PERSPECTIVE_CORRECTION_HINT      = &H00C50
    %GL_POINT_SMOOTH_HINT                = &H00C51
    %GL_LINE_SMOOTH_HINT                 = &H00C52
    %GL_POLYGON_SMOOTH_HINT              = &H00C53
    %GL_FOG_HINT                         = &H00C54
    %GL_TEXTURE_GEN_S                    = &H00C60
    %GL_TEXTURE_GEN_T                    = &H00C61
    %GL_TEXTURE_GEN_R                    = &H00C62
    %GL_TEXTURE_GEN_Q                    = &H00C63
    %GL_PIXEL_MAP_I_TO_I_SIZE            = &H00CB0
    %GL_PIXEL_MAP_S_TO_S_SIZE            = &H00CB1
    %GL_PIXEL_MAP_I_TO_R_SIZE            = &H00CB2
    %GL_PIXEL_MAP_I_TO_G_SIZE            = &H00CB3
    %GL_PIXEL_MAP_I_TO_B_SIZE            = &H00CB4
    %GL_PIXEL_MAP_I_TO_A_SIZE            = &H00CB5
    %GL_PIXEL_MAP_R_TO_R_SIZE            = &H00CB6
    %GL_PIXEL_MAP_G_TO_G_SIZE            = &H00CB7
    %GL_PIXEL_MAP_B_TO_B_SIZE            = &H00CB8
    %GL_PIXEL_MAP_A_TO_A_SIZE            = &H00CB9
    %GL_UNPACK_SWAP_BYTES                = &H00CF0
    %GL_UNPACK_LSB_FIRST                 = &H00CF1
    %GL_UNPACK_ROW_LENGTH                = &H00CF2
    %GL_UNPACK_SKIP_ROWS                 = &H00CF3
    %GL_UNPACK_SKIP_PIXELS               = &H00CF4
    %GL_UNPACK_ALIGNMENT                 = &H00CF5
    %GL_PACK_SWAP_BYTES                  = &H00D00
    %GL_PACK_LSB_FIRST                   = &H00D01
    %GL_PACK_ROW_LENGTH                  = &H00D02
    %GL_PACK_SKIP_ROWS                   = &H00D03
    %GL_PACK_SKIP_PIXELS                 = &H00D04
    %GL_PACK_ALIGNMENT                   = &H00D05
    %GL_MAP_COLOR                        = &H00D10
    %GL_MAP_STENCIL                      = &H00D11
    %GL_INDEX_SHIFT                      = &H00D12
    %GL_INDEX_OFFSET                     = &H00D13
    %GL_RED_SCALE                        = &H00D14
    %GL_RED_BIAS                         = &H00D15
    %GL_ZOOM_X                           = &H00D16
    %GL_ZOOM_Y                           = &H00D17
    %GL_GREEN_SCALE                      = &H00D18
    %GL_GREEN_BIAS                       = &H00D19
    %GL_BLUE_SCALE                       = &H00D1A
    %GL_BLUE_BIAS                        = &H00D1B
    %GL_ALPHA_SCALE                      = &H00D1C
    %GL_ALPHA_BIAS                       = &H00D1D
    %GL_DEPTH_SCALE                      = &H00D1E
    %GL_DEPTH_BIAS                       = &H00D1F
    %GL_MAX_EVAL_ORDER                   = &H00D30
    %GL_MAX_LIGHTS                       = &H00D31
    %GL_MAX_CLIP_PLANES                  = &H00D32
    %GL_MAX_TEXTURE_SIZE                 = &H00D33
    %GL_MAX_PIXEL_MAP_TABLE              = &H00D34
    %GL_MAX_ATTRIB_STACK_DEPTH           = &H00D35
    %GL_MAX_MODELVIEW_STACK_DEPTH        = &H00D36
    %GL_MAX_NAME_STACK_DEPTH             = &H00D37
    %GL_MAX_PROJECTION_STACK_DEPTH       = &H00D38
    %GL_MAX_TEXTURE_STACK_DEPTH          = &H00D39
    %GL_MAX_VIEWPORT_DIMS                = &H00D3A
    %GL_MAX_CLIENT_ATTRIB_STACK_DEPTH    = &H00D3B
    %GL_SUBPIXEL_BITS                    = &H00D50
    %GL_INDEX_BITS                       = &H00D51
    %GL_RED_BITS                         = &H00D52
    %GL_GREEN_BITS                       = &H00D53
    %GL_BLUE_BITS                        = &H00D54
    %GL_ALPHA_BITS                       = &H00D55
    %GL_DEPTH_BITS                       = &H00D56
    %GL_STENCIL_BITS                     = &H00D57
    %GL_ACCUM_RED_BITS                   = &H00D58
    %GL_ACCUM_GREEN_BITS                 = &H00D59
    %GL_ACCUM_BLUE_BITS                  = &H00D5A
    %GL_ACCUM_ALPHA_BITS                 = &H00D5B
    %GL_NAME_STACK_DEPTH                 = &H00D70
    %GL_AUTO_NORMAL                      = &H00D80
    %GL_MAP1_COLOR_4                     = &H00D90
    %GL_MAP1_INDEX                       = &H00D91
    %GL_MAP1_NORMAL                      = &H00D92
    %GL_MAP1_TEXTURE_COORD_1             = &H00D93
    %GL_MAP1_TEXTURE_COORD_2             = &H00D94
    %GL_MAP1_TEXTURE_COORD_3             = &H00D95
    %GL_MAP1_TEXTURE_COORD_4             = &H00D96
    %GL_MAP1_VERTEX_3                    = &H00D97
    %GL_MAP1_VERTEX_4                    = &H00D98
    %GL_MAP2_COLOR_4                     = &H00DB0
    %GL_MAP2_INDEX                       = &H00DB1
    %GL_MAP2_NORMAL                      = &H00DB2
    %GL_MAP2_TEXTURE_COORD_1             = &H00DB3
    %GL_MAP2_TEXTURE_COORD_2             = &H00DB4
    %GL_MAP2_TEXTURE_COORD_3             = &H00DB5
    %GL_MAP2_TEXTURE_COORD_4             = &H00DB6
    %GL_MAP2_VERTEX_3                    = &H00DB7
    %GL_MAP2_VERTEX_4                    = &H00DB8
    %GL_MAP1_GRID_DOMAIN                 = &H00DD0
    %GL_MAP1_GRID_SEGMENTS               = &H00DD1
    %GL_MAP2_GRID_DOMAIN                 = &H00DD2
    %GL_MAP2_GRID_SEGMENTS               = &H00DD3
    %GL_TEXTURE_1D                       = &H00DE0
    %GL_TEXTURE_2D                       = &H00DE1
    %GL_FEEDBACK_BUFFER_POINTER          = &H00DF0
    %GL_FEEDBACK_BUFFER_SIZE             = &H00DF1
    %GL_FEEDBACK_BUFFER_TYPE             = &H00DF2
    %GL_SELECTION_BUFFER_POINTER         = &H00DF3
    %GL_SELECTION_BUFFER_SIZE            = &H00DF4
    %GL_POLYGON_OFFSET_UNITS             = &H02A00
    %GL_POLYGON_OFFSET_POINT             = &H02A01
    %GL_POLYGON_OFFSET_LINE              = &H02A02
    %GL_POLYGON_OFFSET_FILL              = &H08037
    %GL_POLYGON_OFFSET_FACTOR            = &H08038
    %GL_TEXTURE_BINDING_1D               = &H08068
    %GL_TEXTURE_BINDING_2D               = &H08069
    %GL_VERTEX_ARRAY                     = &H08074
    %GL_NORMAL_ARRAY                     = &H08075
    %GL_COLOR_ARRAY                      = &H08076
    %GL_INDEX_ARRAY                      = &H08077
    %GL_TEXTURE_COORD_ARRAY              = &H08078
    %GL_EDGE_FLAG_ARRAY                  = &H08079
'**      %GL_SECONDARY_COLOR_ARRAY_EXT **
    %GL_VERTEX_ARRAY_SIZE                = &H0807A
    %GL_VERTEX_ARRAY_TYPE                = &H0807B
    %GL_VERTEX_ARRAY_STRIDE              = &H0807C
    %GL_NORMAL_ARRAY_TYPE                = &H0807E
    %GL_NORMAL_ARRAY_STRIDE              = &H0807F
    %GL_COLOR_ARRAY_SIZE                 = &H08081
    %GL_COLOR_ARRAY_TYPE                 = &H08082
    %GL_COLOR_ARRAY_STRIDE               = &H08083
    %GL_INDEX_ARRAY_TYPE                 = &H08085
    %GL_INDEX_ARRAY_STRIDE               = &H08086
    %GL_TEXTURE_COORD_ARRAY_SIZE         = &H08088
    %GL_TEXTURE_COORD_ARRAY_TYPE         = &H08089
    %GL_TEXTURE_COORD_ARRAY_STRIDE       = &H0808A
    %GL_EDGE_FLAG_ARRAY_STRIDE           = &H0808C


'** GetTextureParameter **
    %GL_TEXTURE_WIDTH                    = &H01000
    %GL_TEXTURE_HEIGHT                   = &H01001
    %GL_TEXTURE_INTERNAL_FORMAT          = &H01003
    %GL_TEXTURE_COMPONENTS               = %GL_TEXTURE_INTERNAL_FORMAT
    %GL_TEXTURE_BORDER_COLOR             = &H01004
    %GL_TEXTURE_BORDER                   = &H01005
    %GL_TEXTURE_RED_SIZE                 = &H0805C
    %GL_TEXTURE_GREEN_SIZE               = &H0805D
    %GL_TEXTURE_BLUE_SIZE                = &H0805E
    %GL_TEXTURE_ALPHA_SIZE               = &H0805F
    %GL_TEXTURE_LUMINANCE_SIZE           = &H08060
    %GL_TEXTURE_INTENSITY_SIZE           = &H08061
    %GL_TEXTURE_PRIORITY                 = &H08066
    %GL_TEXTURE_RESIDENT                 = &H08067

'** HintMode **
    %GL_DONT_CARE                        = &H01100
    %GL_FASTEST                          = &H01101
    %GL_NICEST                           = &H01102

'** LightParameter **
    %GL_AMBIENT                          = &H01200
    %GL_DIFFUSE                          = &H01201
    %GL_SPECULAR                         = &H01202
    %GL_POSITION                         = &H01203
    %GL_SPOT_DIRECTION                   = &H01204
    %GL_SPOT_EXPONENT                    = &H01205
    %GL_SPOT_CUTOFF                      = &H01206
    %GL_CONSTANT_ATTENUATION             = &H01207
    %GL_LINEAR_ATTENUATION               = &H01208
    %GL_QUADRATIC_ATTENUATION            = &H01209

'** ListMode **
    %GL_COMPILE                          = &H01300
    %GL_COMPILE_AND_EXECUTE              = &H01301

'** DataType **
    %GL_BYTE                             = &H01400
    %GL_UNSIGNED_BYTE                    = &H01401
    %GL_SHORT                            = &H01402
    %GL_UNSIGNED_SHORT                   = &H01403
    %GL_INT                              = &H01404
    %GL_UNSIGNED_INT                     = &H01405
    %GL_FLOAT                            = &H01406
    %GL_2_BYTES                          = &H01407
    %GL_3_BYTES                          = &H01408
    %GL_4_BYTES                          = &H01409
    %GL_DOUBLE                           = &H0140A
    %GL_DOUBLE_EXT                       = &H0140A

'** LogicOp **
    %GL_CLEAR                            = &H01500
    %GL_AND                              = &H01501
    %GL_AND_REVERSE                      = &H01502
    %GL_COPY                             = &H01503
    %GL_AND_INVERTED                     = &H01504
    %GL_NOOP                             = &H01505
    %GL_XOR                              = &H01506
    %GL_OR                               = &H01507
    %GL_NOR                              = &H01508
    %GL_EQUIV                            = &H01509
    %GL_INVERT                           = &H0150A
    %GL_OR_REVERSE                       = &H0150B
    %GL_COPY_INVERTED                    = &H0150C
    %GL_OR_INVERTED                      = &H0150D
    %GL_NAND                             = &H0150E
    %GL_SET                              = &H0150F

'** MaterialParameter **
    %GL_EMISSION                         = &H01600
    %GL_SHININESS                        = &H01601
    %GL_AMBIENT_AND_DIFFUSE              = &H01602
    %GL_COLOR_INDEXES                    = &H01603

'** MatrixMode **
    %GL_MODELVIEW                        = &H01700
    %GL_PROJECTION                       = &H01701
    %GL_TEXTURE                          = &H01702

'** PixelCopyType **
    %GL_COLOR                            = &H01800
    %GL_DEPTH                            = &H01801
    %GL_STENCIL                          = &H01802

'** PixelFormat **
    %GL_COLOR_INDEX                      = &H01900
    %GL_STENCIL_INDEX                    = &H01901
    %GL_DEPTH_COMPONENT                  = &H01902
    %GL_RED                              = &H01903
    %GL_GREEN                            = &H01904
    %GL_BLUE                             = &H01905
    %GL_ALPHA                            = &H01906
    %GL_RGB                              = &H01907
    %GL_RGBA                             = &H01908
    %GL_LUMINANCE                        = &H01909
    %GL_LUMINANCE_ALPHA                  = &H0190A

'** PixelType **
    %GL_BITMAP                           = &H01A00


'** PolygonMode **
    %GL_POINT                            = &H01B00
    %GL_LINE                             = &H01B01
    %GL_FILL                             = &H01B02

'** RenderingMode **
    %GL_RENDER                           = &H01C00
    %GL_FEEDBACK                         = &H01C01
    %GL_SELECT                           = &H01C02

'** ShadingModel **
    %GL_FLAT                             = &H01D00
    %GL_SMOOTH                           = &H01D01

'** StencilOp **
    %GL_KEEP                             = &H01E00
    %GL_REPLACE                          = &H01E01
    %GL_INCR                             = &H01E02
    %GL_DECR                             = &H01E03

'** StringName **
    %GL_VENDOR                           = &H01F00
    %GL_RENDERER                         = &H01F01
    %GL_VERSION                          = &H01F02
    %GL_EXTENSIONS                       = &H01F03

'** TextureCoordName **
    %GL_S                                = &H02000
    %GL_T                                = &H02001
    %GL_R                                = &H02002
    %GL_Q                                = &H02003

'** TextureEnvMode **
    %GL_MODULATE                         = &H02100
    %GL_DECAL                            = &H02101


'** TextureEnvParameter **
    %GL_TEXTURE_ENV_MODE                 = &H02200
    %GL_TEXTURE_ENV_COLOR                = &H02201

'** TextureEnvTarget **
    %GL_TEXTURE_ENV                      = &H02300

'** TextureGenMode **
    %GL_EYE_LINEAR                       = &H02400
    %GL_OBJECT_LINEAR                    = &H02401
    %GL_SPHERE_MAP                       = &H02402

'** TextureGenParameter **
    %GL_TEXTURE_GEN_MODE                 = &H02500
    %GL_OBJECT_PLANE                     = &H02501
    %GL_EYE_PLANE                        = &H02502

'** TextureMagFilter **
    %GL_NEAREST                          = &H02600
    %GL_LINEAR                           = &H02601

'** TextureMinFilter **
    %GL_NEAREST_MIPMAP_NEAREST           = &H02700
    %GL_LINEAR_MIPMAP_NEAREST            = &H02701
    %GL_NEAREST_MIPMAP_LINEAR            = &H02702
    %GL_LINEAR_MIPMAP_LINEAR             = &H02703

'** TextureParameterName **
    %GL_TEXTURE_MAG_FILTER               = &H02800
    %GL_TEXTURE_MIN_FILTER               = &H02801
    %GL_TEXTURE_WRAP_S                   = &H02802
    %GL_TEXTURE_WRAP_T                   = &H02803


'** TextureTarget **
    %GL_PROXY_TEXTURE_1D                 = &H08063
    %GL_PROXY_TEXTURE_2D                 = &H08064

'** TextureWrapMode **
    %GL_CLAMP                            = &H02900
    %GL_REPEAT                           = &H02901

'** PixelInternalFormat **
    %GL_R3_G3_B2                         = &H02A10
    %GL_ALPHA4                           = &H0803B
    %GL_ALPHA8                           = &H0803C
    %GL_ALPHA12                          = &H0803D
    %GL_ALPHA16                          = &H0803E
    %GL_LUMINANCE4                       = &H0803F
    %GL_LUMINANCE8                       = &H08040
    %GL_LUMINANCE12                      = &H08041
    %GL_LUMINANCE16                      = &H08042
    %GL_LUMINANCE4_ALPHA4                = &H08043
    %GL_LUMINANCE6_ALPHA2                = &H08044
    %GL_LUMINANCE8_ALPHA8                = &H08045
    %GL_LUMINANCE12_ALPHA4               = &H08046
    %GL_LUMINANCE12_ALPHA12              = &H08047
    %GL_LUMINANCE16_ALPHA16              = &H08048
    %GL_INTENSITY                        = &H08049
    %GL_INTENSITY4                       = &H0804A
    %GL_INTENSITY8                       = &H0804B
    %GL_INTENSITY12                      = &H0804C
    %GL_INTENSITY16                      = &H0804D
    %GL_RGB4                             = &H0804F
    %GL_RGB5                             = &H08050
    %GL_RGB8                             = &H08051
    %GL_RGB10                            = &H08052
    %GL_RGB12                            = &H08053
    %GL_RGB16                            = &H08054
    %GL_RGBA2                            = &H08055
    %GL_RGBA4                            = &H08056
    %GL_RGB5_A1                          = &H08057
    %GL_RGBA8                            = &H08058
    %GL_RGB10_A2                         = &H08059
    %GL_RGBA12                           = &H0805A
    %GL_RGBA16                           = &H0805B


'** InterleavedArrayFormat **
    %GL_V2F                              = &H02A20
    %GL_V3F                              = &H02A21
    %GL_C4UB_V2F                         = &H02A22
    %GL_C4UB_V3F                         = &H02A23
    %GL_C3F_V3F                          = &H02A24
    %GL_N3F_V3F                          = &H02A25
    %GL_C4F_N3F_V3F                      = &H02A26
    %GL_T2F_V3F                          = &H02A27
    %GL_T4F_V4F                          = &H02A28
    %GL_T2F_C4UB_V3F                     = &H02A29
    %GL_T2F_C3F_V3F                      = &H02A2A
    %GL_T2F_N3F_V3F                      = &H02A2B
    %GL_T2F_C4F_N3F_V3F                  = &H02A2C
    %GL_T4F_C4F_N3F_V4F                  = &H02A2D

'** ClipPlaneName **
    %GL_CLIP_PLANE0                      = &H03000
    %GL_CLIP_PLANE1                      = &H03001
    %GL_CLIP_PLANE2                      = &H03002
    %GL_CLIP_PLANE3                      = &H03003
    %GL_CLIP_PLANE4                      = &H03004
    %GL_CLIP_PLANE5                      = &H03005

'** LightName **
    %GL_LIGHT0                           = &H04000
    %GL_LIGHT1                           = &H04001
    %GL_LIGHT2                           = &H04002
    %GL_LIGHT3                           = &H04003
    %GL_LIGHT4                           = &H04004
    %GL_LIGHT5                           = &H04005
    %GL_LIGHT6                           = &H04006
    %GL_LIGHT7                           = &H04007

'** EXT_abgr **
    %GL_ABGR_EXT                         = &H08000

'** EXT_blend_color **
    %GL_CONSTANT_COLOR_EXT               = &H08001
    %GL_ONE_MINUS_CONSTANT_COLOR_EXT     = &H08002
    %GL_CONSTANT_ALPHA_EXT               = &H08003
    %GL_ONE_MINUS_CONSTANT_ALPHA_EXT     = &H08004
    %GL_BLEND_COLOR_EXT                  = &H08005

'** EXT_blend_minmax **
    %GL_FUNC_ADD_EXT                     = &H08006
    %GL_MIN_EXT                          = &H08007
    %GL_MAX_EXT                          = &H08008
    %GL_BLEND_EQUATION_EXT               = &H08009

'** EXT_blend_subtract **
    %GL_FUNC_SUBTRACT_EXT                = &H0800A
    %GL_FUNC_REVERSE_SUBTRACT_EXT        = &H0800B

'** EXT_convolution **
    %GL_CONVOLUTION_1D_EXT               = &H08010
    %GL_CONVOLUTION_2D_EXT               = &H08011
    %GL_SEPARABLE_2D_EXT                 = &H08012
    %GL_CONVOLUTION_BORDER_MODE_EXT      = &H08013
    %GL_CONVOLUTION_FILTER_SCALE_EXT     = &H08014
    %GL_CONVOLUTION_FILTER_BIAS_EXT      = &H08015
    %GL_REDUCE_EXT                       = &H08016
    %GL_CONVOLUTION_FORMAT_EXT           = &H08017
    %GL_CONVOLUTION_WIDTH_EXT            = &H08018
    %GL_CONVOLUTION_HEIGHT_EXT           = &H08019
    %GL_MAX_CONVOLUTION_WIDTH_EXT        = &H0801A
    %GL_MAX_CONVOLUTION_HEIGHT_EXT       = &H0801B
    %GL_POST_CONVOLUTION_RED_SCALE_EXT   = &H0801C
    %GL_POST_CONVOLUTION_GREEN_SCALE_EXT = &H0801D
    %GL_POST_CONVOLUTION_BLUE_SCALE_EXT  = &H0801E
    %GL_POST_CONVOLUTION_ALPHA_SCALE_EXT = &H0801F
    %GL_POST_CONVOLUTION_RED_BIAS_EXT    = &H08020
    %GL_POST_CONVOLUTION_GREEN_BIAS_EXT  = &H08021
    %GL_POST_CONVOLUTION_BLUE_BIAS_EXT   = &H08022
    %GL_POST_CONVOLUTION_ALPHA_BIAS_EXT  = &H08023

'** EXT_histogram **
    %GL_HISTOGRAM_EXT                    = &H08024
    %GL_PROXY_HISTOGRAM_EXT              = &H08025
    %GL_HISTOGRAM_WIDTH_EXT              = &H08026
    %GL_HISTOGRAM_FORMAT_EXT             = &H08027
    %GL_HISTOGRAM_RED_SIZE_EXT           = &H08028
    %GL_HISTOGRAM_GREEN_SIZE_EXT         = &H08029
    %GL_HISTOGRAM_BLUE_SIZE_EXT          = &H0802A
    %GL_HISTOGRAM_ALPHA_SIZE_EXT         = &H0802B
    %GL_HISTOGRAM_LUMINANCE_SIZE_EXT     = &H0802C
    %GL_HISTOGRAM_SINK_EXT               = &H0802D
    %GL_MINMAX_EXT                       = &H0802E
    %GL_MINMAX_FORMAT_EXT                = &H0802F
    %GL_MINMAX_SINK_EXT                  = &H08030

'** EXT_polygon_offset **
    %GL_POLYGON_OFFSET_EXT               = &H08037
    %GL_POLYGON_OFFSET_FACTOR_EXT        = &H08038
    %GL_POLYGON_OFFSET_BIAS_EXT          = &H08039

'** EXT_packed_pixels **
    %GL_UNSIGNED_BYTE_3_3_2_EXT          = &H08032
    %GL_UNSIGNED_SHORT_4_4_4_4_EXT       = &H08033
    %GL_UNSIGNED_SHORT_5_5_5_1_EXT       = &H08034
    %GL_UNSIGNED_INT_8_8_8_8_EXT         = &H08035
    %GL_UNSIGNED_INT_10_10_10_2_EXT      = &H08036

'** EXT_vertex_array **
    %GL_VERTEX_ARRAY_EXT                 = &H08074
    %GL_NORMAL_ARRAY_EXT                 = &H08075
    %GL_COLOR_ARRAY_EXT                  = &H08076
    %GL_INDEX_ARRAY_EXT                  = &H08077
    %GL_TEXTURE_COORD_ARRAY_EXT          = &H08078
    %GL_EDGE_FLAG_ARRAY_EXT              = &H08079
    %GL_VERTEX_ARRAY_SIZE_EXT            = &H0807A
    %GL_VERTEX_ARRAY_TYPE_EXT            = &H0807B
    %GL_VERTEX_ARRAY_STRIDE_EXT          = &H0807C
    %GL_VERTEX_ARRAY_COUNT_EXT           = &H0807D
    %GL_NORMAL_ARRAY_TYPE_EXT            = &H0807E
    %GL_NORMAL_ARRAY_STRIDE_EXT          = &H0807F
    %GL_NORMAL_ARRAY_COUNT_EXT           = &H08080
    %GL_COLOR_ARRAY_SIZE_EXT             = &H08081
    %GL_COLOR_ARRAY_TYPE_EXT             = &H08082
    %GL_COLOR_ARRAY_STRIDE_EXT           = &H08083
    %GL_COLOR_ARRAY_COUNT_EXT            = &H08084
    %GL_INDEX_ARRAY_TYPE_EXT             = &H08085
    %GL_INDEX_ARRAY_STRIDE_EXT           = &H08086
    %GL_INDEX_ARRAY_COUNT_EXT            = &H08087
    %GL_TEXTURE_COORD_ARRAY_SIZE_EXT     = &H08088
    %GL_TEXTURE_COORD_ARRAY_TYPE_EXT     = &H08089
    %GL_TEXTURE_COORD_ARRAY_STRIDE_EXT   = &H0808A
    %GL_TEXTURE_COORD_ARRAY_COUNT_EXT    = &H0808B
    %GL_EDGE_FLAG_ARRAY_STRIDE_EXT       = &H0808C
    %GL_EDGE_FLAG_ARRAY_COUNT_EXT        = &H0808D
    %GL_VERTEX_ARRAY_POINTER_EXT         = &H0808E
    %GL_NORMAL_ARRAY_POINTER_EXT         = &H0808F
    %GL_COLOR_ARRAY_POINTER_EXT          = &H08090
    %GL_INDEX_ARRAY_POINTER_EXT          = &H08091
    %GL_TEXTURE_COORD_ARRAY_POINTER_EXT  = &H08092
    %GL_EDGE_FLAG_ARRAY_POINTER_EXT      = &H08093

'** EXT_color_table **
    %GL_TABLE_TOO_LARGE_EXT                     = &H08031
    %GL_COLOR_TABLE_EXT                         = &H080D0
    %GL_POST_CONVOLUTION_COLOR_TABLE_EXT        = &H080D1
    %GL_POST_COLOR_MATRIX_COLOR_TABLE_EXT       = &H080D2
    %GL_PROXY_COLOR_TABLE_EXT                   = &H080D3
    %GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_EXT  = &H080D4
    %GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_EXT = &H080D5
    %GL_COLOR_TABLE_SCALE_EXT                   = &H080D6
    %GL_COLOR_TABLE_BIAS_EXT                    = &H080D7
    %GL_COLOR_TABLE_FORMAT_EXT                  = &H080D8
    %GL_COLOR_TABLE_WIDTH_EXT                   = &H080D9
    %GL_COLOR_TABLE_RED_SIZE_EXT                = &H080DA
    %GL_COLOR_TABLE_GREEN_SIZE_EXT              = &H080DB
    %GL_COLOR_TABLE_BLUE_SIZE_EXT               = &H080DC
    %GL_COLOR_TABLE_ALPHA_SIZE_EXT              = &H080DD
    %GL_COLOR_TABLE_LUMINANCE_SIZE_EXT          = &H080DE
    %GL_COLOR_TABLE_INTENSITY_SIZE_EXT          = &H080DF

'** EXT_bgra **
    %GL_BGR_EXT                          = &H080E0
    %GL_BGRA_EXT                         = &H080E1

'** EXT_paletted_texture **
    %GL_COLOR_INDEX1_EXT                 = &H080E2
    %GL_COLOR_INDEX2_EXT                 = &H080E3
    %GL_COLOR_INDEX4_EXT                 = &H080E4
    %GL_COLOR_INDEX8_EXT                 = &H080E5
    %GL_COLOR_INDEX12_EXT                = &H080E6
    %GL_COLOR_INDEX16_EXT                = &H080E7

'** EXT_separate_specular_color **
    %GL_LIGHT_MODEL_COLOR_CONTROL_EXT    = &H081F8
    %GL_SINGLE_COLOR_EXT                 = &H081F9
    %GL_SEPARATE_SPECULAR_COLOR_EXT      = &H081FA

'** EXT_secondary_color **
    %GL_COLOR_SUM_EXT                     = &H08458
    %GL_CURRENT_SECONDARY_COLOR_EXT       = &H08459
    %GL_SECONDARY_COLOR_ARRAY_SIZE_EXT    = &H0845A
    %GL_SECONDARY_COLOR_ARRAY_TYPE_EXT    = &H0845B
    %GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT  = &H0845C
    %GL_SECONDARY_COLOR_ARRAY_POINTER_EXT = &H0845D
    %GL_SECONDARY_COLOR_ARRAY_EXT         = &H0845E

'** EXT_clip_volume_hint **
    %GL_CLIP_VOLUME_CLIPPING_HINT_EXT    = &H080F0

'** EXT_compiled_vertex_array **
    %GL_ARRAY_ELEMENT_LOCK_FIRST_EXT     = &H081A8
    %GL_ARRAY_ELEMENT_LOCK_COUNT_EXT     = &H081A9

'** EXT_cull_vertex **
    %GL_CULL_VERTEX_EXT                  = &H081AA
    %GL_CULL_VERTEX_EYE_POSITION_EXT     = &H081AB
    %GL_CULL_VERTEX_OBJECT_POSITION_EXT  = &H081AC

'*********************************************************************************
'*  OpenGL Function and Subroutine Declarations:

DECLARE SUB glAccum LIB "opengl32.dll" ALIAS "glAccum" (BYVAL op AS GLenum, BYVAL value AS GLfloat)
DECLARE SUB glAlphaFunc LIB "opengl32.dll" ALIAS "glAlphaFunc" (BYVAL func AS GLenum, BYVAL ref AS GLclampf)
DECLARE FUNCTION glAreTexturesResident LIB "opengl32.dll" ALIAS "glAreTexturesResident"_
(BYVAL n AS GLsizei, BYREF textures AS GLuint, BYREF residences AS GLboolean) AS GLboolean
DECLARE SUB glArrayElement LIB "opengl32.dll" ALIAS "glArrayElement" (BYVAL i AS GLint)
DECLARE SUB glBegin LIB "opengl32.dll" ALIAS "glBegin" (BYVAL mode AS GLenum)
DECLARE SUB glBindTexture LIB "opengl32.dll" ALIAS "glBindTexture" (BYVAL ntarget AS GLenum, BYVAL texture AS GLuint)
DECLARE SUB glBitmap LIB "opengl32.dll" ALIAS "glBitmap" (BYVAL nwidth AS GLsizei, BYVAL height AS GLsizei, _
            BYVAL xorig AS GLfloat, BYVAL yorig AS GLfloat, BYVAL xmove AS GLfloat, BYVAL ymove AS GLfloat, BYREF nbitmap AS GLubyte)
DECLARE SUB glBlendFunc LIB "opengl32.dll" ALIAS "glBlendFunc" (BYVAL sfactor AS GLenum, BYVAL dfactor AS GLenum)
DECLARE SUB glCallList LIB "opengl32.dll" ALIAS "glCallList" (BYVAL list AS GLuint)
DECLARE SUB glCallLists LIB "opengl32.dll" ALIAS "glCallLists" (BYVAL n AS GLsizei, BYVAL ntype AS GLenum, BYVAL lists AS ANY)
DECLARE SUB glClear LIB "opengl32.dll" ALIAS "glClear" (BYVAL mask AS GLbitfield)
DECLARE SUB glClearAccum LIB "opengl32.dll" ALIAS "glClearAccum" (BYVAL red AS GLfloat, BYVAL green AS GLfloat, BYVAL blue AS GLfloat, BYVAL alpha AS GLfloat)
DECLARE SUB glClearColor LIB "opengl32.dll" ALIAS "glClearColor" (BYVAL red AS GLclampf, BYVAL green AS GLclampf, BYVAL blue AS GLclampf, BYVAL alpha AS GLclampf)
DECLARE SUB glClearDepth LIB "opengl32.dll" ALIAS "glClearDepth" (BYVAL depth AS GLclampd)
DECLARE SUB glClearIndex LIB "opengl32.dll" ALIAS "glClearIndex" (BYVAL c AS GLfloat)
DECLARE SUB glClearStencil LIB "opengl32.dll" ALIAS "glClearStencil" (BYVAL s AS GLint)
DECLARE SUB glClipPlane LIB "opengl32.dll" ALIAS "glClipPlane" (BYVAL plane AS GLenum, BYREF equation AS GLdouble)
DECLARE SUB glColor3b LIB "opengl32.dll" ALIAS "glColor3b" (BYVAL red AS GLbyte, BYVAL green AS GLbyte, BYVAL blue AS GLbyte)
DECLARE SUB glColor3bv LIB "opengl32.dll" ALIAS "glColor3bv" (BYREF colorArray() AS GLbyte)
DECLARE SUB glColor3d LIB "opengl32.dll" ALIAS "glColor3d" (BYVAL red AS GLdouble, BYVAL green AS GLdouble, BYVAL blue AS GLdouble)
DECLARE SUB glColor3dv LIB "opengl32.dll" ALIAS "glColor3dv" (BYREF colorArray() AS GLdouble)
DECLARE SUB glColor3f LIB "opengl32.dll" ALIAS "glColor3f" (BYVAL red AS GLfloat, BYVAL green AS GLfloat, BYVAL blue AS GLfloat)
DECLARE SUB glColor3fv LIB "opengl32.dll" ALIAS "glColor3fv" (BYREF colorArray() AS GLFloat)
DECLARE SUB glColor3i LIB "opengl32.dll" ALIAS "glColor3i" (BYVAL red AS GLint, BYVAL green AS GLint, BYVAL blue AS GLint)
DECLARE SUB glColor3iv LIB "opengl32.dll" ALIAS "glColor3iv" (BYREF colorArray() AS GLint)
DECLARE SUB glColor3s LIB "opengl32.dll" ALIAS "glColor3s" (BYVAL red AS GLshort, BYVAL green AS GLshort, BYVAL blue AS GLshort)
DECLARE SUB glColor3sv LIB "opengl32.dll" ALIAS "glColor3sv" (BYREF colorArray() AS GLshort)
DECLARE SUB glColor3ub LIB "opengl32.dll" ALIAS "glColor3ub" (BYVAL red AS GLubyte, BYVAL green AS GLubyte, BYVAL blue AS GLubyte)
DECLARE SUB glColor3ubv LIB "opengl32.dll" ALIAS "glColor3ubv" (BYREF colorArray() AS GLubyte)
DECLARE SUB glColor3ui LIB "opengl32.dll" ALIAS "glColor3ui" (BYVAL red AS GLuint, BYVAL green AS GLuint, BYVAL blue AS GLuint)
DECLARE SUB glColor3uiv LIB "opengl32.dll" ALIAS "glColor3uiv" (BYREF colorArray() AS GLuint)
DECLARE SUB glColor3us LIB "opengl32.dll" ALIAS "glColor3us" (BYVAL red AS GLushort, BYVAL green AS GLushort, BYVAL blue AS GLushort)
DECLARE SUB glColor3usv LIB "opengl32.dll" ALIAS "glColor3usv" (BYREF colorArray() AS GLushort)
DECLARE SUB glColor4b LIB "opengl32.dll" ALIAS "glColor4b" (BYVAL red AS GLbyte, BYVAL green AS GLbyte, BYVAL blue AS GLbyte, BYVAL alpha AS GLbyte)
DECLARE SUB glColor4bv LIB "opengl32.dll" ALIAS "glColor4bv" (BYREF colorAlphaArray() AS GLbyte)
DECLARE SUB glColor4d LIB "opengl32.dll" ALIAS "glColor4d" (BYVAL red AS GLdouble, BYVAL green AS GLdouble, BYVAL blue AS GLdouble, BYVAL alpha AS GLdouble)
DECLARE SUB glColor4dv LIB "opengl32.dll" ALIAS "glColor4dv" (BYREF colorAlphaArray() AS GLdouble)
DECLARE SUB glColor4f LIB "opengl32.dll" ALIAS "glColor4f" (BYVAL red AS GLfloat, BYVAL green AS GLfloat, BYVAL blue AS GLfloat, BYVAL alpha AS GLfloat)
DECLARE SUB glColor4fv LIB "opengl32.dll" ALIAS "glColor4fv" (BYREF colorAlphaArray() AS GLfloat)
DECLARE SUB glColor4i LIB "opengl32.dll" ALIAS "glColor4i" (BYVAL red AS GLint, BYVAL green AS GLint, BYVAL blue AS GLint, BYVAL alpha AS GLint)
DECLARE SUB glColor4iv LIB "opengl32.dll" ALIAS "glColor4iv" (BYREF colorAlphaArray() AS GLint)
DECLARE SUB glColor4s LIB "opengl32.dll" ALIAS "glColor4s" (BYVAL red AS GLshort, BYVAL green AS GLshort, BYVAL blue AS GLshort, BYVAL alpha AS GLshort)
DECLARE SUB glColor4sv LIB "opengl32.dll" ALIAS "glColor4sv" (BYREF colorAlphaArray() AS GLshort)
DECLARE SUB glColor4ub LIB "opengl32.dll" ALIAS "glColor4ub" (BYVAL red AS GLubyte, BYVAL green AS GLubyte, BYVAL blue AS GLubyte, BYVAL alpha AS GLubyte)
DECLARE SUB glColor4ubv LIB "opengl32.dll" ALIAS "glColor4ubv" (BYREF colorAlphaArray() AS GLubyte)
DECLARE SUB glColor4ui LIB "opengl32.dll" ALIAS "glColor4ui" (BYVAL red AS GLuint, BYVAL green AS GLuint, BYVAL blue AS GLuint, BYVAL alpha AS GLuint)
DECLARE SUB glColor4uiv LIB "opengl32.dll" ALIAS "glColor4uiv" (BYREF colorAlphaArray() AS GLuint)
DECLARE SUB glColor4us LIB "opengl32.dll" ALIAS "glColor4us" (BYVAL red AS GLushort, BYVAL green AS GLushort, BYVAL blue AS GLushort, BYVAL alpha AS GLushort)
DECLARE SUB glColor4usv LIB "opengl32.dll" ALIAS "glColor4usv" (BYREF colorAlphaArray() AS GLushort)
DECLARE SUB glColorMask LIB "opengl32.dll" ALIAS "glColorMask" (BYVAL red AS GLboolean, BYVAL green AS GLboolean, BYVAL blue AS GLboolean, BYVAL alpha AS GLboolean)
DECLARE SUB glColorMaterial LIB "opengl32.dll" ALIAS "glColorMaterial" (BYVAL face AS GLenum, BYVAL mode AS GLenum)
DECLARE SUB glColorPointer LIB "opengl32.dll" ALIAS "glColorPointer" (BYVAL nSIZE AS GLint, BYVAL ntype AS GLenum, BYVAL stride AS GLsizei, BYval POINT AS dword)
DECLARE SUB glCopyPixels LIB "opengl32.dll" ALIAS "glCopyPixels" (BYVAL x AS GLint, BYVAL y AS GLint, BYVAL nwidth AS GLsizei, BYVAL height AS GLsizei, BYVAL ntype AS GLenum)
DECLARE SUB glCopyTexImage1D LIB "opengl32.dll" ALIAS "glCopyTexImage1D" (BYVAL ntarget AS GLenum, BYVAL level AS GLint, BYVAL internalformat AS GLenum, BYVAL x AS GLint, BYVAL y AS GLint, BYVAL nwidth AS GLsizei, BYVAL border AS GLint)
DECLARE SUB glCopyTexImage2D LIB "opengl32.dll" ALIAS "glCopyTexImage2D" (BYVAL ntarget AS GLenum, BYVAL level AS GLint, BYVAL internalformat AS GLenum, BYVAL x AS GLint, BYVAL y AS GLint, BYVAL nwidth AS GLsizei, BYVAL height AS GLsizei, BYVAL border AS _
GLint)
DECLARE SUB glCopyTexSubImage1D LIB "opengl32.dll" ALIAS "glCopyTexSubImage1D" (BYVAL ntarget AS GLenum, BYVAL level AS GLint, BYVAL xoffset AS GLint, BYVAL x AS GLint, BYVAL y AS GLint, BYVAL nwidth AS GLsizei)
DECLARE SUB glCopyTexSubImage2D LIB "opengl32.dll" ALIAS "glCopyTexSubImage2D" (BYVAL ntarget AS GLenum, BYVAL level AS GLint, BYVAL xoffset AS GLint, BYVAL yoffset AS GLint, BYVAL x AS GLint, BYVAL y AS GLint, BYVAL nwidth AS GLsizei, BYVAL height AS _
GLsizei)
DECLARE SUB glCullFace LIB "opengl32.dll" ALIAS "glCullFace" (BYVAL mode AS GLenum)
DECLARE SUB glDeleteLists LIB "opengl32.dll" ALIAS "glDeleteLists" (BYVAL list AS GLuint, BYVAL range AS GLsizei)
DECLARE SUB glDeleteTextures LIB "opengl32.dll" ALIAS "glDeleteTextures" (BYVAL n AS GLsizei, BYREF textures AS GLuint)
DECLARE SUB glDepthFunc LIB "opengl32.dll" ALIAS "glDepthFunc" (BYVAL func AS GLenum)
DECLARE SUB glDepthMask LIB "opengl32.dll" ALIAS "glDepthMask" (BYVAL flag AS GLboolean)
DECLARE SUB glDepthRange LIB "opengl32.dll" ALIAS "glDepthRange" (BYVAL zNear AS GLclampd, BYVAL zFar AS GLclampd)
DECLARE SUB glDisable LIB "opengl32.dll" ALIAS "glDisable" (BYVAL cap AS GLenum)
DECLARE SUB glDisableClientState LIB "opengl32.dll" ALIAS "glDisableClientState" (BYVAL narray AS GLenum)
DECLARE SUB glDrawArrays LIB "opengl32.dll" ALIAS "glDrawArrays" (BYVAL mode AS GLenum, BYVAL first AS GLint, BYVAL count AS GLsizei)
DECLARE SUB glDrawBuffer LIB "opengl32.dll" ALIAS "glDrawBuffer" (BYVAL mode AS GLenum)
Declare Sub glDrawElements Lib "opengl32.dll" Alias "glDrawElements" (ByVal mode As GLenum, ByVal count As GLsizei, ByVal ntype As GLenum, ByVal indices As GLpointer)
Declare Sub glDrawPixels Lib "opengl32.dll" Alias "glDrawPixels" (ByVal nwidth As GLsizei, ByVal height As GLsizei, ByVal format As GLenum, ByVal ntype As GLenum, ByVal npixels As GLpointer)
DECLARE SUB glEdgeFlag LIB "opengl32.dll" ALIAS "glEdgeFlag" (BYVAL flag AS GLboolean)
DECLARE SUB glEdgeFlagPointer LIB "opengl32.dll" ALIAS "glEdgeFlagPointer" (BYVAL stride AS GLsizei, BYREF POINT AS GLboolean)
DECLARE SUB glEdgeFlagv LIB "opengl32.dll" ALIAS "glEdgeFlagv" (BYREF flag AS GLboolean)
DECLARE SUB glEnable LIB "opengl32.dll" ALIAS "glEnable" (BYVAL cap AS GLenum)
DECLARE SUB glEnableClientState LIB "opengl32.dll" ALIAS "glEnableClientState" (BYVAL narray AS GLenum)
DECLARE SUB glEnd LIB "opengl32.dll" ALIAS "glEnd"
DECLARE SUB glEndList LIB "opengl32.dll" ALIAS "glEndList"
DECLARE SUB glEvalCoord1d LIB "opengl32.dll" ALIAS "glEvalCoord1d" (BYVAL u AS GLdouble)
DECLARE SUB glEvalCoord1dv LIB "opengl32.dll" ALIAS "glEvalCoord1dv" (BYREF u AS GLdouble)
DECLARE SUB glEvalCoord1f LIB "opengl32.dll" ALIAS "glEvalCoord1f" (BYVAL u AS GLfloat)
DECLARE SUB glEvalCoord1fv LIB "opengl32.dll" ALIAS "glEvalCoord1fv" (BYREF u AS GLfloat)
DECLARE SUB glEvalCoord2d LIB "opengl32.dll" ALIAS "glEvalCoord2d" (BYVAL u AS GLdouble, BYVAL v AS GLdouble)
DECLARE SUB glEvalCoord2dv LIB "opengl32.dll" ALIAS "glEvalCoord2dv" (BYREF u() AS GLdouble)
DECLARE SUB glEvalCoord2f LIB "opengl32.dll" ALIAS "glEvalCoord2f" (BYVAL u AS GLfloat, BYVAL v AS GLfloat)
DECLARE SUB glEvalCoord2fv LIB "opengl32.dll" ALIAS "glEvalCoord2fv" (BYREF u() AS GLfloat)
DECLARE SUB glEvalMesh1 LIB "opengl32.dll" ALIAS "glEvalMesh1" (BYVAL mode AS GLenum, BYVAL i1 AS GLint, BYVAL i2 AS GLint)
DECLARE SUB glEvalMesh2 LIB "opengl32.dll" ALIAS "glEvalMesh2" (BYVAL mode AS GLenum, BYVAL i1 AS GLint, BYVAL i2 AS GLint, BYVAL j1 AS GLint, BYVAL j2 AS GLint)
DECLARE SUB glEvalPoint1 LIB "opengl32.dll" ALIAS "glEvalPoint1" (BYVAL i AS GLint)
DECLARE SUB glEvalPoint2 LIB "opengl32.dll" ALIAS "glEvalPoint2" (BYVAL i AS GLint, BYVAL j AS GLint)
DECLARE SUB glFeedbackBuffer LIB "opengl32.dll" ALIAS "glFeedbackBuffer" (BYVAL SIZE AS GLsizei, BYVAL ntype AS GLenum, BYREF buffer AS GLfloat)
DECLARE SUB glFinish LIB "opengl32.dll" ALIAS "glFinish"
DECLARE SUB glFlush LIB "opengl32.dll" ALIAS "glFlush"
DECLARE SUB glFogf LIB "opengl32.dll" ALIAS "glFogf" (BYVAL pname AS GLenum, BYVAL param AS GLfloat)
DECLARE SUB glFogfv LIB "opengl32.dll" ALIAS "glFogfv" (BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glFogi LIB "opengl32.dll" ALIAS "glFogi" (BYVAL pname AS GLenum, BYVAL param AS GLint)
DECLARE SUB glFogiv LIB "opengl32.dll" ALIAS "glFogiv" (BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glFrontFace LIB "opengl32.dll" ALIAS "glFrontFace" (BYVAL mode AS GLenum)
DECLARE SUB glFrustum LIB "opengl32.dll" ALIAS "glFrustum" (BYVAL nleft AS GLdouble, BYVAL nright AS GLdouble, BYVAL bottom AS GLdouble, BYVAL top AS GLdouble, BYVAL zNear AS GLdouble, BYVAL zFar AS GLdouble)
DECLARE FUNCTION glGenLists LIB "opengl32.dll" ALIAS "glGenLists" (BYVAL range AS GLsizei) AS GLuint
DECLARE SUB glGenTextures LIB "opengl32.dll" ALIAS "glGenTextures" (BYVAL n AS GLsizei, BYREF textures AS GLuint)
DECLARE SUB glGetBooleanv LIB "opengl32.dll" ALIAS "glGetBooleanv" (BYVAL pname AS GLenum, BYREF params() AS GLboolean)
DECLARE SUB glGetClipPlane LIB "opengl32.dll" ALIAS "glGetClipPlane" (BYVAL plane AS GLenum, BYREF equation AS GLdouble)
DECLARE SUB glGetDoublev LIB "opengl32.dll" ALIAS "glGetDoublev" (BYVAL pname AS GLenum, BYREF params() AS GLdouble)
DECLARE FUNCTION glGetError LIB "opengl32.dll" ALIAS "glGetError" () AS GLenum
DECLARE SUB glGetFloatv LIB "opengl32.dll" ALIAS "glGetFloatv" (BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glGetIntegerv LIB "opengl32.dll" ALIAS "glGetIntegerv" (BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glGetLightfv LIB "opengl32.dll" ALIAS "glGetLightfv" (BYVAL light AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glGetLightiv LIB "opengl32.dll" ALIAS "glGetLightiv" (BYVAL light AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glGetMapdv LIB "opengl32.dll" ALIAS "glGetMapdv" (BYVAL ntarget AS GLenum, BYVAL query AS GLenum, BYREF v() AS GLdouble)
DECLARE SUB glGetMapfv LIB "opengl32.dll" ALIAS "glGetMapfv" (BYVAL ntarget AS GLenum, BYVAL query AS GLenum, BYREF v() AS GLfloat)
DECLARE SUB glGetMapiv LIB "opengl32.dll" ALIAS "glGetMapiv" (BYVAL ntarget AS GLenum, BYVAL query AS GLenum, BYREF v() AS GLint)
DECLARE SUB glGetMaterialfv LIB "opengl32.dll" ALIAS "glGetMaterialfv" (BYVAL face AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glGetMaterialiv LIB "opengl32.dll" ALIAS "glGetMaterialiv" (BYVAL face AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glGetPixelMapfv LIB "opengl32.dll" ALIAS "glGetPixelMapfv" (BYVAL map AS GLenum, BYREF values() AS GLfloat)
DECLARE SUB glGetPixelMapuiv LIB "opengl32.dll" ALIAS "glGetPixelMapuiv" (BYVAL map AS GLenum, BYREF values() AS GLuint)
DECLARE SUB glGetPixelMapusv LIB "opengl32.dll" ALIAS "glGetPixelMapusv" (BYVAL map AS GLenum, BYREF values() AS GLushort)
DECLARE SUB glGetPointerv LIB "opengl32.dll" ALIAS "glGetPointerv" (BYVAL pname AS GLenum, BYREF params() AS GLuint)
DECLARE SUB glGetPolygonStipple LIB "opengl32.dll" ALIAS "glGetPolygonStipple" (BYREF mask AS GLubyte)
DECLARE SUB glGetTexEnvfv LIB "opengl32.dll" ALIAS "glGetTexEnvfv" (BYVAL ntarget AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glGetTexEnviv LIB "opengl32.dll" ALIAS "glGetTexEnviv" (BYVAL ntarget AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glGetTexGendv LIB "opengl32.dll" ALIAS "glGetTexGendv" (BYVAL ncoord AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLdouble)
DECLARE SUB glGetTexGenfv LIB "opengl32.dll" ALIAS "glGetTexGenfv" (BYVAL ncoord AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glGetTexGeniv LIB "opengl32.dll" ALIAS "glGetTexGeniv" (BYVAL ncoord AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLint)
Declare Sub glGetTexImage Lib "opengl32.dll" Alias "glGetTexImage" (ByVal ntarget As GLenum, ByVal level As GLint, ByVal format As GLenum, ByVal ntype As GLenum, ByVal npixels As GLpointer)
DECLARE SUB glGetTexLevelParameterfv LIB "opengl32.dll" ALIAS "glGetTexLevelParameterfv" (BYVAL ntarget AS GLenum, BYVAL level AS GLint, BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glGetTexLevelParameteriv LIB "opengl32.dll" ALIAS "glGetTexLevelParameteriv" (BYVAL ntarget AS GLenum, BYVAL level AS GLint, BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glGetTexParameterfv LIB "opengl32.dll" ALIAS "glGetTexParameterfv" (BYVAL ntarget AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glGetTexParameteriv LIB "opengl32.dll" ALIAS "glGetTexParameteriv" (BYVAL ntarget AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glHint LIB "opengl32.dll" ALIAS "glHint" (BYVAL ntarget AS GLenum, BYVAL mode AS GLenum)
DECLARE SUB glIndexMask LIB "opengl32.dll" ALIAS "glIndexMask" (BYVAL mask AS GLuint)
DECLARE SUB glIndexPointer LIB "opengl32.dll" ALIAS "glIndexPointer" (BYVAL ntype AS GLenum, BYVAL stride AS GLsizei, ByVal npointer AS GLpointer)
DECLARE SUB glIndexd LIB "opengl32.dll" ALIAS "glIndexd" (BYVAL c AS GLdouble)
DECLARE SUB glIndexdv LIB "opengl32.dll" ALIAS "glIndexdv" (BYREF c AS GLdouble)
DECLARE SUB glIndexf LIB "opengl32.dll" ALIAS "glIndexf" (BYVAL c AS GLfloat)
DECLARE SUB glIndexfv LIB "opengl32.dll" ALIAS "glIndexfv" (BYREF c AS GLfloat)
DECLARE SUB glIndexi LIB "opengl32.dll" ALIAS "glIndexi" (BYVAL c AS GLint)
DECLARE SUB glIndexiv LIB "opengl32.dll" ALIAS "glIndexiv" (BYREF c AS GLint)
DECLARE SUB glIndexs LIB "opengl32.dll" ALIAS "glIndexs" (BYVAL c AS GLshort)
DECLARE SUB glIndexsv LIB "opengl32.dll" ALIAS "glIndexsv" (BYREF c AS GLshort)
DECLARE SUB glIndexub LIB "opengl32.dll" ALIAS "glIndexub" (BYVAL c AS GLubyte)
DECLARE SUB glIndexubv LIB "opengl32.dll" ALIAS "glIndexubv" (BYREF c AS GLubyte)
DECLARE SUB glInitNames LIB "opengl32.dll" ALIAS "glInitNames"
Declare Sub glInterleavedArrays Lib "opengl32.dll" Alias "glInterleavedArrays" (ByVal format As GLenum, ByVal stride As GLsizei, ByVal POINT As GLpointer)
DECLARE FUNCTION glIsEnabled LIB "opengl32.dll" ALIAS "glIsEnabled" (BYVAL cap AS GLenum) AS GLboolean
DECLARE FUNCTION glIsList LIB "opengl32.dll" ALIAS "glIsList" (BYVAL list AS GLuint) AS GLboolean
DECLARE FUNCTION glIsTexture LIB "opengl32.dll" ALIAS "glIsTexture" (BYVAL texture AS GLuint) AS GLboolean
DECLARE SUB glLightModelf LIB "opengl32.dll" ALIAS "glLightModelf" (BYVAL pname AS GLenum, BYVAL param AS GLfloat)
DECLARE SUB glLightModelfv LIB "opengl32.dll" ALIAS "glLightModelfv" (BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glLightModeli LIB "opengl32.dll" ALIAS "glLightModeli" (BYVAL pname AS GLenum, BYVAL param AS GLint)
DECLARE SUB glLightModeliv LIB "opengl32.dll" ALIAS "glLightModeliv" (BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glLightf LIB "opengl32.dll" ALIAS "glLightf" (BYVAL light AS GLenum, BYVAL pname AS GLenum, BYVAL param AS GLfloat)
DECLARE SUB glLightfv LIB "opengl32.dll" ALIAS "glLightfv" (BYVAL light AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glLighti LIB "opengl32.dll" ALIAS "glLighti" (BYVAL light AS GLenum, BYVAL pname AS GLenum, BYVAL param AS GLint)
DECLARE SUB glLightiv LIB "opengl32.dll" ALIAS "glLightiv" (BYVAL light AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glLineStipple LIB "opengl32.dll" ALIAS "glLineStipple" (BYVAL factor AS GLint, BYVAL pattern AS GLushort)
DECLARE SUB glLineWidth LIB "opengl32.dll" ALIAS "glLineWidth" (BYVAL nWIDTH AS GLfloat)
DECLARE SUB glListBase LIB "opengl32.dll" ALIAS "glListBase" (BYVAL nBASE AS GLuint)
DECLARE SUB glLoadIdentity LIB "opengl32.dll" ALIAS "glLoadIdentity"
DECLARE SUB glLoadMatrixd LIB "opengl32.dll" ALIAS "glLoadMatrixd" (BYREF m() AS GLdouble)
DECLARE SUB glLoadMatrixf LIB "opengl32.dll" ALIAS "glLoadMatrixf" (BYREF m() AS GLfloat)
DECLARE SUB glLoadName LIB "opengl32.dll" ALIAS "glLoadName" (BYVAL nNAME AS GLuint)
DECLARE SUB glLogicOp LIB "opengl32.dll" ALIAS "glLogicOp" (BYVAL opcode AS GLenum)
DECLARE SUB glMap1d LIB "opengl32.dll" ALIAS "glMap1d" (BYVAL ntarget AS GLenum, BYVAL u1 AS GLdouble, BYVAL u2 AS GLdouble, BYVAL stride AS GLint, BYVAL order AS GLint, BYREF npoints AS GLdouble)
DECLARE SUB glMap1f LIB "opengl32.dll" ALIAS "glMap1f" (BYVAL ntarget AS GLenum, BYVAL u1 AS GLfloat, BYVAL u2 AS GLfloat, BYVAL stride AS GLint, BYVAL order AS GLint, BYREF npoints AS GLfloat)
DECLARE SUB glMap2d LIB "opengl32.dll" ALIAS "glMap2d" (BYVAL ntarg AS GLenum, BYVAL u1 AS GLdouble, BYVAL u2 AS GLdouble, BYVAL ustride AS GLint, BYVAL uorder AS GLint, BYVAL v1 AS GLdouble, BYVAL v2 AS GLdouble, BYVAL vstride AS GLint, BYVAL vorder AS _
GLint, BYREF npoints AS GLdouble)
DECLARE SUB glMap2f LIB "opengl32.dll" ALIAS "glMap2f" (BYVAL ntarget AS GLenum, BYVAL u1 AS GLfloat, BYVAL u2 AS GLfloat, BYVAL ustride AS GLint, BYVAL uorder AS GLint, BYVAL v1 AS GLfloat, BYVAL v2 AS GLfloat, BYVAL vstride AS GLint, BYVAL vorder AS _
GLint, BYREF npoints AS GLfloat)
DECLARE SUB glMapGrid1d LIB "opengl32.dll" ALIAS "glMapGrid1d" (BYVAL un AS GLint, BYVAL u1 AS GLdouble, BYVAL u2 AS GLdouble)
DECLARE SUB glMapGrid1f LIB "opengl32.dll" ALIAS "glMapGrid1f" (BYVAL un AS GLint, BYVAL u1 AS GLfloat, BYVAL u2 AS GLfloat)
DECLARE SUB glMapGrid2d LIB "opengl32.dll" ALIAS "glMapGrid2d" (BYVAL un AS GLint, BYVAL u1 AS GLdouble, BYVAL u2 AS GLdouble, BYVAL vn AS GLint, BYVAL v1 AS GLdouble, BYVAL v2 AS GLdouble)
DECLARE SUB glMapGrid2f LIB "opengl32.dll" ALIAS "glMapGrid2f" (BYVAL un AS GLint, BYVAL u1 AS GLfloat, BYVAL u2 AS GLfloat, BYVAL vn AS GLint, BYVAL v1 AS GLfloat, BYVAL v2 AS GLfloat)
DECLARE SUB glMaterialf LIB "opengl32.dll" ALIAS "glMaterialf" (BYVAL face AS GLenum, BYVAL pname AS GLenum, BYVAL param AS GLfloat)
DECLARE SUB glMaterialfv LIB "opengl32.dll" ALIAS "glMaterialfv" (BYVAL face AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glMateriali LIB "opengl32.dll" ALIAS "glMateriali" (BYVAL face AS GLenum, BYVAL pname AS GLenum, BYVAL param AS GLint)
DECLARE SUB glMaterialiv LIB "opengl32.dll" ALIAS "glMaterialiv" (BYVAL face AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glMatrixMode LIB "opengl32.dll" ALIAS "glMatrixMode" (BYVAL mode AS GLenum)
DECLARE SUB glMultMatrixd LIB "opengl32.dll" ALIAS "glMultMatrixd" (BYREF m() AS GLdouble)
DECLARE SUB glMultMatrixf LIB "opengl32.dll" ALIAS "glMultMatrixf" (BYREF m() AS GLfloat)
DECLARE SUB glNewList LIB "opengl32.dll" ALIAS "glNewList" (BYVAL list AS GLuint, BYVAL mode AS GLenum)
DECLARE SUB glNormal3b LIB "opengl32.dll" ALIAS "glNormal3b" (BYVAL nx AS GLbyte, BYVAL ny AS GLbyte, BYVAL nz AS GLbyte)
DECLARE SUB glNormal3bv LIB "opengl32.dll" ALIAS "glNormal3bv" (BYREF v AS GLbyte)
DECLARE SUB glNormal3d LIB "opengl32.dll" ALIAS "glNormal3d" (BYVAL nx AS GLdouble, BYVAL ny AS GLdouble, BYVAL nz AS GLdouble)
DECLARE SUB glNormal3dv LIB "opengl32.dll" ALIAS "glNormal3dv" (BYREF v AS GLdouble)
DECLARE SUB glNormal3f LIB "opengl32.dll" ALIAS "glNormal3f" (BYVAL nx AS GLfloat, BYVAL ny AS GLfloat, BYVAL nz AS GLfloat)
DECLARE SUB glNormal3fv LIB "opengl32.dll" ALIAS "glNormal3fv" (BYREF v AS GLfloat)
DECLARE SUB glNormal3i LIB "opengl32.dll" ALIAS "glNormal3i" (BYVAL nx AS GLint, BYVAL ny AS GLint, BYVAL nz AS GLint)
DECLARE SUB glNormal3iv LIB "opengl32.dll" ALIAS "glNormal3iv" (BYREF v AS GLint)
DECLARE SUB glNormal3s LIB "opengl32.dll" ALIAS "glNormal3s" (BYVAL nx AS GLshort, BYVAL ny AS GLshort, BYVAL nz AS GLshort)
DECLARE SUB glNormal3sv LIB "opengl32.dll" ALIAS "glNormal3sv" (BYREF v AS GLshort)
Declare Sub glNormalPointer Lib "opengl32.dll" Alias "glNormalPointer" (ByVal nTYPE As GLenum, ByVal stride As GLsizei, ByVal POINT As GLpointer)
DECLARE SUB glOrtho LIB "opengl32.dll" ALIAS "glOrtho" (BYVAL nLEFT AS GLdouble, BYVAL nRIGHT AS GLdouble, BYVAL bottom AS GLdouble, BYVAL top AS GLdouble, BYVAL zNear AS GLdouble, BYVAL zFar AS GLdouble)
DECLARE SUB glPassThrough LIB "opengl32.dll" ALIAS "glPassThrough" (BYVAL token AS GLfloat)
DECLARE SUB glPixelMapfv LIB "opengl32.dll" ALIAS "glPixelMapfv" (BYVAL map AS GLenum, BYVAL mapsize AS GLint, BYREF values AS GLfloat)
DECLARE SUB glPixelMapuiv LIB "opengl32.dll" ALIAS "glPixelMapuiv" (BYVAL map AS GLenum, BYVAL mapsize AS GLint, BYREF values AS GLuint)
DECLARE SUB glPixelMapusv LIB "opengl32.dll" ALIAS "glPixelMapusv" (BYVAL map AS GLenum, BYVAL mapsize AS GLint, BYREF values AS GLushort)
DECLARE SUB glPixelStoref LIB "opengl32.dll" ALIAS "glPixelStoref" (BYVAL pname AS GLenum, BYVAL param AS GLfloat)
DECLARE SUB glPixelStorei LIB "opengl32.dll" ALIAS "glPixelStorei" (BYVAL pname AS GLenum, BYVAL param AS GLint)
DECLARE SUB glPixelTransferf LIB "opengl32.dll" ALIAS "glPixelTransferf" (BYVAL pname AS GLenum, BYVAL param AS GLfloat)
DECLARE SUB glPixelTransferi LIB "opengl32.dll" ALIAS "glPixelTransferi" (BYVAL pname AS GLenum, BYVAL param AS GLint)
DECLARE SUB glPixelZoom LIB "opengl32.dll" ALIAS "glPixelZoom" (BYVAL xfactor AS GLfloat, BYVAL yfactor AS GLfloat)
DECLARE SUB glPointSize LIB "opengl32.dll" ALIAS "glPointSize" (BYVAL SIZE AS GLfloat)
DECLARE SUB glPolygonMode LIB "opengl32.dll" ALIAS "glPolygonMode" (BYVAL face AS GLenum, BYVAL mode AS GLenum)
DECLARE SUB glPolygonOffset LIB "opengl32.dll" ALIAS "glPolygonOffset" (BYVAL factor AS GLfloat, BYVAL nUNITS AS GLfloat)
DECLARE SUB glPolygonStipple LIB "opengl32.dll" ALIAS "glPolygonStipple" (BYREF mask AS GLubyte)
DECLARE SUB glPopAttrib LIB "opengl32.dll" ALIAS "glPopAttrib"
DECLARE SUB glPopClientAttrib LIB "opengl32.dll" ALIAS "glPopClientAttrib"
DECLARE SUB glPopMatrix LIB "opengl32.dll" ALIAS "glPopMatrix"
DECLARE SUB glPopName LIB "opengl32.dll" ALIAS "glPopName"
DECLARE SUB glPrioritizeTextures LIB "opengl32.dll" ALIAS "glPrioritizeTextures" (BYVAL n AS GLsizei, BYREF textures AS GLuint, BYREF priorities AS GLclampf)
DECLARE SUB glPushAttrib LIB "opengl32.dll" ALIAS "glPushAttrib" (BYVAL mask AS GLbitfield)
DECLARE SUB glPushClientAttrib LIB "opengl32.dll" ALIAS "glPushClientAttrib" (BYVAL mask AS GLbitfield)
DECLARE SUB glPushMatrix LIB "opengl32.dll" ALIAS "glPushMatrix"
DECLARE SUB glPushName LIB "opengl32.dll" ALIAS "glPushName" (BYVAL nNAME AS GLuint)
DECLARE SUB glRasterPos2d LIB "opengl32.dll" ALIAS "glRasterPos2d" (BYVAL x AS GLdouble, BYVAL y AS GLdouble)
DECLARE SUB glRasterPos2dv LIB "opengl32.dll" ALIAS "glRasterPos2dv" (BYREF v AS GLdouble)
DECLARE SUB glRasterPos2f LIB "opengl32.dll" ALIAS "glRasterPos2f" (BYVAL x AS GLfloat, BYVAL y AS GLfloat)
DECLARE SUB glRasterPos2fv LIB "opengl32.dll" ALIAS "glRasterPos2fv" (BYREF v AS GLfloat)
DECLARE SUB glRasterPos2i LIB "opengl32.dll" ALIAS "glRasterPos2i" (BYVAL x AS GLint, BYVAL y AS GLint)
DECLARE SUB glRasterPos2iv LIB "opengl32.dll" ALIAS "glRasterPos2iv" (BYREF v AS GLint)
DECLARE SUB glRasterPos2s LIB "opengl32.dll" ALIAS "glRasterPos2s" (BYVAL x AS GLshort, BYVAL y AS GLshort)
DECLARE SUB glRasterPos2sv LIB "opengl32.dll" ALIAS "glRasterPos2sv" (BYREF v AS GLshort)
DECLARE SUB glRasterPos3d LIB "opengl32.dll" ALIAS "glRasterPos3d" (BYVAL x AS GLdouble, BYVAL y AS GLdouble, BYVAL z AS GLdouble)
DECLARE SUB glRasterPos3dv LIB "opengl32.dll" ALIAS "glRasterPos3dv" (BYREF v AS GLdouble)
DECLARE SUB glRasterPos3f LIB "opengl32.dll" ALIAS "glRasterPos3f" (BYVAL x AS GLfloat, BYVAL y AS GLfloat, BYVAL z AS GLfloat)
DECLARE SUB glRasterPos3fv LIB "opengl32.dll" ALIAS "glRasterPos3fv" (BYREF v AS GLfloat)
DECLARE SUB glRasterPos3i LIB "opengl32.dll" ALIAS "glRasterPos3i" (BYVAL x AS GLint, BYVAL y AS GLint, BYVAL z AS GLint)
DECLARE SUB glRasterPos3iv LIB "opengl32.dll" ALIAS "glRasterPos3iv" (BYREF v AS GLint)
DECLARE SUB glRasterPos3s LIB "opengl32.dll" ALIAS "glRasterPos3s" (BYVAL x AS GLshort, BYVAL y AS GLshort, BYVAL z AS GLshort)
DECLARE SUB glRasterPos3sv LIB "opengl32.dll" ALIAS "glRasterPos3sv" (BYREF v AS GLshort)
DECLARE SUB glRasterPos4d LIB "opengl32.dll" ALIAS "glRasterPos4d" (BYVAL x AS GLdouble, BYVAL y AS GLdouble, BYVAL z AS GLdouble, BYVAL w AS GLdouble)
DECLARE SUB glRasterPos4dv LIB "opengl32.dll" ALIAS "glRasterPos4dv" (BYREF v AS GLdouble)
DECLARE SUB glRasterPos4f LIB "opengl32.dll" ALIAS "glRasterPos4f" (BYVAL x AS GLfloat, BYVAL y AS GLfloat, BYVAL z AS GLfloat, BYVAL w AS GLfloat)
DECLARE SUB glRasterPos4fv LIB "opengl32.dll" ALIAS "glRasterPos4fv" (BYREF v AS GLfloat)
DECLARE SUB glRasterPos4i LIB "opengl32.dll" ALIAS "glRasterPos4i" (BYVAL x AS GLint, BYVAL y AS GLint, BYVAL z AS GLint, BYVAL w AS GLint)
DECLARE SUB glRasterPos4iv LIB "opengl32.dll" ALIAS "glRasterPos4iv" (BYREF v AS GLint)
DECLARE SUB glRasterPos4s LIB "opengl32.dll" ALIAS "glRasterPos4s" (BYVAL x AS GLshort, BYVAL y AS GLshort, BYVAL z AS GLshort, BYVAL w AS GLshort)
DECLARE SUB glRasterPos4sv LIB "opengl32.dll" ALIAS "glRasterPos4sv" (BYREF v AS GLshort)
DECLARE SUB glReadBuffer LIB "opengl32.dll" ALIAS "glReadBuffer" (BYVAL mode AS GLenum)
Declare Sub glReadPixels Lib "opengl32.dll" Alias "glReadPixels" (ByVal x As GLint, ByVal y As GLint, ByVal nWIDTH As GLsizei, ByVal height As GLsizei, ByVal format As GLenum, ByVal nTYPE As GLenum, ByVal nPIXELS As GLpointer) 
DECLARE SUB glRectd LIB "opengl32.dll" ALIAS "glRectd" (BYVAL x1 AS GLdouble, BYVAL y1 AS GLdouble, BYVAL x2 AS GLdouble, BYVAL y2 AS GLdouble)
DECLARE SUB glRectdv LIB "opengl32.dll" ALIAS "glRectdv" (BYREF v1 AS GLdouble, BYREF v2 AS GLdouble)
DECLARE SUB glRectf LIB "opengl32.dll" ALIAS "glRectf" (BYVAL x1 AS GLfloat, BYVAL y1 AS GLfloat, BYVAL x2 AS GLfloat, BYVAL y2 AS GLfloat)
DECLARE SUB glRectfv LIB "opengl32.dll" ALIAS "glRectfv" (BYREF v1 AS GLfloat, BYREF v2 AS GLfloat)
DECLARE SUB glRecti LIB "opengl32.dll" ALIAS "glRecti" (BYVAL x1 AS GLint, BYVAL y1 AS GLint, BYVAL x2 AS GLint, BYVAL y2 AS GLint)
DECLARE SUB glRectiv LIB "opengl32.dll" ALIAS "glRectiv" (BYREF v1 AS GLint, BYREF v2 AS GLint)
DECLARE SUB glRects LIB "opengl32.dll" ALIAS "glRects" (BYVAL x1 AS GLshort, BYVAL y1 AS GLshort, BYVAL x2 AS GLshort, BYVAL y2 AS GLshort)
DECLARE SUB glRectsv LIB "opengl32.dll" ALIAS "glRectsv" (BYREF v1 AS GLshort, BYREF v2 AS GLshort)
DECLARE FUNCTION glRenderMode LIB "opengl32.dll" ALIAS "glRenderMode" (BYVAL mode AS GLenum) AS GLint
DECLARE SUB glRotated LIB "opengl32.dll" ALIAS "glRotated" (BYVAL angle AS GLdouble, BYVAL x AS GLdouble, BYVAL y AS GLdouble, BYVAL z AS GLdouble)
DECLARE SUB glRotatef LIB "opengl32.dll" ALIAS "glRotatef" (BYVAL angle AS GLfloat, BYVAL x AS GLfloat, BYVAL y AS GLfloat, BYVAL z AS GLfloat)
DECLARE SUB glScaled LIB "opengl32.dll" ALIAS "glScaled" (BYVAL x AS GLdouble, BYVAL y AS GLdouble, BYVAL z AS GLdouble)
DECLARE SUB glScalef LIB "opengl32.dll" ALIAS "glScalef" (BYVAL x AS GLfloat, BYVAL y AS GLfloat, BYVAL z AS GLfloat)
DECLARE SUB glScissor LIB "opengl32.dll" ALIAS "glScissor" (BYVAL x AS GLint, BYVAL y AS GLint, BYVAL nWIDTH AS GLsizei, BYVAL height AS GLsizei)
DECLARE SUB glSelectBuffer LIB "opengl32.dll" ALIAS "glSelectBuffer" (BYVAL SIZE AS GLsizei, BYREF buffer AS GLuint)
DECLARE SUB glShadeModel LIB "opengl32.dll" ALIAS "glShadeModel" (BYVAL mode AS GLenum)
DECLARE SUB glStencilFunc LIB "opengl32.dll" ALIAS "glStencilFunc" (BYVAL func AS GLenum, BYVAL ref AS GLint, BYVAL mask AS GLuint)
DECLARE SUB glStencilMask LIB "opengl32.dll" ALIAS "glStencilMask" (BYVAL mask AS GLuint)
DECLARE SUB glStencilOp LIB "opengl32.dll" ALIAS "glStencilOp" (BYVAL fail AS GLenum, BYVAL zfail AS GLenum, BYVAL zpass AS GLenum)
DECLARE SUB glTexCoord1d LIB "opengl32.dll" ALIAS "glTexCoord1d" (BYVAL s AS GLdouble)
DECLARE SUB glTexCoord1dv LIB "opengl32.dll" ALIAS "glTexCoord1dv" (BYREF v AS GLdouble)
DECLARE SUB glTexCoord1f LIB "opengl32.dll" ALIAS "glTexCoord1f" (BYVAL s AS GLfloat)
DECLARE SUB glTexCoord1fv LIB "opengl32.dll" ALIAS "glTexCoord1fv" (BYREF v AS GLfloat)
DECLARE SUB glTexCoord1i LIB "opengl32.dll" ALIAS "glTexCoord1i" (BYVAL s AS GLint)
DECLARE SUB glTexCoord1iv LIB "opengl32.dll" ALIAS "glTexCoord1iv" (BYREF v AS GLint)
DECLARE SUB glTexCoord1s LIB "opengl32.dll" ALIAS "glTexCoord1s" (BYVAL s AS GLshort)
DECLARE SUB glTexCoord1sv LIB "opengl32.dll" ALIAS "glTexCoord1sv" (BYREF v AS GLshort)
DECLARE SUB glTexCoord2d LIB "opengl32.dll" ALIAS "glTexCoord2d" (BYVAL s AS GLdouble, BYVAL t AS GLdouble)
DECLARE SUB glTexCoord2dv LIB "opengl32.dll" ALIAS "glTexCoord2dv" (BYREF v AS GLdouble)
DECLARE SUB glTexCoord2f LIB "opengl32.dll" ALIAS "glTexCoord2f" (BYVAL s AS GLfloat, BYVAL t AS GLfloat)
DECLARE SUB glTexCoord2fv LIB "opengl32.dll" ALIAS "glTexCoord2fv" (BYREF v AS GLfloat)
DECLARE SUB glTexCoord2i LIB "opengl32.dll" ALIAS "glTexCoord2i" (BYVAL s AS GLint, BYVAL t AS GLint)
DECLARE SUB glTexCoord2iv LIB "opengl32.dll" ALIAS "glTexCoord2iv" (BYREF v AS GLint)
DECLARE SUB glTexCoord2s LIB "opengl32.dll" ALIAS "glTexCoord2s" (BYVAL s AS GLshort, BYVAL t AS GLshort)
DECLARE SUB glTexCoord2sv LIB "opengl32.dll" ALIAS "glTexCoord2sv" (BYREF v AS GLshort)
DECLARE SUB glTexCoord3d LIB "opengl32.dll" ALIAS "glTexCoord3d" (BYVAL s AS GLdouble, BYVAL t AS GLdouble, BYVAL r AS GLdouble)
DECLARE SUB glTexCoord3dv LIB "opengl32.dll" ALIAS "glTexCoord3dv" (BYREF v AS GLdouble)
DECLARE SUB glTexCoord3f LIB "opengl32.dll" ALIAS "glTexCoord3f" (BYVAL s AS GLfloat, BYVAL t AS GLfloat, BYVAL r AS GLfloat)
DECLARE SUB glTexCoord3fv LIB "opengl32.dll" ALIAS "glTexCoord3fv" (BYREF v AS GLfloat)
DECLARE SUB glTexCoord3i LIB "opengl32.dll" ALIAS "glTexCoord3i" (BYVAL s AS GLint, BYVAL t AS GLint, BYVAL r AS GLint)
DECLARE SUB glTexCoord3iv LIB "opengl32.dll" ALIAS "glTexCoord3iv" (BYREF v AS GLint)
DECLARE SUB glTexCoord3s LIB "opengl32.dll" ALIAS "glTexCoord3s" (BYVAL s AS GLshort, BYVAL t AS GLshort, BYVAL r AS GLshort)
DECLARE SUB glTexCoord3sv LIB "opengl32.dll" ALIAS "glTexCoord3sv" (BYREF v AS GLshort)
DECLARE SUB glTexCoord4d LIB "opengl32.dll" ALIAS "glTexCoord4d" (BYVAL s AS GLdouble, BYVAL t AS GLdouble, BYVAL r AS GLdouble, BYVAL q AS GLdouble)
DECLARE SUB glTexCoord4dv LIB "opengl32.dll" ALIAS "glTexCoord4dv" (BYREF v AS GLdouble)
DECLARE SUB glTexCoord4f LIB "opengl32.dll" ALIAS "glTexCoord4f" (BYVAL s AS GLfloat, BYVAL t AS GLfloat, BYVAL r AS GLfloat, BYVAL q AS GLfloat)
DECLARE SUB glTexCoord4fv LIB "opengl32.dll" ALIAS "glTexCoord4fv" (BYREF v AS GLfloat)
DECLARE SUB glTexCoord4i LIB "opengl32.dll" ALIAS "glTexCoord4i" (BYVAL s AS GLint, BYVAL t AS GLint, BYVAL r AS GLint, BYVAL q AS GLint)
DECLARE SUB glTexCoord4iv LIB "opengl32.dll" ALIAS "glTexCoord4iv" (BYREF v AS GLint)
DECLARE SUB glTexCoord4s LIB "opengl32.dll" ALIAS "glTexCoord4s" (BYVAL s AS GLshort, BYVAL t AS GLshort, BYVAL r AS GLshort, BYVAL q AS GLshort)
DECLARE SUB glTexCoord4sv LIB "opengl32.dll" ALIAS "glTexCoord4sv" (BYREF v AS GLshort)
DECLARE SUB glTexCoordPointer LIB "opengl32.dll" ALIAS "glTexCoordPointer" (BYVAL SIZE AS GLint, BYVAL nTYPE AS GLenum, BYVAL stride AS GLsizei, ByVal POINT AS GLpointer)
DECLARE SUB glTexEnvf LIB "opengl32.dll" ALIAS "glTexEnvf" (BYVAL ntarget AS GLenum, BYVAL pname AS GLenum, BYVAL param AS GLfloat)
DECLARE SUB glTexEnvfv LIB "opengl32.dll" ALIAS "glTexEnvfv" (BYVAL ntarget AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glTexEnvi LIB "opengl32.dll" ALIAS "glTexEnvi" (BYVAL ntarget AS GLenum, BYVAL pname AS GLenum, BYVAL param AS GLint)
DECLARE SUB glTexEnviv LIB "opengl32.dll" ALIAS "glTexEnviv" (BYVAL ntarget AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glTexGend LIB "opengl32.dll" ALIAS "glTexGend" (BYVAL ncoord AS GLenum, BYVAL pname AS GLenum, BYVAL param AS GLdouble)
DECLARE SUB glTexGendv LIB "opengl32.dll" ALIAS "glTexGendv" (BYVAL ncoord AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLdouble)
DECLARE SUB glTexGenf LIB "opengl32.dll" ALIAS "glTexGenf" (BYVAL ncoord AS GLenum, BYVAL pname AS GLenum, BYVAL param AS GLfloat)
DECLARE SUB glTexGenfv LIB "opengl32.dll" ALIAS "glTexGenfv" (BYVAL ncoord AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glTexGeni LIB "opengl32.dll" ALIAS "glTexGeni" (BYVAL ncoord AS GLenum, BYVAL pname AS GLenum, BYVAL param AS GLint)
DECLARE SUB glTexGeniv LIB "opengl32.dll" ALIAS "glTexGeniv" (BYVAL ncoord AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glTexImage1D LIB "opengl32.dll" ALIAS "glTexImage1D" (BYVAL ntarget AS GLenum, BYVAL level AS GLint, BYVAL components AS GLint, BYVAL nWIDTH AS GLsizei, BYVAL border AS GLint, BYVAL format AS GLenum, BYVAL nTYP AS GLenum, ByVal nPIX AS GLpointer)
DECLARE SUB glTexImage2D LIB "opengl32.dll" ALIAS "glTexImage2D" (BYVAL ntarget AS GLenum, BYVAL level AS GLint, BYVAL components AS GLint, BYVAL nWIDTH AS GLsizei, BYVAL height AS GLsizei, BYVAL border AS GLint, BYVAL format AS GLenum, BYVAL nTYPE AS _
GLenum, ByVal nPIXELS AS GLpointer)
DECLARE SUB glTexParameterf LIB "opengl32.dll" ALIAS "glTexParameterf" (BYVAL ntarget AS GLenum, BYVAL pname AS GLenum, BYVAL param AS GLfloat)
DECLARE SUB glTexParameterfv LIB "opengl32.dll" ALIAS "glTexParameterfv" (BYVAL ntarget AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLfloat)
DECLARE SUB glTexParameteri LIB "opengl32.dll" ALIAS "glTexParameteri" (BYVAL ntarget AS GLenum, BYVAL pname AS GLenum, BYVAL param AS GLint)
DECLARE SUB glTexParameteriv LIB "opengl32.dll" ALIAS "glTexParameteriv" (BYVAL ntarget AS GLenum, BYVAL pname AS GLenum, BYREF params() AS GLint)
DECLARE SUB glTexSubImage1D LIB "opengl32.dll" ALIAS "glTexSubImage1D" (BYVAL ntarget AS GLenum, BYVAL level AS GLint, BYVAL xoffset AS GLint, BYVAL nWIDTH AS GLsizei, BYVAL format AS GLenum, BYVAL nTYPE AS GLenum, ByVal nPIXELS AS GLpointer)
DECLARE SUB glTexSubImage2D LIB "opengl32.dll" ALIAS "glTexSubImage2D" (BYVAL ntarg AS GLenum, BYVAL level AS GLint, BYVAL xoffset AS GLint, BYVAL yoffset AS GLint, BYVAL nWIDTH AS GLsizei, BYVAL height AS GLsizei, BYVAL format AS GLenum, BYVAL nTYPE AS _
GLenum, ByVal nPIXELS As GLpointer)
DECLARE SUB glTranslated LIB "opengl32.dll" ALIAS "glTranslated" (BYVAL x AS GLdouble, BYVAL y AS GLdouble, BYVAL z AS GLdouble)
DECLARE SUB glTranslatef LIB "opengl32.dll" ALIAS "glTranslatef" (BYVAL x AS GLfloat, BYVAL y AS GLfloat, BYVAL z AS GLfloat)
DECLARE SUB glVertex2d LIB "opengl32.dll" ALIAS "glVertex2d" (BYVAL x AS GLdouble, BYVAL y AS GLdouble)
DECLARE SUB glVertex2dv LIB "opengl32.dll" ALIAS "glVertex2dv" (BYREF v() AS GLdouble)
DECLARE SUB glVertex2f LIB "opengl32.dll" ALIAS "glVertex2f" (BYVAL x AS GLfloat, BYVAL y AS GLfloat)
DECLARE SUB glVertex2fv LIB "opengl32.dll" ALIAS "glVertex2fv" (BYREF v() AS GLfloat)
DECLARE SUB glVertex2i LIB "opengl32.dll" ALIAS "glVertex2i" (BYVAL x AS GLint, BYVAL y AS GLint)
DECLARE SUB glVertex2iv LIB "opengl32.dll" ALIAS "glVertex2iv" (BYREF v() AS GLint)
DECLARE SUB glVertex2s LIB "opengl32.dll" ALIAS "glVertex2s" (BYVAL x AS GLshort, BYVAL y AS GLshort)
DECLARE SUB glVertex2sv LIB "opengl32.dll" ALIAS "glVertex2sv" (BYREF v() AS GLshort)
DECLARE SUB glVertex3d LIB "opengl32.dll" ALIAS "glVertex3d" (BYVAL x AS GLdouble, BYVAL y AS GLdouble, BYVAL z AS GLdouble)
DECLARE SUB glVertex3dv LIB "opengl32.dll" ALIAS "glVertex3dv" (BYREF v() AS GLdouble)
DECLARE SUB glVertex3f LIB "opengl32.dll" ALIAS "glVertex3f" (BYVAL x AS GLfloat, BYVAL y AS GLfloat, BYVAL z AS GLfloat)
DECLARE SUB glVertex3fv LIB "opengl32.dll" ALIAS "glVertex3fv" (BYREF v() AS GLfloat)
DECLARE SUB glVertex3i LIB "opengl32.dll" ALIAS "glVertex3i" (BYVAL x AS GLint, BYVAL y AS GLint, BYVAL z AS GLint)
DECLARE SUB glVertex3iv LIB "opengl32.dll" ALIAS "glVertex3iv" (BYREF v() AS GLint)
DECLARE SUB glVertex3s LIB "opengl32.dll" ALIAS "glVertex3s" (BYVAL x AS GLshort, BYVAL y AS GLshort, BYVAL z AS GLshort)
DECLARE SUB glVertex3sv LIB "opengl32.dll" ALIAS "glVertex3sv" (BYREF v() AS GLshort)
DECLARE SUB glVertex4d LIB "opengl32.dll" ALIAS "glVertex4d" (BYVAL x AS GLdouble, BYVAL y AS GLdouble, BYVAL z AS GLdouble, BYVAL w AS GLdouble)
DECLARE SUB glVertex4dv LIB "opengl32.dll" ALIAS "glVertex4dv" (BYREF v() AS GLdouble)
DECLARE SUB glVertex4f LIB "opengl32.dll" ALIAS "glVertex4f" (BYVAL x AS GLfloat, BYVAL y AS GLfloat, BYVAL z AS GLfloat, BYVAL w AS GLfloat)
DECLARE SUB glVertex4fv LIB "opengl32.dll" ALIAS "glVertex4fv" (BYREF v() AS GLfloat)
DECLARE SUB glVertex4i LIB "opengl32.dll" ALIAS "glVertex4i" (BYVAL x AS GLint, BYVAL y AS GLint, BYVAL z AS GLint, BYVAL w AS GLint)
DECLARE SUB glVertex4iv LIB "opengl32.dll" ALIAS "glVertex4iv" (BYREF v() AS GLint)
DECLARE SUB glVertex4s LIB "opengl32.dll" ALIAS "glVertex4s" (BYVAL x AS GLshort, BYVAL y AS GLshort, BYVAL z AS GLshort, BYVAL w AS GLshort)
DECLARE SUB glVertex4sv LIB "opengl32.dll" ALIAS "glVertex4sv" (BYREF v() AS GLshort)
Declare Sub glVertexPointer Lib "opengl32.dll" Alias "glVertexPointer" (ByVal Size As GLint, ByVal nTYPE As GLenum, ByVal stride As GLsizei, ByVal POINT As GLpointer)
DECLARE SUB glViewport LIB "opengl32.dll" ALIAS "glViewport" (BYVAL x AS GLint, BYVAL y AS GLint, BYVAL nWIDTH AS GLsizei, BYVAL height AS GLsizei)
DECLARE FUNCTION glGetString LIB "opengl32.dll" ALIAS "glGetString" (BYVAL nname AS GLuint) AS GLuint
