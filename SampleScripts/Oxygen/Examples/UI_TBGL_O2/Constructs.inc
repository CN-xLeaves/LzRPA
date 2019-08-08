
'---------------------------------------------------
sub stick (wi as double, th as double, le as double)
'===================================================
  dim as double x,y,z
  x=wi*.5 : y=le : z=th*.5

  tbgl_color 250,170,100

  'FRONT

  tbgl_beginpoly %GL_QUADS
  tbgl_normal  0,0,  1
  tbgl_vertex -x, 0, z
  tbgl_vertex  x, 0, z
  tbgl_vertex  x,le, z
  tbgl_vertex -x,le, z
  tbgl_endpoly

  'RIGHT EDGE

  tbgl_beginpoly %GL_QUADS
  tbgl_normal  1,0,0
  tbgl_vertex  x, 0,  z
  tbgl_vertex  x, 0, -z
  tbgl_vertex  x,le, -z
  tbgl_vertex  x,le,  z
  tbgl_endpoly

  'BACK

  tbgl_beginpoly %GL_QUADS
  tbgl_normal  0,0,-1
  tbgl_vertex  x, 0, -z
  tbgl_vertex -x, 0, -z
  tbgl_vertex -x,le, -z
  tbgl_vertex  x,le, -z
  tbgl_endpoly

  'LEFT EDGE

  tbgl_beginpoly %GL_QUADS
  tbgl_normal  -1,0,0
  tbgl_vertex  -x, 0, -z
  tbgl_vertex  -x, 0,  z
  tbgl_vertex  -x,le,  z
  tbgl_vertex  -x,le, -z
  tbgl_endpoly
  
  'TOP END

  tbgl_beginpoly %GL_QUADS
  tbgl_normal  0,1,0
  tbgl_vertex  -x, le,  z
  tbgl_vertex   x, le,  z
  tbgl_vertex   x, le, -z
  tbgl_vertex  -x, le, -z
  tbgl_endpoly
  
  'BOTTOM END

  tbgl_beginpoly %GL_QUADS
  tbgl_normal  0,-1,0
  tbgl_vertex   x, 0,  z
  tbgl_vertex  -x, 0,  z
  tbgl_vertex  -x, 0, -z
  tbgl_vertex   x, 0, -z
  tbgl_endpoly
  
end sub


'----------------------
sub drawPoly(n as long)
'======================

  if updatem=1 then: tbgl_CallList 1 : exit sub
  '
  'UPDATEM=2 TO CREATE LIST
  '
  tbgl_DeleteList 1
  '
  dim b,e,r as long
  r=lcolor and 255
  dim pi,x,y,z,le,x1,y1,z1,x2,y2,z2,xn,yn,zn,a,s,sc,an,sa,rt as double
  '
  rt=diam*.5
  pi=4*atn(1) 'PI FOR ANGLE IN RADIANS
  e=n         'SIDE COUNT
  a=0         'Y ANGLE
  s=pi*2/e    'STEP Y ANGLE
  y1=1 : y2=1 'HEIGHT
  sc=1.005    'SCALING FOR OUTLINES
  an=(pi+s)*.5-s
  '
  tbgl_NewList 1

  for b=1 to e
    '
    TBGL_UseLighting %TRUE

    x1=cos(a) : z1=-sin(a)
    a+=s
    x2=cos(a) : z2=-sin(a)
    xn=x1+x2 : yn=y1+y2 : zn=z1+z2
    '
    '
    if panels then
      tbgl_beginpoly %GL_QUADS
      tbgl_normal xn,yn,zn
      tbgl_color   0, 128, 255 : tbgl_vertex  x1,   0.0, z1
      tbgl_color 255,   0,   0 : tbgl_vertex  x2,   0.0, z2
      tbgl_color 255, 255, 255 : tbgl_vertex  x2*tp, y2,  z2*tp
      tbgl_color 255, 255, 255 : tbgl_vertex  x1*tp, y1,  z1*tp
      tbgl_endpoly
    end if
    '
    if tubes or sticks then
      
      'BOTTOM MEMBERS

      tbgl_color   200, 200, 210
      x=x2-x1 : y=0 : z=z2-z1 : le=sqr(x*x+y*y+z*z)
      tbgl_PushMatrix
      tbgl_translate x1,0,z1
      tbgl_rotate 180*(an+a)/pi,0,1,0
      tbgl_rotate -90,0,0,1
      if tubes then
        tbgl_color  fr,fg,fb
        tbgl_cylinder rt,rt,le
      end if
      if sticks then
        x=x1*(1-tp) : y=y1 : z=z1*(1-tp)
        sa=atn(sqr(x*x+z*z)/y)*180/pi
        tbgl_rotate -sa,0,1,0
        stick swi,sth,le
      end if
      tbgl_PopMatrix
      '
      'TOP MEMBERS
      '
      tbgl_PushMatrix
      tbgl_translate x1*tp,y1,z1*tp
      tbgl_rotate 180*(an+a)/pi,0,1,0
      tbgl_rotate -90,0,0,1
      if tubes then
        tbgl_color  fr,fg,fb
        tbgl_cylinder rt,rt,le*tp
      end if
      if sticks then
        x=x1*(1-tp) : y=y1 : z=z1*(1-tp)
        sa=atn(sqr(x*x+z*z)/y)*180/pi
        tbgl_rotate -sa,0,1,0
        stick swi,sth,le*tp
      end if
      tbgl_PopMatrix

      'SIDE MEMBERS

      x=x1*(1-tp) : y=y1 : z=z1*(1-tp) : le=sqr(x*x+y*y+z*z)
      sa=atn(sqr(x*x+z*z)/y)
      
      tbgl_PushMatrix
      tbgl_translate x1,0,z1
      tbgl_rotate 180*(a-s)/pi,0,1,0
      tbgl_rotate sa*180/pi,0,0,1
      if tubes then
        tbgl_color  fr,fg,fb
        tbgl_cylinder rt,rt,le
      end if
      if sticks then
        tbgl_rotate 90,0,1,0
        stick swi,sth, le
      end if
      tbgl_PopMatrix
      '


    end if
    '
    TBGL_UseLighting %FALSE
    '
    if lines then
      tbgl_color   fr,fg,fb
      tbgl_beginpoly %GL_LINE_STRIP
      tbgl_vertex  x1*sc,   0.0, z1*sc
      tbgl_vertex  x2*sc,   0.0, z2*sc
      tbgl_vertex  x2*tp*sc, y2*sc,  z2*tp*sc
      tbgl_vertex  x1*tp*sc, y1*sc,  z1*tp*sc
      tbgl_endpoly
    end if

    TBGL_UseLighting %TRUE
    '
  next
  tbgl_EndList

  
