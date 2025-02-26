#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

class person
{
public:
    string m_name;
    int m_age;
    int m_height;

    person(string name,int age,int height):m_name(name),m_age(age),m_height(height) {}
};

bool compare(person p1,person p2)
{
    // if(p1.m_age>p2.m_age) return true;
    // else if(p1.m_age=p2.m_age&&p1.m_height>p2.m_height) return true;
    // else return false;
    if(p1.m_age!=p2.m_age) return p1.m_age > p2.m_age;
    if(p1.m_height!=p2.m_height) return p1.m_height>p2.m_height;
}

void test()
{
    list<person> l;
    person p1("lda",18,180);
    l.push_back(p1);
    person p2("pmx",19,179);
    l.push_back(p2);
    person p3("jcl",17,170);
    l.push_back(p3);
    person p4("msy",17,180);
    l.push_back(p4);
    person p5("ygl",17,175);
    l.push_back(p5);

    l.sort(compare);

    for(list<person>::iterator it=l.begin();it!=l.end();it++)
    {
        cout<<it->m_name<<" "<<it->m_age<<" "<<it->m_height<<endl;
    }

}

int main()
{
    test();

    return 0;
}
