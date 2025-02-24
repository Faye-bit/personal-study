#include<iostream>
#include<iomanip>
using namespace std;

void addition(int (&arr)[10][10],int N)
{
    int temp[10][10];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>temp[i][j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            arr[i][j]=arr[i][j]+temp[i][j];
        }
    }
}

void subtraction(int (&arr)[10][10],int N)
{
    int temp[10][10];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>temp[i][j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            arr[i][j]=arr[i][j]-temp[i][j];
        }
    }
}

int main()
{
    int arr[10][10]={0};
    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>arr[i][j];
        }
    }

    while(1)
    {
        char x;
        cin>>x;

        if(x=='+')addition(arr,N);
        if(x=='-')subtraction(arr,N);
        if(x=='#')break;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<setw(5)<<arr[i][j];
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}