  '*********************************************************
  '*             OpenGL "glu.h" for thinBASIC              *
  '*                                                       *
  '*              based on work of Sublevel6               *
  '*          thinBASIC version by Petr Schreiber          *
  '*                                                       *
  '*              Release 15th September 2008              *
  '*********************************************************

#INCLUDE ONCE "%APP_INCLUDEPATH%\thinbasic_gl.inc"

%GLU_VERSION_1_1                 = 1
%GLU_VERSION_1_2                 = 1

%GLU_INVALID_ENUM                = 100900
%GLU_INVALID_VALUE               = 100901
%GLU_OUT_OF_MEMORY               = 100902
%GLU_INCOMPATIBLE_GL_VERSION     = 100903

%GLU_VERSION                     = 100800
%GLU_EXTENSIONS                  = 100801

%GLU_TRUE                        = %GL_TRUE
%GLU_FALSE                       = %GL_FALSE

%GLU_SMOOTH                      = 100000
%GLU_FLAT                        = 100001
%GLU_NONE                        = 100002

%GLU_POINT                       = 100010
%GLU_LINE                        = 100011
%GLU_FILL                        = 100012
%GLU_SILHOUETTE                  = 100013

%GLU_OUTSIDE                     = 100020
%GLU_INSIDE                      = 100021

GLOBAL %GLU_TESS_MAX_COORD AS EXT = 10^150

%GLU_TESS_WINDING_RULE           = 100140
%GLU_TESS_BOUNDARY_ONLY          = 100141
%GLU_TESS_TOLERANCE              = 100142

%GLU_TESS_WINDING_ODD            = 100130
%GLU_TESS_WINDING_NONZERO        = 100131
%GLU_TESS_WINDING_POSITIVE       = 100132
%GLU_TESS_WINDING_NEGATIVE       = 100133
%GLU_TESS_WINDING_ABS_GEQ_TWO    = 100134

%GLU_TESS_BEGIN                  = 100100
%GLU_TESS_VERTEX                 = 100101
%GLU_TESS_END                    = 100102
%GLU_TESS_ERROR                  = 100103
%GLU_TESS_EDGE_FLAG              = 100104
%GLU_TESS_COMBINE                = 100105

%GLU_TESS_BEGIN_DATA             = 100106

%GLU_TESS_VERTEX_DATA            = 100107

%GLU_TESS_END_DATA               = 100108
%GLU_TESS_ERROR_DATA             = 100109

%GLU_TESS_EDGE_FLAG_DATA         = 100110

%GLU_TESS_COMBINE_DATA           = 100111

%GLU_TESS_ERROR1                 = 100151
%GLU_TESS_ERROR2                 = 100152
%GLU_TESS_ERROR3                 = 100153
%GLU_TESS_ERROR4                 = 100154
%GLU_TESS_ERROR5                 = 100155
%GLU_TESS_ERROR6                 = 100156
%GLU_TESS_ERROR7                 = 100157
%GLU_TESS_ERROR8                 = 100158

%GLU_TESS_MISSING_BEGIN_POLYGON  = %GLU_TESS_ERROR1
%GLU_TESS_MISSING_BEGIN_CONTOUR  = %GLU_TESS_ERROR2
%GLU_TESS_MISSING_END_POLYGON    = %GLU_TESS_ERROR3
%GLU_TESS_MISSING_END_CONTOUR    = %GLU_TESS_ERROR4
%GLU_TESS_COORD_TOO_LARGE        = %GLU_TESS_ERROR5
%GLU_TESS_NEED_COMBINE_CALLBACK  = %GLU_TESS_ERROR6

%GLU_AUTO_LOAD_MATRIX            = 100200
%GLU_CULLING                     = 100201
%GLU_SAMPLING_TOLERANCE          = 100203
%GLU_DISPLAY_MODE                = 100204
%GLU_PARAMETRIC_TOLERANCE        = 100202
%GLU_SAMPLING_METHOD             = 100205
%GLU_U_STEP                      = 100206
%GLU_V_STEP                      = 100207

