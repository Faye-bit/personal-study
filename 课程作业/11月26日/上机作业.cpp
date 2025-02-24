#include<iostream>
#include<cmath>
using namespace std;

bool IsPrime(int x)
{
    if(x==1)
    {
        return false;
    }
    else if(x<=3)
    {
        return true;
    }
    else if(x%2==0||x%3==0)
    {
        return false;
    }
    else
    {
        for(int i=5;i<=sqrt(x);i+=6)
        {
            if(x%i==0||x%(i+2)==0)
            {
                return false;
            }
        }
        return true;
    }
}

int Sort(int (&c)[10])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9-i;j++)
        {
            if(c[j]<c[j+1])
            {
                int temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
            }
        }
    }
}

int main()
{
    int a[5]={19,24,40,37,11};
    int b[5]={3,17,9,7,20};
    int c[10]={0};
    int n=0;

    for(int i=0;i<5;i++)
    {
        if(IsPrime(a[i]))
        {
            c[n]=a[i];
            n++;
        }
    }
    for(int i=0;i<5;i++)
    {
        if(IsPrime(b[i]))
        {
            c[n]=b[i];
            n++;
        }
    }
    cout<<endl;
    
    cout<<n<<endl;
    Sort(c);
    for(int i=0;i<n;i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}