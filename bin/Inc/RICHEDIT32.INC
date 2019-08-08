  TYPE NMHDR
    hwndFrom        AS DWORD
    idfrom          AS DWORD
    code            AS LONG    ' used for messages, so needs to be LONG, not DWORD...
  END TYPE

  TYPE CHARRANGE
    cpMin           AS LONG
    cpMax           AS LONG
  end type

  TYPE TEXTRANGE
    cpMin AS LONG
    cpMax AS LONG
    lpstrText AS ASCIIZ PTR  ' allocated by caller, zero terminated by RichEdit
  END TYPE

  TYPE CHARFORMAT2 BYTE
    cbSize          AS DWORD
    dwMask          AS DWORD
    dwEffects       AS DWORD
    yHeight         AS LONG
    yOffset         AS LONG                ' > 0 for superscript, < 0 for subscript
    crTextColor     AS DWORD
    bCharSet        AS BYTE
    bPitchAndFamily AS BYTE
    szFaceName      AS ASCIIZ * %LF_FACESIZE
    wFiller         AS WORD
    wWeight         AS WORD                ' Font weight (LOGFONT value)
    sSpacing        AS INTEGER              ' Amount to space between letters
    crBackColor     AS DWORD           ' Background color
    lcid            AS DWORD                  ' Locale ID
    dwReserved      AS DWORD            ' Reserved. Must be 0
    sStyle          AS INTEGER              ' Style handle
    wKerning        AS WORD               ' Twip size above which to kern char pair
    bUnderlineType  AS BYTE         ' Underline type
    bAnimation      AS BYTE             ' Animated text like marching ants
    bRevAuthor      AS BYTE             ' Revision author index
    bReserved1      AS BYTE   ' <- added..
  END TYPE

  TYPE CHARFORMAT BYTE
    cbSize          AS DWORD
    dwMask          AS DWORD
    dwEffects       AS DWORD
    yHeight         AS LONG
    yOffset         AS LONG
    crTextColor     AS DWORD
    bCharSet        AS BYTE
    bPitchAndFamily AS BYTE
    szFaceName      AS ASCIIZ * %LF_FACESIZE
    wFiller         AS WORD
  END TYPE
