#include<iostream>
using namespace std;

int gcd(int m, int n)
{
    if(n>m)
    {
        int temp=m;
        m=n;
        n=temp;
    }
    while(n!=0)
    {
    int r;
    r=m%n;
    m=n;
    n=r;
    }

    return m;
}

int main()
{
    int m,n;
    cin>>m>>n;
    int x=gcd(m,n);

    int lcm=m*n/x;
    cout<<lcm<<endl;

    system("pause");
    return 0;
}
