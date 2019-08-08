
'======
' SORTM
'######

'
' Indexer using a MergeSort and Callbacks
'
'
' Charles E V Pegge
' 9 Aug 2009



' The sortm function is written in Oxygen, and based on a MergeSort
' which is one of the most efficient sort algorithms available, requiring
' n/2 * log2(n) comparisons.
'
' For example, A database of 1 meg data elements would require  10 meg comparisons
' whereas a simple pick-one sort would take n*n/2 = 500 gig comparisons.
'
' The sortm function requires twice the workspace of the final index, since it
' shuttles the indices from one buffer to the other during the merge sort process.
'
' This function uses a callback Chooser function to make each comparison, so 
' it can be applied to any type of data on any criterion. The output is 
' an array of 4 byte integers indexing the array of data elements.

' The index array must first be initialised with a set of indices, one for each
' data element. The merge sort function then rearranges the order of these indices 
' in the array.

uses "oxygen","file"


'-----------------------
'NUMBER OF WORDS TO SORT
'=======================


dim sz as long=10000


'-------------------------
'FOR INDEX AND DATA ARRAYS
'=========================


dim ri(sz*2+1) as long ' must be twice the number of data elements
dim rs(sz+1) as string ' test sample of random string data

'---------------
'FOR SAMPLE DATA
'===============

dim i,j as long
dim r as long
dim rst as string


'---------------------------------
'GENERATE RANDOM STRINGS AND INDEX
'=================================

for i=1 to sz
 ri(i)=i ' this is our initial index for each element in the string array.
 rst=string$(16," ")
 for j= 1 to 16 ' generate a string of 16 random uppercase characters
  r=rnd(1)*25+65
  mid$(rst,j)=chr$(r)
 next
 rs(i)=rst ' store a random string in each data element in the string array
 'print rst
next


dim src as string

