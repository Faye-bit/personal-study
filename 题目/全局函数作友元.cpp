#include <iostream>
using namespace std;

class building
{
private:
    string m_livingroom;
    string m_bedroom;
public:
    building()
    {
        m_livingroom = "¿ÍÌü";
        m_bedroom = "ÎÔÊÒ";
    }

    friend void goodgay(building *b);
};

void goodgay(building *b)
{
    cout<<b->m_livingroom<<endl<<b->m_bedroom<<endl;
}

int main()
{
    building b;
    goodgay(&b);

    system("pause");
    return 0;
}
//
// Created by Faye on 25-1-18.
//
