  '
  ' Expand / Collapse Panel
  ' v1.0
  '
  ' Petr Schreiber, 2006
  '  
  
  ' This stores information for each section
  type tSection
    cID           as long ' Control ID

    NumControls   as long ' Number of controls in section   
    Hide          as long ' Section is hidden ? 0 = No, 1 = Yes

    oweShift      as long ' Info for colapsing and expanding
    posY          as long ' Y position in dialog
    hDialog       as long ' Parent dialog handle
  end type  
  
  dim cSection(32, 64) as tSection   ' max 32 sections, max 64 controls for each; this is resized automatically when needed
  dim cSectionWidth as long
  dim cSectionNum as long
  
  ' Call this first to specify dialog width, section width will be derived from this
  sub section_Init( dialogWidth as long )
    cSectionWidth = dialogWidth - 10
  end sub
  
  ' Assigns control to section
  sub section_Assign( section as long, ctrl as long )
    cSection(section,1).NumControls += 1
    local n as long = cSection(section,1).NumControls
    
    if n > ubound(cSection(2)) then redim preserve cSection( ubound(cSection(1)), n )

    cSection(section,n).cid = ctrl
  end sub
  
  ' Creates new section
  function section_New( hdialog as long, sName as string, y as long )
  
    incr cSectionNum
    if cSectionNum > ubound(cSection(1)) then redim PRESERVE cSection( cSectionNum, ubound(cSection(2)))
    CONTROL ADD LABEL, hdialog, 10000+cSectionNum, sName, 5, y, cSectionWidth, 15, %SS_CENTER OR %SS_CENTERIMAGE OR %WS_BORDER or %SS_NOTIFY
    control set color hdialog, 10000+cSectionNum, rgb(0,0,0), rgb(255,128,0)
    cSection(cSectionNum,1).PosY = y
    cSection(cSectionNum,1).hDialog = hdialog
    function = 10000+cSectionNum
    
  end function
  
  ' Collapses section
  sub section_Collapse( section as long )
    local posMoveBy as long
    local j,k,l as long
    local x,y as long    
    
    posMoveBy = cSection(section+1,1).PosY-(cSection(section,1).posy+20)
    cSection(section,1).oweShift = posMoveBy

    for j = 1 to cSection(section,1).NumControls
      control get loc cSection(cSectionNum,1).hDialog, cSection(section,j).cid to x,y
      control set loc cSection(cSectionNum,1).hDialog, cSection(section,j).cid, x+10000,y                  
      control disable cSection(cSectionNum,1).hDialog, cSection(section,j).cid 
    next

    for j = section+1 to cSectionNum
      for l = 1 to 10
        control set loc cSection(cSectionNum,1).hDialog, 10000+j, 5, cSection(j,1).PosY - posMoveBy/10*l
        control redraw cSection(cSectionNum,1).hDialog, 10000+j

        for k = 1 to cSection(j,1).NumControls
          if cSection(j,k).cid = 0 then iterate for


          control get loc cSection(cSectionNum,1).hDialog, cSection(j,k).cid to x,y
          control set loc cSection(cSectionNum,1).hDialog, cSection(j,k).cid, x,y-posMoveBy/10
          control redraw cSection(cSectionNum,1).hDialog, cSection(j,k).cid
        next   
        sleep 5
      next

      cSection(j,1).PosY = cSection(j,1).PosY - posMoveBy
    next
      
  end sub
  
  ' Expands section
  sub section_Expand( section as long )
    local posMoveBy as long
    local j,k,l as long
    local x,y as long

    for j = 1 to cSection(section,1).NumControls
        control enable cSection(cSectionNum,1).hDialog, cSection(section,j).cid 
        control get loc cSection(cSectionNum,1).hDialog, cSection(section,j).cid to x,y
        control set loc cSection(cSectionNum,1).hDialog, cSection(section,j).cid, x-10000,y                  
    next

    for j = cSectionNum to section+1 step -1
      for l = 1 to 10      
        control set loc cSection(j,1).hDialog, 10000+j, 5, cSection(j,1).posy+cSection(section,1).oweShift/10
        control redraw cSection(j,1).hDialog, 10000+j      
        cSection(j,1).PosY = cSection(j,1).posy+cSection(section,1).oweShift/10

        for k = 1 to cSection(j,1).NumControls
          if cSection(j,k).cid = 0 then iterate for
          control get loc cSection(j,1).hDialog, cSection(j,k).cid to x,y
          control set loc cSection(j,1).hDialog, cSection(j,k).cid, x,y+cSection(section,1).oweShift/10                          
          control redraw cSection(j,1).hDialog, cSection(j,k).cid
        next   
        sleep 5
      next   

    next
      dialog redraw cSection(section,1).hDialog
  end sub    
  
  ' Handles behaviour of all sections  
  sub section_Behaviour( Msg as long, wParam as long )
    if Msg = %WM_COMMAND then
      local i as long
      
      for i = 1 to cSectionNum
        if wParam = 10000+i then
              
          cSection(i,1).Hide = cSection(i,1).Hide xor 1
          if cSection(i,1).Hide = 1 then
            section_Collapse(i)
          else
            section_Expand(i)          
          end if              
              
        end if  
      next
    end if
  end sub      
  