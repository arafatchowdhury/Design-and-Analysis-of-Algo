# Dijkstra's Algorithm

Algorithm Steps:

step 0:  Open input and output files
 numNodes <- get from input
 sourceNode <- get from input
 
step 1:  loadMatrix

step 2:  setBestCostAry (sourceNode)
 setFatherAry (sourceNode)
 setToDoAry (sourceNode)

step 3:  minNode <- findMinNode()
              markMinNode(minNode)
              call debugPrint

step 4:  currentNode <- 1

step 5:  if (toDoAry[currentNode] == 1)
           	      	 newCost <- computeCost(minNode, currentNode)
         		 if newCost < bestCostAry [currentNode]
 		changeCost (currentNode, newCost)
changeFather (currentNode, minNode)
   		call debugPrint

step 6: 	currentNode ++

step 7: repeat step 5-step 6 while currentNode <= numNodes

step 8: repeat step 3 to step 7 until all nodes in toDoAry are 0

step 9: currentNode <- 1

step 10:  printShortestPath (currentNode, sourceNode)

step 11:  currentNode ++

step 12: repeat step 10 and step 11 while currentNode <= numNodes

step 13: close all files.



                                              ****** Thank You ******

