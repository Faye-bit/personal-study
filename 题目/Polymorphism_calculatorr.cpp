#include<iostream>
#include<string>
using namespace std;

class calculator
{
public:
    virtual void get_result(){}

    int m_num1;
    int m_num2;
    int temp=0;

    calculator(int n1,int n2)
    {
        m_num1=n1;
        m_num2=n2;
    }
};

class add:public calculator
{
public:
    void get_result()
    {
        temp=m_num1+m_num2;
        cout<<"="<<temp<<endl;
    }

    add(int n1,int n2):calculator(n1,n2){}
};

class sub:public calculator
{
public:
    void get_result()
    {
        temp=m_num1-m_num2;
        cout<<"="<<temp<<endl;
    }

    sub(int n1,int n2):calculator(n1,n2){}
};

class mul:public calculator
{
public:
    void get_result()
    {
        temp=m_num1*m_num2;
        cout<<"="<<temp<<endl;
    }

    mul(int n1,int n2):calculator(n1,n2){}
};

void test()
{
    while(1)
    {
        int n1,n2;
        char op;
        cin>>n1>>op>>n2;

        calculator* c;

        if(op=='+'){c=new add(n1,n2);}
        else if(op=='-'){c=new sub(n1,n2);}
        else if(op=='*'){c=new mul(n1,n2);}
        else{cout<<"get wrong!"<<endl;}

        c->get_result();

        delete c;
    }
}

int main()
    {
      test();

      system("pause");
      return 0;
    }

//
// Created by Faye on 25-1-24.
//
