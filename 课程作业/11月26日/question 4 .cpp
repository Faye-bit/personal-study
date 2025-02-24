#include<iostream>
using namespace std;

int main()
{
    int arr[100];
    
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    int b;
    cin>>b;
    for(int j=a;j<a+b;j++)
    {
        cin>>arr[j];
    }

    for(int i=0;i<a+b-1;i++)
    {
        for(int j=0;j<a+b-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    for(int k=0;k<a+b;k++)
    {
        cout<<arr[k]<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}