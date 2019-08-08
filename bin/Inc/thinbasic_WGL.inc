  '*********************************************************
  '*                                                       *
  '*        OpenGL related API specific to Windows         *
  '*          thinBASIC version by Petr Schreiber          *
  '*                                                       *
  '*                 Release 9th July 2007                 *
  '*                                                       *
  '*********************************************************

  TYPE POINTFLOAT
    x AS SINGLE
    y AS SINGLE
  END TYPE

  TYPE GLYPHMETRICSFLOAT
    gmfBlackBoxX AS SINGLE
    gmfBlackBoxY AS SINGLE
    gmfptGlyphOrigin AS POINTFLOAT
    gmfCellIncX AS SINGLE
    gmfCellIncY AS SINGLE
  END TYPE

  ' Layer plane descriptor
  TYPE LAYERPLANEDESCRIPTOR
    nSize AS WORD
    nVersion AS WORD
    dwFlags AS DWORD
    iPixelType AS BYTE
    cColorBits AS BYTE
    cRedBits AS BYTE
    cRedShift AS BYTE
    cGreenBits AS BYTE
    cGreenShift AS BYTE
    cBlueBits AS BYTE
    cBlueShift AS BYTE
    cAlphaBits AS BYTE
    cAlphaShift AS BYTE
    cAccumBits AS BYTE
    cAccumRedBits AS BYTE
    cAccumGreenBits AS BYTE
    cAccumBlueBits AS BYTE
    cAccumAlphaBits AS BYTE
    cDepthBits AS BYTE
    cStencilBits AS BYTE
    cAuxBuffers AS BYTE
    iLayerPlane AS BYTE
    bReserved AS BYTE
    crTransparent AS DWORD
  END TYPE

  TYPE WGLSWAP
    hdc AS DWORD
    uiFlags AS DWORD
  END TYPE

  %WGL_FONT_LINES    = 0
  %WGL_FONT_POLYGONS = 1

  ' LAYERPLANEDESCRIPTOR flags
  %LPD_DOUBLEBUFFER   = &H00000001
  %LPD_STEREO         = &H00000002
  %LPD_SUPPORT_GDI    = &H00000010
  %LPD_SUPPORT_OPENGL = &H00000020
  %LPD_SHARE_DEPTH    = &H00000040
  %LPD_SHARE_STENCIL  = &H00000080
  %LPD_SHARE_ACCUM    = &H00000100
  %LPD_SWAP_EXCHANGE  = &H00000200
  %LPD_SWAP_COPY      = &H00000400
  %LPD_TRANSPARENT    = &H00001000

  %LPD_TYPE_RGBA       = 0
  %LPD_TYPE_COLORINDEX = 1

  ' wglSwapLayerBuffers flags
  %WGL_SWAP_MAIN_PLANE = &H00000001
  %WGL_SWAP_OVERLAY1   = &H00000002
  %WGL_SWAP_OVERLAY2   = &H00000004
  %WGL_SWAP_OVERLAY3   = &H00000008
  %WGL_SWAP_OVERLAY4   = &H00000010
  %WGL_SWAP_OVERLAY5   = &H00000020
  %WGL_SWAP_OVERLAY6   = &H00000040
  %WGL_SWAP_OVERLAY7   = &H00000080
  %WGL_SWAP_OVERLAY8   = &H00000100
  %WGL_SWAP_OVERLAY9   = &H00000200
  %WGL_SWAP_OVERLAY10  = &H00000400
  %WGL_SWAP_OVERLAY11  = &H00000800
  %WGL_SWAP_OVERLAY12  = &H00001000
  %WGL_SWAP_OVERLAY13  = &H00002000
  %WGL_SWAP_OVERLAY14  = &H00004000
  %WGL_SWAP_OVERLAY15  = &H00008000
  %WGL_SWAP_UNDERLAY1  = &H00010000
  %WGL_SWAP_UNDERLAY2  = &H00020000
  %WGL_SWAP_UNDERLAY3  = &H00040000
  %WGL_SWAP_UNDERLAY4  = &H00080000
  %WGL_SWAP_UNDERLAY5  = &H00100000
  %WGL_SWAP_UNDERLAY6  = &H00200000
  %WGL_SWAP_UNDERLAY7  = &H00400000
  %WGL_SWAP_UNDERLAY8  = &H00800000
  %WGL_SWAP_UNDERLAY9  = &H01000000
  %WGL_SWAP_UNDERLAY10 = &H02000000
  %WGL_SWAP_UNDERLAY11 = &H04000000
  %WGL_SWAP_UNDERLAY12 = &H08000000
  %WGL_SWAP_UNDERLAY13 = &H10000000
  %WGL_SWAP_UNDERLAY14 = &H20000000
  %WGL_SWAP_UNDERLAY15 = &H40000000

  %WGL_SWAPMULTIPLE_MAX = 16

  DECLARE FUNCTION wglCopyContext LIB "OPENGL32.DLL" ALIAS "wglCopyContext" (BYVAL hglrcSrc AS DWORD, BYVAL hlglrcDst AS DWORD, BYVAL dMask AS DWORD) AS LONG
  DECLARE FUNCTION wglCreateContext LIB "OPENGL32.DLL" ALIAS "wglCreateContext" (BYVAL hdc AS DWORD) AS DWORD
  DECLARE FUNCTION wglCreateLayerContext LIB "OPENGL32.DLL" ALIAS "wglCreateLayerContext" (BYVAL hdc AS DWORD, BYVAL iLayerPlane AS LONG) AS DWORD
  DECLARE FUNCTION wglDeleteContext LIB "OPENGL32.DLL" ALIAS "wglDeleteContext" (BYVAL hglrc AS DWORD) AS LONG
  DECLARE FUNCTION wglGetCurrentContext LIB "OPENGL32.DLL" ALIAS "wglGetCurrentContext" () AS DWORD
  DECLARE FUNCTION wglGetCurrentDC LIB "OPENGL32.DLL" ALIAS "wglGetCurrentDC" () AS DWORD
  DECLARE FUNCTION wglGetProcAddress LIB "OPENGL32.DLL" ALIAS "wglGetProcAddress" (lpszProc AS ASCIIZ) AS DWORD
  DECLARE FUNCTION wglMakeCurrent LIB "OPENGL32.DLL" ALIAS "wglMakeCurrent" (BYVAL hdc AS DWORD, BYVAL hglrc AS DWORD) AS LONG
  DECLARE FUNCTION wglShareLists LIB "OPENGL32.DLL" ALIAS "wglShareLists" (BYVAL hglrc1 AS DWORD, BYVAL hglrc2 AS DWORD) AS LONG
  DECLARE FUNCTION wglUseFontBitmaps LIB "OPENGL32.DLL" ALIAS "wglUseFontBitmapsA" (BYVAL hdc AS DWORD, BYVAL dFirst AS DWORD, BYVAL dCount AS DWORD, BYVAL dListBase AS DWORD) AS LONG
  DECLARE FUNCTION wglUseFontOutlines LIB "OPENGL32.DLL" ALIAS "wglUseFontOutlinesA" (BYVAL hdc AS DWORD, BYVAL dFirst AS DWORD, BYVAL dCount AS DWORD, BYVAL dListBase AS DWORD, BYVAL deviation AS SINGLE, BYVAL extrusion AS SINGLE, _
                   BYVAL iFormat AS LONG, BYVAL lpgmf AS DWORD) AS LONG
  DECLARE FUNCTION wglDescribeLayerPlane LIB "OPENGL32.DLL" ALIAS "wglDescribeLayerPlane" (BYVAL hdc AS DWORD, BYVAL iPixelFormat AS LONG, BYVAL iLayerPlane AS LONG, BYVAL nBytes AS DWORD, plpd AS LAYERPLANEDESCRIPTOR) AS LONG
  DECLARE FUNCTION wglSetLayerPaletteEntries LIB "OPENGL32.DLL" ALIAS "wglSetLayerPaletteEntries" (BYVAL hdc AS DWORD, BYVAL iLayerPlane AS LONG, BYVAL iStart AS LONG, BYVAL cEntries AS LONG, pcr AS DWORD) AS LONG
  DECLARE FUNCTION wglGetLayerPaletteEntries LIB "OPENGL32.DLL" ALIAS "wglGetLayerPaletteEntries" (BYVAL hdc AS DWORD, BYVAL iLayerPlane AS LONG, BYVAL iStart AS LONG, BYVAL cEntries AS LONG, pcr AS DWORD) AS LONG
  DECLARE FUNCTION wglRealizeLayerPalette LIB "OPENGL32.DLL" ALIAS "wglRealizeLayerPalette" (BYVAL hdc AS DWORD, BYVAL iLayerPlane AS LONG, BYVAL fRealize AS LONG) AS LONG
  DECLARE FUNCTION wglSwapLayerBuffers LIB "OPENGL32.DLL" ALIAS "wglSwapLayerBuffers" (BYVAL hdc AS DWORD, BYVAL dfPlanes AS DWORD) AS LONG
