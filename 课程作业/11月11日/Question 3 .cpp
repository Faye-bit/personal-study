#include<iostream>
using namespace std;

int main()
{
    int N=0;
    cin>>N;

    for(int n=100;n<=N;n++)
    {
        int a= n/100;
        int b= n%10;
        int c= (n/10)%10;

        if(a*a*a+b*b*b+c*c*c==n)
        {
            cout<<n<<endl;
        }
    }

    system("pause");
    return 0;
}