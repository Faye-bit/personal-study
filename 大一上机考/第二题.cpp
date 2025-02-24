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
    int n;
    cin>>n;
    
    if(n>=11)
    {
        for(int i=1;i<=n;i++)
        {
        if(i==11)
            {
                cout<<i;
            }

        else if(i>11&&i%10==1&&isPrime(i))
            {
                cout<<" "<<i;
            }
        }
        cout<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    

    system("pause");
    return 0;
}