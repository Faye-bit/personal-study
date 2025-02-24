#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b>a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while(b!=0)
    {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main()
{
    cout<<"欢迎使用求公因数程序。"<<endl;
    int a ,b;
    cout<<"请给出两个数：";
    cin>>a>>b;

    int c = gcd(a,b);
    cout<<a<<"和"<<b<<"的最大公因数是："<<c<<endl;

    system("pause");
    return 0;
}