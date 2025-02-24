#include<iostream>
using namespace std;

template<class T>
void my_swap(T& a,T& b)
{
    T temp=a;
    a=b;
    b=temp;
}


void func()
{
    cout<<"func()"<<endl;
}

void test()
{
    int a=10;
    int b=20;

    my_swap(a,b);
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    func();
}

int main()
{
    test();

    system("pause");
    return 0;
}

//
// Created by Faye on 25-2-2.
//