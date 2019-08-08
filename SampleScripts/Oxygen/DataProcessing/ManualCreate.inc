  'MARKERS
  '=======

  cr=chr(13)+chr(10)
  tab=chr(9)
  kd=cr+"data "
  ke=cr+cr+cr
  kk=cr+chr(39)
  kn=kk+" "
  ks=" "



  '--------------------------------------------------------------------------
  sub getblock(s as string, kw as string, ke as string, a as long, b as long)
  '==========================================================================
  a=instr(a,s,kw)
  if not a then a=1 : b=1 : exit sub
  b=instr(a,s,ke)
  if not b then b=a
  end sub


  '----------------------------------------------
  sub getsdata(s as string, a as long, b as long)
  '==============================================
  b=a
  getblock(s,kd,ks,a,b)
  end sub


  '--------------------------------------------
  sub getrec(s as string, a as long, b as long)
  '============================================
  b=a
  getblock(s,kd,ke,a,b)
  end sub


  '-------------------------------------------------------------
  function nqtword(s as string, a as long, le as long) as string
  '=============================================================
  a+=1
  b=instr a,s," "
  a+=1 : c=b-1
  le=c-a
  if le>0 then function=mid s,a,le
  'itr skipspaces?
  a=b
  end function


  '--------------------------------------------------
  function getname(s as string, a as long) as string
  '==================================================
  sys b,c,le
  b=a : c=a
  getsdata(s,b,c)
  if b<>c then function=nqtword(s,c,le)
  end function


  '--------------------------------------------------
  function getnames(s as string, a as long) as string
  '==================================================
  sys b,c,d,le
  b=a : c=a
  do
    getsdata(s,b,c)
    if b=c then exit do 'no more data
    b=c
    function+=nqtword(s,b,le) cr
    b=instr b,s,cr
    d=instr b,s,kd
    if b<>d then
      exit function 'not contiguous data statements
    end if
  end do
  end function


  '----------------------------------------------------
  function getfieldword(s as string, n as string) as string
  '====================================================
  sys a,b,c
  a=instr(s,kk+n+":")
  if not a then exit function
  a+=len(n)+4
  b=instr a,s,cr
  if not b then b=1+len s
  function=ltrim(mid(s,a,b-a))
  end function

  '----------------------------------------------------
  function getfield(s as string, n as string) as string
  '====================================================
  sys a,b,c
  a=instr(s,kk+n+":")
  if not a then exit function
  a+=len(n)+4
  b=instr a,s,cr
  if not b then b=1+len s
  function=ltrim(mid(s,a,b-a+2))
  '
  do
    c=instr b,s,kn
    if c<>b then exit do
    b=c+13 'skip lead-in
    c=instr b,s,cr
    if c then
      function+=(mid s,b,c+2-b)
      b=c
    end if
  end do
  end function


  '--------------
  type recordlist
  '==============
    s as string 'name of record
    i as sys    'position in file
  end type


  '----------------------------------------------------
  sub makegrlist(s as string, d as recordlist, i as sys)
  '=====================================================
  sys a,b,le
  a=1 : b=1 : le=0
  do
    getsdata(s,a,b)
    if b<=a then exit do
    c=b
    i+=1
    d[i].s=nqtword(s,c,le)
    if not le then i-=1 : exit do
    d[i].i=a
    '
    'SKIP OVER OTHER DATA STATEMENTS IN THE BLOCK
    '
    do
      a=instr(c,s,cr)
      b=instr(c,s,cr+"data ")
      if a<>b then
        b=instr(c,s,kk) 'allow for commented lines etc
        if a<>b then exit do
      end if
      c+=3
    end do
    a=c
  end do
  end sub


  '---------------------------------------------------
  sub makelist(s as string, d as recordlist, i as sys)
  '===================================================
  sys a,b,le
  a=1 : b=1 : le=0
  do
    getsdata(s,a,b)
    if b<=a then exit do
    c=b
    i+=1
    d[i].s=nqtword(s,c,le)
    if not le then i-=1 : exit do
    d[i].i=a
    a=c
  end do
  end sub


  prbuf="" 'print buffer
  prof=0   'endpoint index
  '
  '--------------------------------------------
  function pr(s as string) 'ADD TO PRINT BUFFER
  '============================================
    sys le,ls
    le=len prbuf : ls=len s
    if prof+ls>le then prbuf+=space(8000+ls)
    mid prbuf,prof+1,s
    prof+=ls
  end function


  '
  'def printfield pr k cr cr s cr
  '
  'def printfield pr "<b><i>" k "</i></b><br><br>" cr cr s "<br><br><br>" cr
  '
  def printfield
    pr "<tr>" cr +
    "<td valign=top >" cr +
    "<font color=#3333ff><b><i>" k "</i></b></font>" +
    "</td>" cr +
    "<td valign=top>" cr +
    s +
    "<br>" cr +
    "</td>" cr +
    "</tr>" cr
  end def
  '
  def printHeading
    pr "<tr>" cr +
    "<td valign=top >" cr +
    "<font color=#3333ff><b>" k "</b></font>" +
    "</td>" cr +
    "</tr>" cr
  end def
  '
  '--------------------------------
  sub prih(k as string,s as string)
  '================================
  printHeading
  end sub

  '--------------------------------
  sub prif(k as string,s as string)
  '================================
  sys le
  le=len s
  if not le then exit sub
  printfield
  end sub

  '---------------------------------
  sub prifc(k as string,s as string)
  '=================================
  sys a,le
  a=asc s
  le=len s
  if not le then exit sub
  s="<pre>" s "</pre>"
  printfield
  end sub

  '------------------------------------------------
  function getword(s as string, i as sys) as string
  '================================================
  sys le,p,q,j=1
  le=len s
  if le=0 then exit function
  if i>le then exit function
  p=*s
  q=i
  mov edx,p
  mov ecx,q
  dec ecx
  add edx,ecx
  (
    mov al,[edx]
    inc edx : inc ecx
    cmp al,0  : jz exit
    cmp al,33 : jb repeat
    cmp al,44 : jz repeat 'ignore comma
  )
  j=ecx
  dec edx : dec ecx
  (
    mov al,[edx]
    inc edx : inc ecx
    cmp al,0  : jz exit
    cmp al,44 : jz exit
    cmp al,32 : ja repeat
  )
  i=ecx
  if i>j then function=mid(s,j,i-j)
  end function


  '-------------------------------
  function filenameHTM(n as string) as string
  '===============================
  sys a
  function=n+".htm"
  a=asc n
  if a<97 then
    function="a"+str(a)+mid function,2
  end if
  end function


  '----------------------
  sub reftag(s as string)
  '======================
  sys i
  string w,r,n
  if len(s)<4 then exit sub 'itr necessary
  i=1
  do
    w=getword(s,i)
    if len(w) then
      n=filenameHTM w
      r+=`<a href="`+n+`">` w `</a> ` cr
    else
      exit do
    end if
  end do
  s=r
  end sub


  '---------------------------
  sub htmlencodew(w as string)
  '===========================
  sys c
  '
  c=asc w
  if c=60 then
    if asc(w,2)=60 then
      w="&#60;&#60;" : exit sub
    end if
    w="&#60;"+mid(w,2)
  elseif c=62 then
    w="&#62;"+mid(w,2)
  end if
  end sub


  '--------------------------------------
  sub grprintnames(s as string, p as sys)
  '======================================
  sys a,b,le
  string w
  a=p : b=1 : le=0
  getsdata(s,a,b)
  if b<=a then exit sub
  c=b
  do
    '
    w=nqtword(s,c,le)
    htmlencodew w
    pr w " , "
    if not le then exit do
    '
    'SKIP OVER OTHER DATA STATEMENTS IN THE BLOCK
    '
    do
      a=instr(c,s,cr)
      b=instr(c,s,cr+"data ")
      if a<>b then
        b=instr(c,s,kk) 'allow for commented lines etc
        if a<>b then jmp fwd ngrprint 'done
        if instr(b,s,kk+"-")=b then pr "<br><br>" cr 'line break for line
        c=b+3
        continue do
      else
        c=b+6 : exit do
      end if
    end do
  end do
  '
  ngrprint:
  '
  end sub


  '
  'TO BUILD LIST OF ALL FILES
  '==========================
  '
  filelist=""

  '-------------------------------------------------------
  function inclfile(s as string, f as string) as string
  '=======================================================
  string ent
  ent=f
  ent=replace(ent,"%1",s)
  ent=replace(ent,"%2",s ".hha")
  filelist+=s ".hha" cr
  function=ent
  end function
  
