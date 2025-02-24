#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int a,b,c;
    double s,S;
    cin>>a>>b>>c;
    
    s=((a+b+c)*0.5);
    S=pow((s*(s-a)*(s-b)*(s-c)),0.5);

    
    cout<<fixed<<setprecision(3)<<S<<endl;

    system("pause");
    return 0;
}