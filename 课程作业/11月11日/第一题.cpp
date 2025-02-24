#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
    int max=INT_MIN;
    int m;
    for(int i=0;i<3;i++)
    {
        cin>>m;
        if(m>=max)
        {
            max=m;
            
        }
        cout<<endl;
    }

    cout<<max<<endl;
}