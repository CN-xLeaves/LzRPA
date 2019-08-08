'
'EXAMPLE
'=======
'
'def ChooseDirect
'  #asm
'  lea ecx,da
'  call comparestringsA [ecx+edx*4-4], [ecx+eax*4-4] 'DIRECT BSTRING COMPARE
'  '( : mov eax,0 : jle exit : inc eax : )
'  #basic
'end def


  'COMPARATOR FOR MERGESORT
  '
  def ChooseDirect
    mov ecx,da 'index array base
    '
    dec eax   'base adjust
    shl eax,StrideShift
    add eax,ecx
    mov eax,[eax] 'string address
    mov eax,[eax] 'string BSTR
    push eax
    '
    dec edx   'base adjust
    shl edx,StrideShift
    add edx,ecx
    mov edx,[edx] 'string address
    mov edx,[edx] 'string BSTR
    push edx
    '
    call comparestr
  end def



'===========
' MERGE SORT
'===========


'
' requires an index array of twice the number of elements
' 
' parameters
' 1 p    pointer to index array
' 2 sz   size of index array in elements
' 3 cbk  address of Choosing function for callback

' Return:
' 0
'
'-------------------------------------------
function Sort(sys dp, sys sz, sys da) as sys
'===========================================

'   dp ' pointer to base of data index array
'   sz ' pointer to number of elements to sort
'   da ' pointer to data array
'   cb ' pointer to comparator callback function
dim a  ' comparator flag
dim c  ' chooser index
dim e  ' end of  upper buffer block
dim g  ' element counter
dim i  ' first selector
dim j  ' second selector
dim k  ' target index
dim n  ' number of elements
dim q  ' flag for toggling source/target buffer blocks
dim bi ' boundary for fist selector
dim bj ' boundary for second selector
dim st ' start of source buffer
dim en ' end of source buffer
    
dim dd at dp
dim dc,dj,dk
'
'INITIAL
'-------
'
n=*sz : e=n+n
st=1 : g=n+1
'  
do
  if g>n then
    if st>=n then exit do
    '
    'SWAP SOURCE SOURCE INDEX BLOCK AND TARGET INDEX BLOCK
    '
    q=1-q                           ' TOGGLE
    if q then                       '
      k=n+1 : i=1 : en=n            ' TARGET UPPER BUFFERE
    else                            '
      k=1 : i=n+1 : en=e            ' TARGET LOWER BUFFER
    end if                          '
    '                               '
    j=i+st : bi=j : bj=bi+st        ' SET BLOCKS BASE AND MOUNDARIES
    if bj>en then bj=en+1           ' LIMIT TO MAX ELEMENTS
    shl st,1                        ' DOUBLE NEXT STRIDE
    g=1 
  end if
  '
  if i>=bi then                     ' IBLOCK USED UP
    if j>=bj then                   ' JBLOCK ALSO USED UO
      i=bj : bi+=st : bj+=st : j=bi ' NEXT BLOCK PAIR
      if bj>en then bj=en+1         ' BOUNDARY LIMIT
      if bi>en then bi=en+1         ' BOUNDARY LIMIT
      continue do
    else                            ' ONLY IBLOCK USED UP
      mov ecx,j : inc j
    end if
  elseif j>=bj then                 ' ONLY JBLOCK USED UP
     mov ecx,i : inc i
  else                              ' COMPARE IBLOCK AND JBLOCK ELEMENT
    mov edi,dp
    '
    mov eax,i : mov eax, [edi+eax*4-4] 
    mov edx,j : mov edx, [edi+edx*4-4]
    '
    ChooseDirect                   'COMPARATOR MACRO
    '
    (
    (
    jle exit
    mov ecx,j : inc j
    exit 2
    )
    mov ecx,i : inc i
    )
  end if
  '
  'dd(k)=dd(c)                      ' TRANSFER THE CHOSEN ELEMENT INDEX
  mov edi,dp
  mov edx,k
  mov eax,[edi+ecx*4-4]
  mov [edi+edx*4-4],eax
  inc k : inc g                     ' NEXT
end do

'TRANSFER SHUTTLE BUFFER TO START IF NECESSARY

if q then for i=1 to n : dd(i)=dd(i+n) : next 'TRANSFER TO LOWER BUFFER

end function

