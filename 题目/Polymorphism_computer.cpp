#include<iostream>
#include<string>
using namespace std;

class cpu
{
public:
    virtual void calculate()=0;
};

class gpu
{
public:
    virtual void display()=0;
};

class ram
{
public:
    virtual void storage()=0;
};

class amd:public cpu
{
public:
    void calculate()
    {
        cout<<"AMD��CPU��ʼ������"<<endl;
    }
};

class intel:public cpu
{
public:
    void calculate()
    {
        cout<<"INTEL��CPU��ʼ������"<<endl;
    }
};


class N:public gpu
{
public:
    void display()
    {
        cout<<"NUDIA���Կ���ʼ��ʾ��"<<endl;
    }
};

class A:public gpu
{
public:
    void display()
    {
        cout<<"AMD���Կ���ʼ��ʾ��"<<endl;
    }
};

class hynix:public ram
{
public:
    void storage()
    {
        cout<<"Hynix���ڴ�����ʼ�洢��"<<endl;
    }
};

class crucial:public ram
{
public:
    void storage()
    {
        cout<<"Crucial���ڴ�����ʼ�洢��"<<endl;
    }
};


class computer
{
private:
    cpu* m_c;
    gpu* m_g;
    ram* m_r;

public:
    computer(cpu* c,gpu* g,ram* r)
    {
        m_c=c;
        m_g=g;
        m_r=r;
    }

    void start()
    {
        m_c->calculate();
        m_g->display();
        m_r->storage();
    }

    ~computer()
    {
        if(m_c!=nullptr)
        {
            delete m_c;
            m_c=nullptr;
        }
        if(m_g!=nullptr)
        {
            delete m_g;
            m_g=nullptr;
        }
        if(m_r!=nullptr)
        {
            delete m_r;
            m_r=nullptr;
        }
    }
};

void test()
{
    cpu* a1=new amd;
    gpu* g1=new N;
    ram* r1=new hynix;

    cout<<"��һ̨���Կ�ʼ��װ"<<endl;
    computer* com1=new computer(a1,g1,r1);
    com1->start();
    cout<<endl;

    cpu* a2=new amd;
    gpu* g2=new A;
    ram* r2=new crucial;

    cout<<"�ڶ�̨���Կ�ʼ��װ"<<endl;
    computer* com2=new computer(a2,g2,r2);
    com2->start();   
    cout<<endl;

    cpu* a3=new intel;
    gpu* g3=new N;
    ram* r3=new hynix;

    cout<<"����̨���Կ�ʼ��װ"<<endl;
    computer* com3=new computer(a3,g3,r3);
    com3->start();
    cout<<endl;

    delete com1;
    delete com2;
    delete com3;
}

int main()
{
    test();

    system("pause");
    return 0;
}

//
// Created by Faye on 2025-1-27
//