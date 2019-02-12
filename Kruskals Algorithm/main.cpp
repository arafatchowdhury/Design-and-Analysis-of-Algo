#include <iostream>
#include <fstream>
using namespace std;

class graphNode
{
    public:
    int nodeID; // an integer 1 to N
    graphNode* next;
    
    graphNode(int id) // to create a new graphNode of a given nodeID and next should be null.
    {
        nodeID = id;
        next = NULL;
    }
    ~graphNode() // to free a graphNode
    {
        delete[] next;
    }
};

class undirectedEdge
{
    public:
    int Ni;
    int Nj;
    int edgeCost;
    undirectedEdge *next;
    
    undirectedEdge()
    {
        Ni=0;
        Nj=0;
        edgeCost=0;
        next=NULL;
    }
    
    undirectedEdge(int i, int j, int cost) // to create a new undirectedEdge of given data and next should be null.
    {
        Ni = i;
        Nj = j;
        edgeCost = cost;
        next = NULL;
    }

    void printEdge() // print the info of a given undirectedEdge
    {
        cout << Ni << " " << Nj << " " << edgeCost << endl;
    }

    ~undirectedEdge() //to free an undirectedEdge
    {
        delete[] next;
    }
};

class KruskalMST
{
    public:
    int numNodes; //number of nodes in G
    int* inWhichSet; // a 1-D array, size of N+1,
    // to indicate which set each node belongs; dynamically allocated, and set to itself initially.
    int numSets; // to indicate the remaining number of sets in the computation, initially set to numNodes.
    int totalMSTCost; // initially set to zero
    undirectedEdge* MSTofG; // the head of a linked list Stack, should point to a dummy node <0,0,0> when created.
    undirectedEdge* edgeListHead; // the head of a linked list, should point to a dummy node <0,0,0> when created.
    
    KruskalMST(int n)
    {
        numNodes = n;
        inWhichSet = new int [n+1];
        for(int i=1; i<n+1; i++)
        {
            inWhichSet[i] = i;
        }
        numSets = numNodes;
        totalMSTCost = 0;
        MSTofG = new undirectedEdge();
        edgeListHead = new undirectedEdge();
    }

    ~KruskalMST()
    {
        delete[] inWhichSet;
        delete[] MSTofG;
        delete[] edgeListHead;
    }

    void insertEdge(undirectedEdge *edge, undirectedEdge *edgeListHead) // inserting edge into the list of edgeListHead in ascending order using insertion sort.
    {
        undirectedEdge* current=edgeListHead;
        if(current->next == NULL)
        {
            current->next = edge;
        }
        else
        {
            while(current->next != NULL && current-> next->edgeCost < edge->edgeCost)
            {
                current = current->next;
            }
            undirectedEdge* swap = current->next;
            current->next = edge;
            edge->next = swap;
        }
    }

    undirectedEdge* removedEdge(undirectedEdge* edgeListHead) // removes *and* returns the front edge node of edgeListHead
    {
        undirectedEdge* current = edgeListHead->next;
        edgeListHead->next = current->next;
        return current;
    }

    void pushEdge(undirectedEdge *edge, undirectedEdge* MSTofG) // push edge node on the top of MSTofG
    {
        undirectedEdge* current = MSTofG;
        while(current->next != NULL)
        {
        current = current->next;
        }
        edge->next=current->next;
        current->next = edge;
    }

    void merge2Sets(int node1,int node2) // modify inWhichSet (node2) to node1 if node1 is smaller the node2, otherwise
    // do the opposite, so that node1 and node2 are in the same set.
    {
        if(inWhichSet[node1] < inWhichSet[node2])
        {
            //inWhichSet[node2] = inWhichSet[node1];
            int swap = inWhichSet[node2];
            
            for(int i=1;i<numNodes+1;i++)
            {
                if(inWhichSet[i] == swap)
                {
                    inWhichSet[i] = inWhichSet[node1];
                }
            }
        }
        else
        {
            //inWhichSet[node1] = inWhichSet[node2];
            int swap = inWhichSet[node1];
            for(int i=1; i< numNodes+1;i++)
            {
                if(inWhichSet[i] == swap)
                {
                    inWhichSet[i] = inWhichSet[node2];
                }
            }
        }
    }

    void printSet(int* inWhichSet, ofstream &outFile2) // print the inWhichSet array to argv[3]
    {
        outFile2 << "_____________" <<endl <<endl;
        outFile2 << "inWhichSet: " << endl;
        for(int i=1; i<numNodes+1; i++)
        {
            //outFile2 << "inWhichSet[" << i<< "] " << inWhichSet[i] << endl;
            outFile2 << inWhichSet[i] << " " ;
        }
        outFile2 << endl;
        //outFile2 << endl;
    }

    void printList (undirectedEdge* edgeListHead, ofstream &outFile2) // print the information in nodes <Ni, Nj, edgeCost> in the given linked list to argv[3]
    // Format: listHead <0, 0, 0> <N1, N1, edgeCost> <N2, N2, edgeCost> â€¦
    {
        //undirectedEdge* edgelistHead
        undirectedEdge *current = edgeListHead;
        while(current !=NULL)
        {
            if(current->next == NULL)
            {
                outFile2 << "<"<< current->Ni <<","<< current->Nj <<","<<
                current->edgeCost << ">";
                outFile2 << endl;
            }
            else
            {
                outFile2 << "<" <<current->Ni<< "," <<current->Nj << ","<<current->edgeCost<<">" << endl;
            }
            current = current->next;
        }
        outFile2 << endl;
    }
};

int main(int argc, char** argv) 
{
    ofstream outFile1, outFile2;

    outFile1.open(argv[2]);
    outFile2.open(argv[3]);
    
    ifstream inFile;
    inFile.open(argv[1]);
    
    int numNodes, x,y,cost;
    inFile >> numNodes;
    KruskalMST *kr = new KruskalMST(numNodes);
    kr->printSet(kr->inWhichSet, outFile2);
    undirectedEdge *newEdge;
    
    while(!inFile.eof())
    {
        inFile >> x;
        inFile >> y;
        inFile >> cost;
        newEdge = new undirectedEdge(x,y,cost);
        kr->insertEdge(newEdge, kr->edgeListHead);
        kr->printList(kr->edgeListHead, outFile2);
    }
    
    undirectedEdge *nextEdge;
    while(kr->numSets != 1)
    {
        do
        {
            nextEdge = kr->removedEdge(kr->edgeListHead);
        }

        while(kr->inWhichSet[nextEdge->Ni] == kr->inWhichSet[nextEdge->Nj]);
        kr->pushEdge(nextEdge, kr->MSTofG);
        kr->totalMSTCost += nextEdge->edgeCost;
        kr->merge2Sets(nextEdge->Ni,nextEdge->Nj); //check'
        kr->numSets--;
        kr->printSet(kr->inWhichSet, outFile2);
        kr->printList(kr->MSTofG, outFile2);
    }
    
    outFile1 << "Entire MSTofG with Respective Cost: " << endl;
    kr->printList(kr->MSTofG,outFile1);
    outFile1 << "Total Cost: " << kr->totalMSTCost << endl;
    //kr->~KruskalMST();
   
    inFile.close();
    outFile1.close();
    outFile2.close();


    return 0;
}
