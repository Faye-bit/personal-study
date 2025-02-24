#include<iostream>
using namespace std;
const int n=99;

template<class T>
void myswap(T& a,T& b)
{
    T temp=a;
    a=b;
    b=temp;
}

template<class T>
void mysort(T a[n],int len)
{
    for(int i=0;i<len;i++)
    {
        int max=i;
        for(int j=i+1;j<len;j++)
        {
            if(a[j]>a[max])
            {
                max=j;
            }
        }
        if(i!=max)
        {
            myswap(a[i],a[max]);
        }
    }
}

int main()
{
    int len=0;
    cin>>len;

    int a[n];
    for(int i=0;i<len;i++)
    {
        cin>>a[i];
    }

    mysort(a,len);

    for(int i=0;i<len;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}


//
//Created by Faye on 25-2-2