%GLU_PATH_LENGTH                 = 100215
%GLU_PARAMETRIC_ERROR            = 100216
%GLU_DOMAIN_DISTANCE             = 100217

%GLU_MAP1_TRIM_2                 = 100210
%GLU_MAP1_TRIM_3                 = 100211

%GLU_OUTLINE_POLYGON             = 100240
%GLU_OUTLINE_PATCH               = 100241

%GLU_NURBS_ERROR1                = 100251
%GLU_NURBS_ERROR2                = 100252
%GLU_NURBS_ERROR3                = 100253
%GLU_NURBS_ERROR4                = 100254
%GLU_NURBS_ERROR5                = 100255
%GLU_NURBS_ERROR6                = 100256
%GLU_NURBS_ERROR7                = 100257
%GLU_NURBS_ERROR8                = 100258
%GLU_NURBS_ERROR9                = 100259
%GLU_NURBS_ERROR10               = 100260
%GLU_NURBS_ERROR11               = 100261
%GLU_NURBS_ERROR12               = 100262
%GLU_NURBS_ERROR13               = 100263
%GLU_NURBS_ERROR14               = 100264
%GLU_NURBS_ERROR15               = 100265
%GLU_NURBS_ERROR16               = 100266
%GLU_NURBS_ERROR17               = 100267
%GLU_NURBS_ERROR18               = 100268
%GLU_NURBS_ERROR19               = 100269
%GLU_NURBS_ERROR20               = 100270
%GLU_NURBS_ERROR21               = 100271
%GLU_NURBS_ERROR22               = 100272
%GLU_NURBS_ERROR23               = 100273
%GLU_NURBS_ERROR24               = 100274
%GLU_NURBS_ERROR25               = 100275
%GLU_NURBS_ERROR26               = 100276
%GLU_NURBS_ERROR27               = 100277
%GLU_NURBS_ERROR28               = 100278
%GLU_NURBS_ERROR29               = 100279
%GLU_NURBS_ERROR30               = 100280
%GLU_NURBS_ERROR31               = 100281
%GLU_NURBS_ERROR32               = 100282
%GLU_NURBS_ERROR33               = 100283
%GLU_NURBS_ERROR34               = 100284
%GLU_NURBS_ERROR35               = 100285
%GLU_NURBS_ERROR36               = 100286
%GLU_NURBS_ERROR37               = 100287


%GLU_CW                          = 100120
%GLU_CCW                         = 100121
%GLU_INTERIOR                    = 100122
%GLU_EXTERIOR                    = 100123
%GLU_UNKNOWN                     = 100124

%GLU_BEGIN                       = %GLU_TESS_BEGIN
%GLU_VERTEX                      = %GLU_TESS_VERTEX
%GLU_END                         = %GLU_TESS_END
%GLU_ERROR                       = %GLU_TESS_ERROR
%GLU_EDGE_FLAG                   = %GLU_TESS_EDGE_FLAG


DECLARE FUNCTION gluErrorString      LIB "glu32.dll" ALIAS "gluErrorString"          (BYVAL errCode AS DWORD) AS LONG
DECLARE FUNCTION gluGetString        LIB "glu32.dll" ALIAS "gluGetString"            (BYVAL nname AS DWORD) AS LONG
DECLARE SUB gluOrtho2D               LIB "glu32.dll" ALIAS "gluOrtho2D"              (BYVAL nleft AS GLDouble, BYVAL nright AS GLDouble, BYVAL nbottom AS GLDouble, BYVAL ntop AS GLDouble)
DECLARE SUB gluPerspective           LIB "glu32.dll" ALIAS "gluPerspective"          (BYVAL fovy AS GLDouble, BYVAL aspect AS GLDouble, BYVAL zNear AS GLDouble, BYVAL zFar AS GLDouble)
DECLARE SUB gluPickMatrix            LIB "glu32.dll" ALIAS "gluPickMatrix"           (BYVAL x AS GLDouble, BYVAL y AS GLDouble, BYVAL nwidth AS GLDouble, BYVAL nheight AS GLDouble, BYREF viewport() AS GLInt)
DECLARE SUB gluLookAt                LIB "glu32.dll" ALIAS "gluLookAt"               (BYVAL eyex AS GLDouble, BYVAL eyey AS GLDouble, BYVAL eyez AS GLDouble, _
                                                                                      BYVAL centerx AS GLDouble, BYVAL centery AS GLDouble, BYVAL centerz AS GLDouble, _
                                                                                      BYVAL upx AS GLDouble,BYVAL upy AS GLDouble, BYVAL upz AS GLDouble)

