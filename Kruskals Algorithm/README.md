
Algorithm Steps:

Step 0: numNodes ← get from input file. Allocate and initialize all the members in KruskalMST class, printSet(inWhichSet) // print the inWhichSet array to argv[3] with proper heading

// Step 1 to Step 3 is to make a list of input edges in ascending order so that for the subsequence of

// finding a min cost edge would be easy.

Step 1: <Ni, Nj, edgeCost> ← read from input file

newEdge ← create an undirectedEdge and fill with <Ni, Nj, cost>

insertEdge ( newEdge, edgeListHead) // Using insertion sort to insert newEdge into the linked list of edgeListHead // in ascending order by the cost

Step 2: printList (edgeListHead) //print up to the first 10 edges on the edgeList) to argv[3] file (with proper heading)

Step 3: repeat step 1 to step 2 until the input file is empty

Step 4: nextEdge ← removedEdge (edgeListHead) // Let’s say, nextEdge is <Ni, Nj, cost> if Ni and Nj are in the same set 

// check inWhichSet(Ni) with inWhichSet(Nj) to see if there are equal then discards nextEdge

Step 5: repeat step 4 until Ni and Nj are in different sets.

Step 6 pushEdge(nextEdge, MSTofG) // push nextEdge in the front of MSTofG totalMSTCost += the cost of nextEdge merge2Sets (Ni, Nj) // now, Ni, Nj are in the same set numSets --
printSet(inWhichSet) // print the inWhichSet array to argv[3] (with proper heading)

Step 7: printList(MSTofG) // print up to the first 10 edges of MSTofG) to argv[3] file (with proper heading)

Step 8: repeat step 4 – step 7 until numSets is equal to 1.

Step 9: output the entire MSTofG and the totalCost to argv[2] with proper heading, one edge with cost per text line.

Step 10: close all files.


                                                  
                                                  ****** END ******