end sub




'---------------------------
function Render_01() as long
'===========================

  ' Rotation Variable
  static angle as single

  KeyboardControls()


  if pf+updatem=0 then exit function ' no updates no mouse action 

  TBGL_UseLighting %TRUE
  TBGL_UseLightSource %GL_LIGHT0, %TRUE

  TBGL_BackColor br,bg,bb    
  tbgl_clearframe                   ' Clear Screen
  tbgl_resetmatrix                  ' Reset the Current Matrix
  tbgl_camera 0, 0, 1, 0, 0, 0      ' Default Camera Position

  tbgl_PushMatrix

  tbgl_translate pdx*.01, pdy*.01, -2-(0.02*pdz) 'MOVE OBJECT

  if yspinf then tbgl_Rotate yspinv,0,1,0 : yspinv+=0.2
  tbgl_rotate pax, 0.0, 1.0, 0.0    ' Rotation about y axis
  tbgl_rotate pay, 1.0, 0.0, 0.0    ' Rotation about x axis
  tbgl_rotate paz, 0.0, 0.0, 1.0    ' Rotation about z axis
  
  drawPoly(nsym)

  tbgl_PopMatrix
  
  tbgl_drawframe ' Swap the Drawing Buffers
  
  if updatem then updatem-=1
    
end function  



'---------------------------
function Render_02() as long
'===========================
  
  static x, y, z as double
  Static BoxColor as long 
  TBGL_UseLighting %TRUE
  TBGL_UseLightSource %GL_LIGHT0, %TRUE
  TBGL_BackColor br,bg,bb    

  if tbgl_GetwindowKeyState(hCtrl, %VK_R) then fr=255 : fg=0   : fb=0
  if tbgl_GetwindowKeyState(hCtrl, %VK_G) then fr=0   : fg=255 : fb=0
  if tbgl_GetwindowKeyState(hCtrl, %VK_B) then fr=0   : fg=0   : fb=255
  TBGL_COLOR fr,fg,fb
    
  TBGL_ClearFrame 
    
    tbgl_Camera 0,0,5,0,0,0
    
    if yspinf then tbgl_Rotate yspinv,0,1,0 : yspinv+=0.2
    tbgl_Box 1,1,1

    tbgl_GetPixelInfo tbgl_MouseGetPosX, tbgl_MouseGetPosy, %TBGL_PINFO_XYZ, x, y, z
    tbgl_Translate x,y,z
    tbgl_Sphere 0.1  
  TBGL_DrawFrame  
  
end function


'---------------------------
function Render_03() as long
'===========================
  
  static i, j as long
    TBGL_COLOR 255, 255, 255
    TBGL_BackColor br,bg,bb    
    TBGL_UseLighting %TRUE
    TBGL_UseLightSource %GL_LIGHT0, %TRUE    

    
    ' -- Erases previous frame
    tbgl_ClearFrame 
      
      ' -- Sets camera to look from 3,3,3 to 0,-1,0
      tbgl_Camera 3, 3, 3, _
                  0, 0, 0
    
      ' -- All following geometry will be rotated around vector 0,1,0
      ' -- That is - Y axis
    if yspinf then tbgl_Rotate yspinv,0,1,0 : yspinv+=0.2
      
      ' -- Now we will try to render kind of spider
      ' -- It has ...

      ' .. One big head
      tbgl_Color fr,fg,fb      
      tbgl_Sphere 0.25
      
      ' .. And eight legs
      ' .. We will draw them each 60° 
      for i = 0 to 359 step 45
        tbgl_PushMatrix
          tbgl_Rotate i, 0, 1, 0      ' 60, 120, 180, ...
          
          ' -- Legs will raise from bottom of head
          tbgl_Translate 0, -0.25, 0
        
          ' -- With 3 part tentacle
          tbgl_PushMatrix
            for j = 1 to 3
            tbgl_Color fr/j, fg/j, fb/j              
              
              ' -- Some harmonic rotations will be provided by Sinus
              tbgl_Rotate 70+sin(GetTickCount/1000+i+j)*20, 1, 0, 0
              
              ' -- Each tentacle part will be shorter and thinner than that before
              tbgl_Cylinder ( 0.1/j, 0.1/(j+1), 1/j )
              ' -- When drawn, we need to move "cursor" at its end to bind new part
              tbgl_Translate 0, 1/j, 0              
            next 
          tbgl_PopMatrix
           
        tbgl_PopMatrix
      next       

      
    ' -- Finishes drawing
    tbgl_DrawFrame 

end function


