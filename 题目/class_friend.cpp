#include<iostream>
using namespace std;
#include <string>

class Building;
class goodgay
{
private:
    Building *building;

public:
    goodgay();
    ~goodgay();
    void visit();
};

class Building
{
private:
    string m_bedroom;

public:
    string m_livingroom;

    Building();    

    friend class goodgay;
};

goodgay::goodgay()
{
    building= new Building;
}
goodgay::~goodgay()
{
    delete building;
}

Building::Building()
{
    m_livingroom="����";
    m_bedroom="����";
}

void goodgay::visit()
{
    cout<<"�û������ڷ�������"<<building->m_livingroom<<endl;
    cout<<"�û������ڷ�������"<<building->m_bedroom<<endl;
}

int main()
{
    goodgay gg;
    gg.visit();

    system("pause");
    return 0;
}
//
// Created by Faye on 25-1-19.
//
