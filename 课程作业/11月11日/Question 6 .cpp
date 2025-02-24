#include<iostream>
#include<cmath>
using namespace std;

bool isPrime (int x)
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

int main()
{
    int a;
    cin>>a;

    for(int i=1;i<a;i++) 
    {   
        if(isPrime(i))
        {
        if(a%i==0&&a%(i*i)!=0)
        {
            cout<<i<<" ";
        }
        }
    }

    system("pause");
    return 0;
}