DECLARE FUNCTION gluProject          LIB "glu32.dll" ALIAS "gluProject"              (BYVAL objx AS GLDouble, BYVAL objy AS GLDouble, BYVAL objz AS GLDouble, _
                                                                                      BYREF modelMatrix() AS GLDouble, BYREF projMatrix() AS GLDouble, BYREF viewport AS GLInt, _
                                                                                      BYREF winx AS GLDouble, BYREF winy AS GLDouble, BYREF winz AS GLDouble) AS LONG

DECLARE FUNCTION gluUnProject LIB "glu32.dll" ALIAS "gluUnProject"                  (BYVAL winx AS GLDouble, BYVAL winy AS GLDouble, BYVAL winz AS GLDouble, _
                                                                                     BYREF modelMatrix() AS GLDouble, BYREF projMatrix() AS GLDouble, BYREF viewport AS GLInt, _
                                                                                     BYREF objx AS GLDouble, BYREF objy AS GLDouble, BYREF objz AS GLDouble) AS LONG

DECLARE FUNCTION gluScaleImage       LIB "glu32.dll" ALIAS "gluScaleImage"           (BYVAL nformat AS DWORD, BYVAL widthin AS GLInt, BYVAL heightin AS GLInt, BYVAL typein AS GLEnum, BYVAL bydatain AS GLEnum, _
                                                                                      BYVAL widthout AS GLInt, BYVAL heightout AS GLInt, BYVAL typeout AS GLEnum, BYVAL dataout AS GLEnum) AS LONG
DECLARE FUNCTION gluBuild1DMipmaps   LIB "glu32.dll" ALIAS "gluBuild1DMipmaps"       (BYVAL ntarget AS DWORD, BYVAL components AS GLInt, BYVAL nwidth AS GLInt, BYVAL nformat AS GLEnum, BYVAL ntype AS GLEnum, BYVAL ndata AS GLEnum) AS LONG
DECLARE FUNCTION gluBuild2DMipmaps   LIB "glu32.dll" ALIAS "gluBuild2DMipmaps"       (BYVAL ntarget AS DWORD, BYVAL components AS GLInt, BYVAL nwidth AS GLInt, BYVAL nheight AS GLInt, BYVAL nformat AS GLEnum, BYVAL ntype AS GLEnum, _
                                                                                      BYVAL byvndata AS GLEnum) AS LONG
