#include <iostream>
#include <fstream>
using namespace std;

class BucketS
{
    public:
    int count;
    int maxInt;
    int* BucketAry;
    BucketS(int count1, int max)
    {
        count = count1;
        maxInt = max;
        BucketAry = new int[maxInt+1];
        for(int i=0; i<=maxInt+1; i++)
        {
            BucketAry[i] = 0;
        }
    }
};
int main(int argc, char** argv)
{
    ofstream outFile1, outFile2;
    ifstream inFile1, inFile2;
    inFile1.open(argv[1]);
    outFile1.open(argv[2]);
    int data;
    int maxI;
    int count=0;
    while(!inFile1.eof())
    {
        inFile1 >> data;
        if(data > maxI)
        {
            maxI = data;
        }
        count++;
    }
    BucketS *bkt = new BucketS(count, maxI);
    inFile1.close();
    inFile2.open(argv[1]);
    int idex;
    outFile1 << "Here is the input before performing Bucket-Sort: " << endl;
    while(!inFile2.eof())
    {
        inFile2 >> data;
        idex = data;
        outFile1 << idex << " ";
        bkt->BucketAry[idex]++;
    }
    outFile1 << endl << endl;
    outFile1 << "Here is the output after performing Bucket-Sort: " << endl;
    for(int i=0; i<= bkt->maxInt+1; i++)
    {
        while(bkt->BucketAry[i] != 0)
        {
            if(bkt->BucketAry[i] > 0)
            {
                outFile1 << i << " ";
            }
            bkt->BucketAry[i]--;
        }
    }
    inFile2.close();
    outFile1.close();
    return 0;
}
