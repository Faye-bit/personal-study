#include<iostream>
#include<string>
using namespace std;

class Building;
class goodgay
{
public:
    goodgay();
    ~goodgay();
    void visit();

private:
    Building *building;
};

class Building
{
    friend void goodgay::visit();

private:
    string m_livingroom;
    string m_bedroom;

public:
    Building();
};

goodgay::goodgay()
{
    building = new Building;
}

goodgay::~goodgay()
{
    delete building;
}

void goodgay::visit()
{
    cout<<"����"<<building->m_bedroom<<endl;
    cout<<"����"<<building->m_livingroom<<endl;
}

Building::Building()
{
    m_livingroom="����";
    m_bedroom="����";
}

void test01()
{
    goodgay gg;
    gg.visit();
}

int main()
{
    test01();

    system("pause");
    return 0;
}

//
// Created by Faye on 25-1-20.
//
