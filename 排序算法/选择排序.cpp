#include<iostream>
using namespace std;

int a[10];

int main()
{
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }

    int k;
    
    for(int i=0;i<10;i++)
    {  
        k=i;
        for(int j=i+1;j<10;j++)
        {
            if(a[k]>a[j])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            int temp=a[i];
            a[i]=a[k];
            a[k]=temp;
        }
        
    }

    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }

    system("pause");
    return 0;
}