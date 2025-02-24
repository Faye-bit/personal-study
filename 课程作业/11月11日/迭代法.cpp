#include<iostream>
using namespace std;

int main()
{
    double a;
    cin>>a;

    double x=a/2;
    double y;

    while(true)
    {
        y=(x+a/x)/2;
        if((x-y)<1e-5)
        {
            break;
        }
        x=y;
    }

    cout<<x<<" "<<y<<endl;

    system("pause");
    return 0;
}