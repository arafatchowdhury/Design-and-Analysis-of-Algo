Algorithm Steps:

Step 0: 
 
 -	inFile  open the input file
 
 -	read and count the number of data items in the file inFile.
 
 -	Close the inFile
 
 -	Dynamically allocate heapAry[] of the size count+1 and initialize heapAry[0] to 0. Remember, heapAry[1] is the root of the tree and heapAry[0] is the last index used in heapAry.
 
 -	outFile1  open for writing.
 
 -	outFile2  open for writing.

Step 1: call buildHeap

1.1	inFile <-- open the input file for the *second time*. 

1.2	rootIndex <-- 1

1.3	data <-- get a data item from the inFile

1.4	insertOneDataItem (data) // put data at the end of heap	

1.5	kidIndex <-- heapAry[0] // last index

1.6	bubbleUp (kidIndex) // written in recursion 

1.7	printHeap to outFile1 // debugging file

1.8	repeat step 1.3 - step 1.7 while inFile is NOT empty

Step 2: call deleteHeap
	
  2.1 data <-- getRoot()
	    
      - print data to outFile2 // the sorted output
	    
      - deletRoot () // move the last item in headAry to root
	    
      - fatherIndex <-- rootIndex
	    
      - bubbleDown (fatherIndex) // written in recursion				
	
  2.2 printHeap to outFile1 // debugging file

2.3 repeat step 2.1 - step 2.2 while the heap is NOT empty

Step 3: Close file.



Input text file include the following lines:

23  

82 7 28 

9 19 28 9  

7  13 

21 

4 

81  19 36

18 320 

61 7

3

4

5

16

17



Output-1:


1 23 

2 23 82 

3 7 82 23 

4 7 28 23 82 

5 7 9 23 82 28 

6 7 9 19 82 28 23 

7 7 9 19 82 28 23 28 

8 7 9 19 9 28 23 28 82 

9 7 7 19 9 28 23 28 82 9 

10 7 7 19 9 13 23 28 82 9 28 

11 7 7 19 9 13 23 28 82 9 28 21 

12 4 7 7 9 13 19 28 82 9 28 21 23 

13 4 7 7 9 13 19 28 82 9 28 21 23 81 

14 4 7 7 9 13 19 19 82 9 28 21 23 81 28 

15 4 7 7 9 13 19 19 82 9 28 21 23 81 28 36 

16 4 7 7 9 13 19 19 18 9 28 21 23 81 28 36 82 

17 4 7 7 9 13 19 19 18 9 28 21 23 81 28 36 82 320 

18 4 7 7 9 13 19 19 18 9 28 21 23 81 28 36 82 320 61 

19 4 7 7 7 13 19 19 18 9 28 21 23 81 28 36 82 320 61 9 

20 3 4 7 7 7 19 19 18 9 13 21 23 81 28 36 82 320 61 9 28 

21 3 4 7 7 4 19 19 18 9 7 21 23 81 28 36 82 320 61 9 28 13 

22 3 4 7 7 4 19 19 18 9 7 5 23 81 28 36 82 320 61 9 28 13 21 

23 3 4 7 7 4 19 19 18 9 7 5 23 81 28 36 82 320 61 9 28 13 21 16 

24 3 4 7 7 4 17 19 18 9 7 5 19 81 28 36 82 320 61 9 28 13 21 16 23

23 4 4 7 7 5 17 19 18 9 7 16 19 81 28 36 82 320 61 9 28 13 21 23 

22 4 5 7 7 7 17 19 18 9 13 16 19 81 28 36 82 320 61 9 28 23 21 

21 5 7 7 9 7 17 19 18 9 13 16 19 81 28 36 82 320 61 21 28 23 

20 7 7 7 9 13 17 19 18 9 23 16 19 81 28 36 82 320 61 21 28 

19 7 9 7 9 13 17 19 18 21 23 16 19 81 28 36 82 320 61 28 

18 7 9 17 9 13 19 19 18 21 23 16 28 81 28 36 82 320 61 

17 9 9 17 18 13 19 19 61 21 23 16 28 81 28 36 82 320 

16 9 13 17 18 16 19 19 61 21 23 320 28 81 28 36 82 

15 13 16 17 18 23 19 19 61 21 82 320 28 81 28 36 

14 16 18 17 21 23 19 19 61 36 82 320 28 81 28 

13 17 18 19 21 23 28 19 61 36 82 320 28 81 

12 18 21 19 36 23 28 19 61 81 82 320 28 

11 19 21 19 36 23 28 28 61 81 82 320 

10 19 21 28 36 23 320 28 61 81 82 

9 21 23 28 36 82 320 28 61 81 

8 23 36 28 81 82 320 28 61 

7 28 36 28 81 82 320 61 

6 28 36 61 81 82 320 

5 36 81 61 320 82 

4 61 81 82 320 

3 81 320 82 

2 82 320 

1 320 

0 



                                         		 ****** END ******
