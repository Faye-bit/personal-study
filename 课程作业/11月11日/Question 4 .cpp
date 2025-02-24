#include<iostream>
using namespace std;

int main()
{
    int m,n;
    int a,b,c;

    cin>>m>>n;

    for(a=m;a<=n;a++)
    {
        b=a*a;

        if(b>100)
        {
            c=b%100;
        }
        else if(b>10&&b<100)
        {
            c=b%10;
        }
        else if(b>=0&&b<10)
        {
            c=b;
        }

        if(c==a)
        {
            cout<<a<<endl;
        }
    }

    system("pause");
    return 0;
}