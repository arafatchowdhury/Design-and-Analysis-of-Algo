#include <iostream>
#include <fstream>
using namespace std;

class node
{
    public:
    int colorID;
    node* next;
    node()
    {
    colorID = 0;
    next =NULL;
    }
    node(int ID)
    {
    colorID = ID;
    next = NULL;
    }
};

class graphColoring
{
    public:
    int** adjacencyMatrix;
    node* usedColorTop;
    int newColor;
    int numNode;
    graphColoring(int nNodes)
    {
        numNode = nNodes;
        usedColorTop = new node();
        newColor = 0;
        adjacencyMatrix = new int*[numNode+1];
        for(int i=1;i<numNode+1;i++)
        {
        adjacencyMatrix[i] = new int[numNode+1];
        }
        for(int i= 1; i < numNode+1; i++)
        {
        for(int j = 1; j < numNode+1; j++)
        {
        adjacencyMatrix[i][j] = 0;
        }
        }
    }

    // read from input and fill the adjacentcy Matrix
    void loadMatrix(int ni, int nj)
    {
        adjacencyMatrix[ni][nj] = 1;
        adjacencyMatrix[nj][ni] = 1;
    }

    // it return 0 if there is no adjacent nodes use the color
    int checkAdjacent(int nodeID, int color)
    {
        for(int i = 1; i<numNode; i++)
        {
            if(adjacencyMatrix[nodeID][i] == 1 && adjacencyMatrix[i][i]==color)
            return 1;
        }
        return 0;
    }

    // push the newColor on top of the linked list stack.
    void pushUsedColor(int color)
    {
        node *newNode = new node(color);
        if (usedColorTop->next == NULL)
        {
            usedColorTop->next = newNode;
        }
        else
        {
            newNode->next = usedColorTop->next;
            usedColorTop->next = newNode;
        }
    }

    int findUsedColor(int currentNode)
    {
        node *current = usedColorTop->next;
        while(current != NULL)
        {
            if(checkAdjacent(currentNode, current->colorID) == 1)
            {
                current = current->next;
            }
            else
            return current->colorID;
        }
        return 0;
    }

    //displayImage()
    void displayImage(ofstream &outFile)
    {
        for(int i = 1; i < numNode+1; i++)
        {
            for(int j = 1 ; j < numNode+1; j++)
            {
                outFile << adjacencyMatrix[i][j];
            }
            outFile<<endl;
        }
        outFile<<endl;
    }

    bool checkUncolored()
    {
        int count = 0;
        for (int i = 1; i < numNode + 1; i++)
        {
            if (adjacencyMatrix[i][i] != 0)
            {
                count++;
                if (count == numNode) 
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {

    ifstream inFile;
    inFile.open(argv[1]);
    ofstream outFile;
    outFile.open(argv[2]);

    int numNode,n_i, n_j;
    inFile >> numNode;
    graphColoring *gr = new graphColoring(numNode);

    while(!inFile.eof())
    {
        inFile >> n_i;
        inFile >> n_j;
        gr->loadMatrix(n_i,n_j);
    }
    
    gr->displayImage(outFile);
    gr->newColor = 0;
    int currentNode = 0;
    int usedColor;

    while(gr->checkUncolored())
    {
        currentNode++;
        gr->displayImage(outFile);
        usedColor = gr->findUsedColor(currentNode);
        if(usedColor > 0)
        {
            gr->adjacencyMatrix[currentNode][currentNode] = usedColor;
        }
        else
        {
            gr->newColor++;
            gr->adjacencyMatrix[currentNode][currentNode] = gr->newColor;
            gr->pushUsedColor(gr->newColor);
        }
    }

    outFile << "Number of colors used is: " << gr->newColor << endl;
    gr->displayImage(outFile);
    
    inFile.close();
    outFile.close();

    return 0;
}
