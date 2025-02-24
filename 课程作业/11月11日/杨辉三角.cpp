#include<iostream>
using namespace std;

int main()
{
    int arr[10][10];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            arr[i][j]=0;
        }
    }
    for(int i=0;i<9;i++)
    {
        arr[i][0]=1;
        for(int j=0;j<9;j++)
        {
            arr[i+1][j+1]=arr[i][j]+arr[i][j+1];
        }
    }
    arr[9][0]=1;

    for(int i =0;i<10;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        
    }

    system("pause");
    return 0;
}