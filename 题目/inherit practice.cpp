#include<iostream>
#include<string>
using namespace std;

class Person
{
protected:
    string m_name;
    int m_age;
public:
    Person(){}
    Person(string name,int age):m_name(name),m_age(age){}
    void display_info()
    {
       cout<<"Name:"<<m_name<<endl;
       cout<<"Age:"<<m_age<<endl;
    }
};

class Student:public Person
{
private:
    int m_studentID;
public:
    Student(string name,int age,int id):Person(name,age),m_studentID(id){}

    void display_info()
    {
       cout<<"Name:     "<<m_name<<endl;
       cout<<"Age:      "<<m_age<<endl;
       cout<<"StudentID:"<<m_studentID<<endl; 
    }
};

void test01()
{
    Student stu("ben",18,123);
    stu.display_info();
}

int main()
{
    test01();

    system("pause");
    return 0;
}

//
// Created by Faye on 25-1-24.
//