DECLARE FUNCTION gluNewQuadric       LIB "glu32.dll" ALIAS "gluNewQuadric"           () AS LONG
DECLARE SUB gluDeleteQuadric         LIB "glu32.dll" ALIAS "gluDeleteQuadric"        (BYVAL quadObject AS DWORD)
DECLARE SUB gluQuadricNormals        LIB "glu32.dll" ALIAS "gluQuadricNormals"       (BYVAL quadObject AS DWORD, BYVAL normals AS GLEnum)
DECLARE SUB gluQuadricTexture        LIB "glu32.dll" ALIAS "gluQuadricTexture"       (BYVAL quadObject AS DWORD, BYVAL textureCoords AS GLBoolean)
DECLARE SUB gluQuadricOrientation    LIB "glu32.dll" ALIAS "gluQuadricOrientation"   (BYVAL quadObject AS DWORD, BYVAL orientation AS GLEnum)
DECLARE SUB gluQuadricDrawStyle      LIB "glu32.dll" ALIAS "gluQuadricDrawStyle"     (BYVAL quadObject AS DWORD, BYVAL drawStyle AS GLEnum)
DECLARE SUB gluCylinder              LIB "glu32.dll" ALIAS "gluCylinder"             (BYVAL qobj AS DWORD, BYVAL baseRadius AS GLDouble, BYVAL topRadius AS GLDouble, BYVAL nheight AS GLDouble, BYVAL slices AS GLInt, BYVAL stacks AS GLInt)
DECLARE SUB gluDisk                  LIB "glu32.dll" ALIAS "gluDisk"                 (BYVAL qobj AS DWORD, BYVAL innerRadius AS GLDouble, BYVAL outerRadius AS GLDouble, BYVAL slices AS GLInt, BYVAL loops AS GLInt)
DECLARE SUB gluPartialDisk           LIB "glu32.dll" ALIAS "gluPartialDisk"          (BYVAL qobj AS DWORD, BYVAL innerRadius AS GLDouble, BYVAL outerRadius AS GLDouble,_
                                                                                      BYVAL slices AS GLInt, BYVAL loops AS GLInt, BYVAL startAngle AS GLDouble, BYVAL sweepAngle AS GLDouble)
DECLARE SUB gluSphere                LIB "glu32.dll" ALIAS "gluSphere"               (BYVAL qobj AS DWORD, BYVAL radius AS GLDouble, BYVAL slices AS GLInt, BYVAL stacks AS GLInt)
DECLARE SUB gluQuadricCallback       LIB "glu32.dll" ALIAS "gluQuadricCallback"      (BYVAL qobj AS DWORD, BYVAL which AS GLEnum, BYVAL nfn AS GLEnum)
DECLARE FUNCTION gluNewTess          LIB "glu32.dll" ALIAS "gluNewTess"              () AS DWORD
DECLARE SUB gluDeleteTess            LIB "glu32.dll" ALIAS "gluDeleteTess"           (BYVAL tess AS DWORD)
DECLARE SUB gluTessBeginPolygon      LIB "glu32.dll" ALIAS "gluTessBeginPolygon"     (BYVAL tess AS DWORD, BYVAL polygon_data AS DWORD)
DECLARE SUB gluTessBeginContour      LIB "glu32.dll" ALIAS "gluTessBeginContour"     (BYVAL tess AS DWORD)
DECLARE SUB gluTessVertex            LIB "glu32.dll" ALIAS "gluTessVertex"           (BYVAL tess AS DWORD, BYREF coords() AS GLDouble, BYVAL ndata AS GLEnum)
DECLARE SUB gluTessEndContour        LIB "glu32.dll" ALIAS "gluTessEndContour"       (BYVAL tess AS DWORD)
DECLARE SUB gluTessEndPolygon        LIB "glu32.dll" ALIAS "gluTessEndPolygon"       (BYVAL tess AS DWORD)
DECLARE SUB gluTessProperty          LIB "glu32.dll" ALIAS "gluTessProperty"         (BYVAL tess AS DWORD, BYVAL which AS GLEnum, BYVAL value AS GLDouble)
DECLARE SUB gluTessNormal            LIB "glu32.dll" ALIAS "gluTessNormal"           (BYVAL tess AS DWORD, BYVAL x AS GLDouble, BYVAL y AS GLDouble, BYVAL z AS GLDouble)
DECLARE SUB gluTessCallback          LIB "glu32.dll" ALIAS "gluTessCallback"         (BYVAL tess AS DWORD, BYVAL which AS GLEnum, BYVAL nfn AS GLInt)
DECLARE SUB gluGetTessProperty       LIB "glu32.dll" ALIAS "gluGetTessProperty"      (BYVAL tess AS DWORD, BYVAL which AS GLEnum, BYREF value AS GLDouble)
DECLARE FUNCTION gluNewNurbsRenderer LIB "glu32.dll" ALIAS "gluNewNurbsRenderer"     () AS LONG
DECLARE SUB gluDeleteNurbsRenderer   LIB "glu32.dll" ALIAS "gluDeleteNurbsRenderer"  (BYVAL nobj AS DWORD)
DECLARE SUB gluBeginSurface          LIB "glu32.dll" ALIAS "gluBeginSurface"         (BYVAL nobj AS DWORD)
DECLARE SUB gluBeginCurve            LIB "glu32.dll" ALIAS "gluBeginCurve"           (BYVAL nobj AS DWORD)
DECLARE SUB gluEndCurve              LIB "glu32.dll" ALIAS "gluEndCurve"             (BYVAL nobj AS DWORD)
DECLARE SUB gluEndSurface            LIB "glu32.dll" ALIAS "gluEndSurface"           (BYVAL nobj AS DWORD)
DECLARE SUB gluBeginTrim             LIB "glu32.dll" ALIAS "gluBeginTrim"            (BYVAL nobj AS DWORD)
DECLARE SUB gluEndTrim               LIB "glu32.dll" ALIAS "gluEndTrim"              (BYVAL nobj AS DWORD)
DECLARE SUB gluPwlCurve              LIB "glu32.dll" ALIAS "gluPwlCurve"             (BYVAL nobj AS DWORD, BYVAL ncount AS GLint, BYREF narray AS GLFloat, BYVAL stride AS GLint, BYVAL ntype AS GLEnum)
DECLARE SUB gluNurbsCurve            LIB "glu32.dll" ALIAS "gluNurbsCurve"           (BYVAL nobj AS DWORD, BYVAL nknots AS GLint, BYREF knot AS GLFloat, BYVAL stride AS GLInt, BYREF ctlarray() AS GLFLoat, BYVAL order AS GLint, BYVAL ntype AS GLEnum)
DECLARE SUB gluNurbsSurface          LIB "glu32.dll" ALIAS "gluNurbsSurface"      (BYVAL nobj AS DWORD, BYVAL sknot_count AS GLint, BYREF sknot AS GLfloat , _
                                                                                   BYVAL tknot_count AS GLint, BYREF tknot AS GLFloat, BYVAL s_stride AS GLint, BYVAL t_stride AS GLint, BYREF ctlarray() _
                                                                                   AS GLFloat, BYVAL sorder AS GLint, BYVAL torder AS GLint, BYVAL ntype AS GLEnum)
