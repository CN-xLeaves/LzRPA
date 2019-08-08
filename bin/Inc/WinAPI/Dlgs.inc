'------------------------------------------------------------------------------
'
'  Dlgs.inc - This module contains the UI dialog header information.
'
'  Copyright (c) 2009-2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 31 Jan 2011
'
'------------------------------------------------------------------------------
'  from Dlgs.h dated 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%DLGSH_INCLUDED = 1

#INCLUDE "SdkDdkVer.inc"

'
'  Constant Declarations.
'

%ctlFirst  = &H0400
%ctlLast   = &H04ff

'
'  Push buttons.
'
%psh1      = &H0400
%psh2      = &H0401
%psh3      = &H0402
%psh4      = &H0403
%psh5      = &H0404
%psh6      = &H0405
%psh7      = &H0406
%psh8      = &H0407
%psh9      = &H0408
%psh10     = &H0409
%psh11     = &H040a
%psh12     = &H040b
%psh13     = &H040c
%psh14     = &H040d
%psh15     = &H040e
%pshHelp   = %psh15
%psh16     = &H040f

'
'  Checkboxes.
'
%chx1      = &H0410
%chx2      = &H0411
%chx3      = &H0412
%chx4      = &H0413
%chx5      = &H0414
%chx6      = &H0415
%chx7      = &H0416
%chx8      = &H0417
%chx9      = &H0418
%chx10     = &H0419
%chx11     = &H041a
%chx12     = &H041b
%chx13     = &H041c
%chx14     = &H041d
%chx15     = &H041e
%chx16     = &H041f

'
'  Radio buttons.
'
%rad1      = &H0420
%rad2      = &H0421
%rad3      = &H0422
%rad4      = &H0423
%rad5      = &H0424
%rad6      = &H0425
%rad7      = &H0426
%rad8      = &H0427
%rad9      = &H0428
%rad10     = &H0429
%rad11     = &H042a
%rad12     = &H042b
%rad13     = &H042c
%rad14     = &H042d
%rad15     = &H042e
%rad16     = &H042f

'
'  Groups, frames, rectangles, and icons.
'
%grp1      = &H0430
%grp2      = &H0431
%grp3      = &H0432
%grp4      = &H0433
%frm1      = &H0434
%frm2      = &H0435
%frm3      = &H0436
%frm4      = &H0437
%rct1      = &H0438
%rct2      = &H0439
%rct3      = &H043a
%rct4      = &H043b
%ico1      = &H043c
%ico2      = &H043d
%ico3      = &H043e
%ico4      = &H043f

'
'  Static text.
'
%stc1      = &H0440
%stc2      = &H0441
%stc3      = &H0442
%stc4      = &H0443
%stc5      = &H0444
%stc6      = &H0445
%stc7      = &H0446
%stc8      = &H0447
%stc9      = &H0448
%stc10     = &H0449
%stc11     = &H044a
%stc12     = &H044b
%stc13     = &H044c
%stc14     = &H044d
%stc15     = &H044e
%stc16     = &H044f
%stc17     = &H0450
%stc18     = &H0451
%stc19     = &H0452
%stc20     = &H0453
%stc21     = &H0454
%stc22     = &H0455
%stc23     = &H0456
%stc24     = &H0457
%stc25     = &H0458
%stc26     = &H0459
%stc27     = &H045a
%stc28     = &H045b
%stc29     = &H045c
%stc30     = &H045d
%stc31     = &H045e
%stc32     = &H045f

'
'  Listboxes.
'
%lst1      = &H0460
%lst2      = &H0461
%lst3      = &H0462
%lst4      = &H0463
%lst5      = &H0464
%lst6      = &H0465
%lst7      = &H0466
%lst8      = &H0467
%lst9      = &H0468
%lst10     = &H0469
%lst11     = &H046a
%lst12     = &H046b
%lst13     = &H046c
%lst14     = &H046d
%lst15     = &H046e
%lst16     = &H046f

'
'  Combo boxes.
'
%cmb1      = &H0470
%cmb2      = &H0471
%cmb3      = &H0472
%cmb4      = &H0473
%cmb5      = &H0474
%cmb6      = &H0475
%cmb7      = &H0476
%cmb8      = &H0477
%cmb9      = &H0478
%cmb10     = &H0479
%cmb11     = &H047a
%cmb12     = &H047b
%cmb13     = &H047c
%cmb14     = &H047d
%cmb15     = &H047e
%cmb16     = &H047f

'
'  Edit controls.
'
%edt1      = &H0480
%edt2      = &H0481
%edt3      = &H0482
%edt4      = &H0483
%edt5      = &H0484
%edt6      = &H0485
%edt7      = &H0486
%edt8      = &H0487
%edt9      = &H0488
%edt10     = &H0489
%edt11     = &H048a
%edt12     = &H048b
%edt13     = &H048c
%edt14     = &H048d
%edt15     = &H048e
%edt16     = &H048f

'
'  Scroll bars.
'
%scr1      = &H0490
%scr2      = &H0491
%scr3      = &H0492
%scr4      = &H0493
%scr5      = &H0494
%scr6      = &H0495
%scr7      = &H0496
%scr8      = &H0497

'
'  Controls
'
%ctl1      = &H04A0


%FILEOPENORD             = 1536
%MULTIFILEOPENORD        = 1537
%PRINTDLGORD             = 1538
%PRNSETUPDLGORD          = 1539
%FINDDLGORD              = 1540
%REPLACEDLGORD           = 1541
%FONTDLGORD              = 1542
%FORMATDLGORD31          = 1543
%FORMATDLGORD30          = 1544
%RUNDLGORD               = 1545

#IF (%WINVER >= &H400)
%PAGESETUPDLGORD         = 1546
%NEWFILEOPENORD          = 1547
%PRINTDLGEXORD           = 1549
%PAGESETUPDLGORDMOTIF    = 1550
%COLORMGMTDLGORD         = 1551
%NEWFILEOPENV2ORD        = 1552
#ENDIF ' %WINVER >= &H400)

' 1581 - 1590
#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
%NEWFILEOPENV3ORD        = 1553
#ENDIF

'1591 - 1600
#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
%NEWFORMATDLGWITHLINK    = 1591
%IDC_MANAGE_LINK         = 1592
#ENDIF


'
'  Typedef Declarations.
'
TYPE CRGB
    bRed   AS BYTE
    bGreen AS BYTE
    bBlue  AS BYTE
    bExtra AS BYTE
END TYPE           ' RGB Color
