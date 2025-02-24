#include<iostream>
using namespace std;

void find(int ar[8][8])
{
    int n=0;
    for(int i=1;i<7;i++)
    {
        for(int j=1;j<7;j++)
        {
            if(ar[i][j]>ar[i][j-1] &&ar [i][j]>ar[i][j+1] && ar[i][j]<ar[i-1][j] && ar[i][j]<ar[i+1][j])
            {
                cout<<"saddle point: "<<ar[i][j]<<" i="<<i<<" j="<<j<<endl;
                n++;
            }
            if(ar[i][j]<ar[i][j-1] &&ar [i][j]<ar[i][j+1] && ar[i][j]>ar[i-1][j] && ar[i][j]>ar[i+1][j])
            {
                cout<<"saddle point: "<<ar[i][j]<<" i="<<i<<" j="<<j<<endl;
                n++;
            }
        }
    }
    if(n==0)
    {
        cout<<"this matrix has no saddle point。";
    }
}

int main()
{
    int ar[8][8] = 
    {
    {0,3,5,7,11,13,17,19},
    {1,2,3,9,16,17,21,18},
    {3,5,4,14,22,19,26,15},
    {5,11,9,6,16,15,23,12},
    {9,12,18,7,8,9,10,11},
    {7,6,15,14,13,10,9,10},
    {13,4,17,24,20,18,12,12},
    {15,10,9,8,25,19,16,14}
    };
    
    find(ar);

    system("pause");
    return 0;
}