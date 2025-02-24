#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double e;
    cin>>e;

    double n=2.;
    int i=1;
    
    while(1)
    {
        double term = (2.*i/(2*i-1)*2*i/(2*i+1));
        n *= term;

        if(n>=e)
        {
            n /= term;
            i--;
            break;
        }
    
        i++;
    }
    
    cout<<fixed<<setprecision(7)<<n<<"  ";
    cout<<i<<endl;

    system("pause");
    return 0;
}