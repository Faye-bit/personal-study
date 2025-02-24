#include<iostream>
using namespace std;

int main()
{
    int y,m,d;
    cin>>y>>m>>d;

    int n=0;
    for(int i=1900;i<y;i++)
    {
        if((i%4==0 && i%100!=0)||i%400==0)
        {
            n+=366;
        }
        else
        {
            n+=365;
        }

    }

    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=0;i<m-1;i++)
    {
        n+=month[i];
    }
    if(((y%4==0 && y%100!=0) || y%400==0)&&m>2)
    {
        n++;
    }

    n+=d;
    
    int x=n%7;
    if(x==0)
    {
        x=7;
    }
    cout<<x<<endl;

    system("pause");
    return 0;
}