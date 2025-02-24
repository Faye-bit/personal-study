#include<iostream>
using namespace std;

class Person
{
   friend ostream &operator<<(ostream &cout,const Person &p);
   friend Person operator+(const Person &p1,const Person &p2);

private:
    int m_A;
    int m_B;
    int* m_C;

    /*Person operator+(Person &p)
    {
        Person temp(0,0);
        temp.m_A = this->m_A+p.m_A;
        temp.m_B = this->m_B+p.m_B;

        return temp;
    }*/
public:
    Person(int a,int b)
    {
        m_A=a;
        m_B=b;
        m_C=nullptr;
    }

    Person(const Person &p)
    {
        m_A=p.m_A;
        m_B=p.m_B;
        m_C=nullptr;
    }

    Person& operator++();
    Person operator++(int);
    Person& operator=(int c);
    Person& operator=(const Person& p);
    bool operator==(const Person& p);
    bool operator!=(const Person& p);
    /*{
        m_A++;
        m_B++;

        return *this;
    }*/
   /*/*int getm_A () const
    {
      return m_A;
    }*/

   int* getm_C() const
    {
      return m_C;
    }

};

Person operator+(const Person &p1,const Person &p2)
{
    Person temp(0,0) ;
    temp.m_A=p1.m_A+p2.m_A;
    temp.m_B=p1.m_B+p2.m_B;

    return temp;
}

ostream& operator<<(ostream &cout,const Person &p)
{
    cout<<"m_A="<<p.m_A<<" m_B="<<p.m_B;

    return cout;
}

Person& Person::operator++()
{
    m_A++;
    m_B++;

    return *this;
}

Person Person::operator++(int)
{
     Person temp(*this);

    ++m_A;
    ++m_B;

    return temp;
}

Person& Person::operator=(int c)
{
     m_C=new int (c) ;

    return *this;
}

Person& Person::operator=(const Person& p)
{
     if (this==&p)
     {
         return *this;
     }
     if (this->m_C != nullptr)
     {
         delete m_C;
         m_C=nullptr;
     }
    m_C=new int (*p.getm_C());

    return *this;
}

bool Person::operator==(const Person &p)
{
    if (m_A==p.m_A&&m_B==p.m_B&&*m_C==*p.m_C)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Person::operator!=(const Person&p)
{
    if (m_A!=p.m_A||m_B!=p.m_B||*m_C!=*p.m_C)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void test01()
{
    Person p1(10,20);
    Person p2(30,40);
    Person p3(p1+p2);

    //cout<<"test01"<<endl;
    //cout<<p3.m_A<<" "<<p3.m_B<<endl;
    cout<<p3<<endl;
    cout<<++p3<<endl;
    cout<<p3++<<endl;
    cout<<p3<<endl;

    p3=1;
    cout<<"*m_C= "<<*p3.getm_C()<<"\n";
    p2=2;
    cout<<"*m_C= "<<*p2.getm_C()<<"\n";
    p3=p2;
    cout<<"*m_C= "<<*p3.getm_C()<<"\n";

    if (p2==p3)
    {
        cout<<"相等"<<endl;
    }
    else
    {
        cout<<"不相等"<<endl;
    }
}

int main()
{
    test01();

    system("pause");
    return 0;
}