#include"template_array.hpp"
#include<iostream>
using namespace std;

class person
{
private:
    int m_age;

public:
    person()
    {}
    person(int age):m_age(age){};

    int getage()
    {
        return m_age;
    }
};

void test01()
{
    myarray<int> a(10);
    myarray<char> b(10);
    for(int i=0;i<a.getcapacity();i++)
    {
        int val1;
        cin>>val1;
        a.push_back(val1);
    }

    for(int i=0;i<b.getcapacity();i++)
    {
        char val2;
        cin>>val2;
        b.push_back(val2);
    }

    for(int i=0;i<a.getsize();i++)
    {
        cout<<a[i]<<"  ";
        cout<<b[i]<<"  ";
    }

    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        a.pop_back();
        b.pop_back();
    }

    for(int i=0;i<a.getsize();i++)
    {
        cout<<a[i]<<"  ";
        cout<<b[i]<<"  ";
    }
}

void test02()
{
    myarray<person> c(10);
    for(int i=0;i<c.getcapacity();i++)
    {
        int age;
        cin>>age;
        c.push_back(person(age));
    }

    for(int i=0;i<c.getsize();i++)
    {
        cout<<c[i].getage()<<"  ";
    }

    myarray<person> d(c);

    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        c.pop_back();
    }

    for(int i=0;i<c.getsize();i++)
    {
        cout<<c[i].getage()<<"  ";
    }

    cout<<endl;

    for(int i=0;i<d.getsize();i++)
    {
        cout<<d[i].getage()<<"  ";
    }

}

int main()
{
    test02();

    system("pause");
    return 0;
}

//
//Created by Faye on 25-2-5
//