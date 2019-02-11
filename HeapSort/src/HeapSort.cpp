#include <iostream>
#include <fstream>
using namespace std;

class HeapSort
{
public:
    int fatherIndex;
    int leftKidIndex;
    int rightKidIndex;
    int midIndex;
    int *heapAry;

    //contructor
    HeapSort(int count)
    {
        heapAry = new int[count+1];
        heapAry[0] = 0;
    }

    //isRoot
    bool isRoot(int index)
    {
        if(index==1)
        {
            return true;
        }
        return false;
    }

    //getRoot
    int getRoot()
    {
        if(heapAry[0] == 0 )
        {
            cout << "Heap is Empty." << endl;
        }
        return heapAry[1];
    }

    //delete Root()
    void deleteRoot()
    {
        heapAry[1] = heapAry[heapAry[0]];
        heapAry[0]--;
    }

    //isLeaf
    bool isLeaf (int father)
    {
        if(2 * father <= heapAry[0] && 2 * father + 1 <= heapAry[0])
            return false;
        else{
            return true;
        }
    }

    //isEmpty()
    bool isEmpty()
    {
        if(heapAry[0] == 0)
            return true;
        return false;
    }

    //printHeap
    void printHeap(ofstream &outFile)
    {
        for(int i = 0; i <= heapAry[0]; i++) //i=1
        {
            outFile << heapAry[i] << " ";
        }
        outFile << endl;
    }

    //findMinKidIndex
    int findMinKidIndex(int fatherIndex)
    {
        leftKidIndex = fatherIndex * 2;
        rightKidIndex = (fatherIndex * 2) + 1;

        if(heapAry[leftKidIndex] <= heapAry[rightKidIndex]) {
            midIndex = leftKidIndex;
        }
        else
        {
            midIndex = rightKidIndex;
        }
        return midIndex;
    }

    //bubble Up
    void bubbleUp(int kidIndex)
    {
        if( isRoot(kidIndex))
            return;
        else
        {
            fatherIndex = kidIndex/2;
            if(heapAry[kidIndex] < heapAry[fatherIndex])
            {
                int swap = heapAry[kidIndex];
                heapAry[kidIndex] = heapAry[fatherIndex];
                heapAry[fatherIndex] = swap;
                bubbleUp(fatherIndex);
            }
        }
    }

    //bubble Down
    void bubbleDown(int fatherIndex)
    {
        if(isLeaf(fatherIndex))
            return;
        else
        {
            midIndex = findMinKidIndex(fatherIndex);

            if(heapAry[midIndex] < heapAry[fatherIndex])
            {
                int swap = heapAry[midIndex];
                heapAry[midIndex] = heapAry[fatherIndex];
                heapAry[fatherIndex] = swap;
                bubbleDown(midIndex);
            }
        }
    }

    //insertData
    void insertOneDataItem(int data)
    {
        heapAry[0]++;
        heapAry[heapAry[0]] = data;
    }

    //buildHeap
    void buildHeap(char** argv, ofstream &outFile1)
    {
        int i;
        ifstream inFile;
        inFile.open(argv[1]);
        try
        {
            while(inFile >> i)
            {
                insertOneDataItem(i);
                int kidIndex = heapAry[0];
                bubbleUp(kidIndex);
                printHeap(outFile1);
            }
        }
        catch(exception &e)
        {
            cout << "Standard exception: " << e.what() << endl;
        }
    }

    //deleteHeap()
    void deleteHeap(ofstream &outFile1, ofstream &outFile2)
    {
        try
        {
            while(!isEmpty())
            {
                outFile2 << getRoot() << endl;
                deleteRoot();
                fatherIndex = 1;
                bubbleDown(fatherIndex);
                printHeap(outFile1);            //debugging purpose
            }
        }
        catch(exception &e)
        {
            cout << "Standard exception: " << e.what() << endl;
        }
    }
};

int main(int argc, char** argv)
{
    ifstream inFile;
    ofstream outFile1, outFile2;

    inFile.open(argv[1]);
    outFile1.open(argv[2]);
    outFile2.open(argv[3]);
    int i;
    int count = 0;

    while(inFile >> i)
    {
        count++;
    }

    HeapSort *heap = new HeapSort(count);
    heap->buildHeap(argv, outFile1);
    heap->deleteHeap(outFile1, outFile2);

    inFile.close();
    outFile1.close();
    outFile2.close();
    return 0;
}
