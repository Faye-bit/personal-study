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
    cout<<"��ӭʹ������������"<<endl;
    int a ,b;
    cout<<"�������������";
    cin>>a>>b;

    int c = gcd(a,b);
    cout<<a<<"��"<<b<<"����������ǣ�"<<c<<endl;

    system("pause");
    return 0;
}