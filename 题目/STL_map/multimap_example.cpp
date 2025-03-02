#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
using namespace std;

#define CEHUA 0
#define MEISU 1
#define YANFA 3

//员工类
class worker
{
private:
    string m_name;
    int m_salary;

public:
    worker(string name,int salary)
    {
        m_name=name;
        m_salary= salary;
    }

    string getn()
    {
        return m_name;
    }

    int gets()
    {
        return m_salary;
    }
};

//先用vector初始化员工列表，并存放好
//再随机分配部分，改为用map存放
//再讲map遍历打印出来
void go()
{
    vector<worker> v;
    string id ="ABCDEFGHIJ";
    for(int i=0;i<10;i++)
    {
        string name="员工";
        name+=id[i];
        int salary=rand()%10000+10000;

        v.push_back(worker(name,salary));
    }

    multimap<int,worker> m;
    for(vector<worker>::iterator it=v.begin();it!=v.end();it++)
    {
        int department = rand()%3;
        m.insert(make_pair(department,*it));
    }

    cout<<"策划部门:"<<endl;
    int count=m.count(0);
    multimap<int,worker>::iterator pos=m.find(0);
    int index=0;
    for(;pos!=m.end()&&index<count;index++,pos++)
    {
        cout<<"姓名:"<<pos->second.getn()<<"  "<<"工资:"<<pos->second.gets()<<endl;
    }

    cout<<"美术部门:"<<endl;
    count=m.count(1);
    pos=m.find(1);
    index=0;
    for(;pos!=m.end()&&index<count;index++,pos++)
    {
        cout<<"姓名:"<<pos->second.getn()<<"  "<<"工资:"<<pos->second.gets()<<endl;
    }

    cout<<"研发部门:"<<endl;
    count=m.count(2);
    pos=m.find(2);
    index=0;
    for(;pos!=m.end()&&index<count;index++,pos++)
    {
        cout<<"姓名:"<<pos->second.getn()<<"  "<<"工资:"<<pos->second.gets()<<endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    go();

    return 0;
}