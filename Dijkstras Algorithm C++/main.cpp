#include <iostream>
#include <fstream>
using namespace std;

class DijktraSSS
{
	public:
	int numNodes;
	int sourceNode;
	int minNode;
	int currentNode;
	int newCost;
	int* fatherAry;
	int* toDoAry;
	int* bestCostAry;
	int** costMatrix;


	DijktraSSS(int nNode, int src)
	{
		newCost = 0;
		currentNode = 1;
		sourceNode = src;
		minNode = src;
		numNodes = nNode;

		fatherAry = new int [numNodes+1];
			for(int i=1; i <numNodes+1;i++)
			{
				fatherAry[i] = i;
			}
		toDoAry = new int[numNodes+1];
		bestCostAry = new int[numNodes+1];

		costMatrix = new int*[numNodes+1];
			for(int i = 0; i < numNodes+1; ++i)
			{
				costMatrix[i] = new int [numNodes+1];
			}
	}

	void initialize()
	{
		for(int i=0; i < numNodes+1; i++)
		{
			for(int j = 0; j < numNodes+1; j++)
			{
				if(i == j)
				{
					costMatrix[i][j] = 0;
				}
				else
				{
					costMatrix[i][j] = 9999;
				}
			}
		}
	}

	void loadCostMatrix(int n_i, int n_j, int cost)
	{
			costMatrix[n_i][n_j] = cost;
	}

	void setToDoAry(int src)
	{
		for(int i=1; i< numNodes+1 ; i++)
		{
			if(i==src)
			{
				toDoAry[i] = 0;
			}
			else
			{
				toDoAry[i] = 1;
			}
		}
	}

	void setBestCostAry(int src)
	{
		for(int i = 1; i< numNodes+1;i++)
		{
			bestCostAry[i] = costMatrix[src][i];
		}
	}

	void setFather (int src)
	{
		for (int i=1; i < numNodes+1; i++)
		{
			fatherAry[i] = src;
		}
	}

	void changeFather(int node, int minNodes)
	{
		fatherAry[node] = minNodes;
	}

	int findMinNode()
	{
		int minNodeCost = 99999;
		for(int i=1; i<numNodes+1; i++)
		{
			if(toDoAry[i] == 1 && bestCostAry[i] < minNodeCost)
			{
					minNodeCost = bestCostAry[i];;
					minNode = i;
			}
		}
		return minNode;
	}

	int computeCost (int minNode, int currentNode)
	{
		int cost = bestCostAry[minNode] + costMatrix[minNode][currentNode];
		return cost;
	}

	void markMinNode (int minNode)
	{
		if (toDoAry[minNode] != 0)
		{
			toDoAry[minNode]  = 0;
		}
	}

	void changeCost(int node, int newCost)
	{
		bestCostAry[node] = newCost;
	}

	void debugPrint (ofstream &outFile2)
	{
		outFile2 << "Source Node is: "<<sourceNode << endl;

		outFile2 << endl<< "The father Array is:" << endl;
			for(int i=1; i < numNodes+1; i++)
			{
				outFile2 << fatherAry[i] << endl;
			}

		outFile2 <<endl<< "The bestCost Array is:" << endl;
				for(int i=1; i < numNodes+1; i++)
				{
					outFile2 << bestCostAry[i] << endl;
				}

		outFile2 <<endl<< "The ToDo  Array is:" << endl;
				for(int i=1; i < numNodes+1; i++)
				{
					outFile2 << toDoAry[i] << endl;
				}
	}

	void printShortestPaths(int src, int curr, ofstream &outFile1)
	{
		int temp = curr;
		outFile1 << "From path " << src << " to " << curr;
		outFile1 <<" : " <<curr << " <-- ";

		while (fatherAry[curr] != src)
		{
			outFile1 <<fatherAry[curr] << " <-- ";
			curr = fatherAry[curr];
		}
		outFile1 << src;
		outFile1 << ": Cost = " << bestCostAry[temp] << endl;
	}

	bool check()
	{
		for(int i =1;i<numNodes+1;i++)
		{
			if(toDoAry[i] ==1)
			{
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char** argv) {

	ifstream inFile;
		inFile.open(argv[1]);

	ofstream outFile1, outFile2;
		outFile1.open(argv[2]);
	   	outFile2.open(argv[3]);

	int numNodes;
	int sourceNode;
	int minNode, newCost;
	int currentNode;


	inFile >> numNodes;
	inFile >> sourceNode;

	DijktraSSS *dj = new DijktraSSS(numNodes, sourceNode);
	dj->initialize();

	while(!inFile.eof())
	{
	    	int n_i, n_j, cost_ij;
	    	inFile >> n_i;
		inFile >> n_j;
	    	inFile >> cost_ij;
	    	dj->loadCostMatrix(n_i,n_j,cost_ij);
	}

	dj->setBestCostAry(sourceNode);
	dj->setFather(sourceNode);
	dj->setToDoAry(sourceNode);

	while(dj->check())
	{
		minNode = dj->findMinNode();
		dj->markMinNode(minNode);
		dj->debugPrint(outFile2);

		dj->currentNode=1;
		while(dj->currentNode <= dj->numNodes)
		{
			if(dj->toDoAry[dj->currentNode] ==1)
			{
				newCost = dj->computeCost(minNode, dj->currentNode);
				if(newCost < dj->bestCostAry[dj->currentNode])
				{
					dj->changeCost(dj->currentNode, newCost);
					dj->changeFather(dj->currentNode,minNode);
					dj->debugPrint(outFile2);
				}
			}
			dj->currentNode++;
		}
	}

	int curr = 1;
	while(curr <= numNodes)
	{
		dj->printShortestPaths(sourceNode, curr, outFile1);
		curr++;
	}

	inFile.close();
	outFile1.close();
	outFile2.close();

	return 0;
}
