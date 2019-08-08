

  '-----------------------------------------------------------
  function check_sample(long dt, long ri,long sz) as string
  '===========================================================
  '
  dim as bstr rs at dt ' array of data strings
  dim as long dd at ri ' array of indexes to data
  dim as long e  at sz ' number of elements
  '
  dim i,j
  function=`
  SAMPLE:
  ASCENDING ORDER


  `
  j=e
  if j>16 then j=16
  for i=1 to j
    function+=rs(dd(i))+`
    `
  next
  '
  end function


  '-----------------
  'PERFORMANCE CHECK
  '=================
  '
  DECLARE FUNCTION QueryPerformanceCounter LIB `KERNEL32.DLL` (lpPerformanceCount AS QUAD) AS LONG
  DECLARE FUNCTION QueryPerformanceFrequency LIB `KERNEL32.DLL` (lpFrequency AS QUAD) AS LONG
  dim as quad t1,t2,fr

  QueryPerformanceFrequency fr  



  '----
  'MAIN
  '====
  '
  '
  '----------------
  'PERFORM THE TEST
  '================

  QueryPerformanceCounter t1
  sortmb #ri,#sz, &choosewhich
  QueryPerformanceCounter t2
  
  '------------
  'PREPARE DATA
  '============

  dim as string r,tab=chr 9
  r=check_sample (#rs,#ri,#sz)
  dim n at #sz
  dim as single t
  t=(t2-t1)/fr

  '------
  'REPORT
  '======

  double d=round(t*1e9/(n*log2(n)))
  string cr=chr(13)+chr(10)
  print r + cr +
  str(n) " strings" + cr +
  "sorting time " str(round(t*1000)) " mSecs" + cr +
  "per cycle: " str(d) " nsec" + cr
