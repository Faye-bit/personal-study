#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=10001;

/*
int main()
{
    int a[MAXN];
    int n=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int max=a[0];
    int m;

    for(int j=0;j<n;j++)
    {
        if(a[j]>max)
        {
            max= a[j];
            m=j+1;
        }
    }

    cout<<m<<endl;

    system("pause");
    return 0;
}
*/
int a[MAXN];

int main()
{
    int n=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        a[i]=1;
    }

    int k=0;
    cin>>k;

    for(int j=2;j<=k;j++)
    {
        for(int i=1;i<n+1;i++)
        {
            if(i%j==0)
            {
                a[i-1]=!a[i-1];
            }
        }
        
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            cout<<i+1<<" ";
        }
    }

    system("pause");
    return 0;
}