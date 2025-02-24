#include<iostream>
#include<string>
using namespace std;

class drinking
{
public:
    void fisrt()
    {
        cout<<"煮水"<<endl;
    }

    virtual void second()=0;

    void third()
    {

        cout<<"倒入杯中"<<endl;
    }

    virtual void last()=0;

};

class coffee:public drinking
{
public:
    void second() override
    {
        cout<<"冲泡咖啡"<<endl;
    }

    void last() override
    {
        cout<<"加糖和牛奶"<<endl;
    }

    coffee()
    {
        fisrt();
        second();
        third();
        last();
        cout<<"咖啡已制作完成"<<endl;
    }

};

class tea:public drinking
{
public:
    void second() override
    {
        cout<<"冲泡茶叶"<<endl;
    }

    void last() override
    {
        cout<<"加柠檬"<<endl;
    }

    tea()
    {
        fisrt();
        second();
        third();
        last();
        cout<<"茶已制作完成"<<endl;
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