#include<iostream>
using namespace std;

int factorial(int n)
{
    int fn=1;

    for(int i=1;i<=n;i++)
    {
        fn*=i;
    }
    
    return fn;
}

int main()
{
    double e=1;
    int n=1;

    while(1)
    {
        //cout<<factorial(n)<<endl;
        double term=1.0/factorial(n);
        e+=term;
        //cout<<1.0/factorial(n)<<endl;
        
        if(term<1e-6)
        {
            break;
        }

        n++;
    }

    cout<<e<<endl;

    system("pause");
    return 0;
}
