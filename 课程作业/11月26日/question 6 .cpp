#include<iostream>
using namespace std;

bool Is(int arr[10][10],int z,int n,int m,int i,int j)
{
    for(int x=0;x<m;x++)
    {
        if(arr[i][x]>arr[i][j])return false;
    }
    for(int y=0;y<n;y++)
    {
        if(arr[y][j]<arr[i][j])return false;
    }
    return true;
}

int main()
{
    int arr[10][10]={0};
    int n,m,l=0;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(Is(arr,arr[i][j],n,m,i,j))
            {
                cout<<arr[i][j]<<" "<<i+1<<" "<<j+1<<endl;
                l++;
            }
        }
    }
    
    if(l==0)cout<<"No answer"<<endl;

    system("pause");
    return 0;
}