DECLARE SUB gluLoadSamplingMatrices  LIB "glu32.dll" ALIAS "gluLoadSamplingMatrices" (BYVAL nobj AS DWORD, BYREF modelMatrix() AS GLFloat, BYREF projMatrix() AS GLFloat, BYREF viewport() AS GLint)

DECLARE SUB gluNurbsProperty         LIB "glu32.dll" ALIAS "gluNurbsProperty"        (BYVAL nobj AS DWORD, BYVAL property AS GLenum, BYVAL value AS GlFloat)
DECLARE SUB gluGetNurbsProperty      LIB "glu32.dll" ALIAS "gluGetNurbsProperty"     (BYVAL nobj AS DWORD, BYVAL property AS GLenum, BYREF value AS GLFloat)
DECLARE SUB gluNurbsCallback         LIB "glu32.dll" ALIAS "gluNurbsCallback"        (BYVAL nobj AS DWORD, BYVAL which AS GLenum, BYVAL nfn AS DWORD)
DECLARE SUB gluBeginPolygon          LIB "glu32.dll" ALIAS "gluBeginPolygon"         (BYVAL tess AS DWORD)
DECLARE SUB gluNextContour           LIB "glu32.dll" ALIAS "gluNextContour"          (BYVAL tess AS DWORD, BYVAL ntype AS GLEnum)
DECLARE SUB gluEndPolygon            LIB "glu32.dll" ALIAS "gluEndPolygon"           (BYVAL tess AS DWORD)
