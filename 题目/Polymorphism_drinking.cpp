#include<iostream>
#include<string>
using namespace std;

class drinking
{
public:
    void fisrt()
    {
        cout<<"��ˮ"<<endl;
    }

    virtual void second()=0;

    void third()
    {

        cout<<"���뱭��"<<endl;
    }

    virtual void last()=0;

};

class coffee:public drinking
{
public:
    void second() override
    {
        cout<<"���ݿ���"<<endl;
    }

    void last() override
    {
        cout<<"���Ǻ�ţ��"<<endl;
    }

    coffee()
    {
        fisrt();
        second();
        third();
        last();
        cout<<"�������������"<<endl;
    }

};

class tea:public drinking
{
public:
    void second() override
    {
        cout<<"���ݲ�Ҷ"<<endl;
    }

    void last() override
    {
        cout<<"������"<<endl;
    }

    tea()
    {
        fisrt();
        second();
        third();
        last();
        cout<<"�����������"<<endl;
    }
};

void test()
{
    drinking* d1=new coffee;
    cout<<endl;
    drinking* d2=new tea;
}

int main()
{
    test();

    system("pause");
    return 0;
}


//
// Created by Faye on 25-1-25 
//