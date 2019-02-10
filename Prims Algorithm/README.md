Algorithm Steps:

Step 0: numNodes ß get from input file
  Allocate and initialize all the members in PrimMST class accordingly
  
Step 1: <Ni, Nj, edgeCost> ß read from input file
  newEdge ß create an undirectedEdge and fill with <Ni, Nj, cost>
  insertEdge ( newEdge, edgeListHead) // Using insertion sort to insert newEdge into the linked list of
  edgeListHead. In ascending order by the cost
  
Step 2: printList (edgeListHead) //See the output format in the above

Step 3: repeat step 1 to step 2 until the input file is empty

Step 4: nextEdge ß removedEdge (edgeListHead)

  If Ni and Nj are in the same set // check inWhichSet(Ni) and inWhichSet(Nj)
  then discards nextEdge

Step 5: repeat step 4 until Ni and Nj are in different sets

Step 6: pushEdge(nextEdge, MSTofG) // push nextEdge in the front of MSTofG
  totalMSTCost += the cost of nextEdge
  if Ni is in setA,
  move2SetA(Nj, setA) // move Nj from setB to setA
  else
  move2SetA(Ni, setA) // move Ni from setB to setA
  // now, Ni, Nj should be in setA
  printSet(inWhichSet) // print the inWhichSet array to argv[3] (with proper heading)

Step 7: printList(MSTofG) // print up to the first 10 edges of MSTofG) to argv[2] file (with proper heading)

Step 8: repeat step 4 – step 7 until setB is empty. // inWhichSet are all 1

Step 9: output the entire MSTofG and the totalCost to outfile1, argv[1], with proper heading, one edge with cost
  per text line.

Step 10: close all files.

Input:
9
6 4 3
2 4 1
3 2 5
5 7 5
1 6 3
8 6 2
9 8 2
4 3 3
1 2 6
3 5 4
6 7 2


Output:
Entire MSTofG with Respective Cost:
<0,0,0>
<2,4,1>
<6,7,2>
<9,8,2>
<8,6,2>
<4,3,3>
<1,6,3>
<6,4,3>
<3,5,4>
Total Cost: 20
