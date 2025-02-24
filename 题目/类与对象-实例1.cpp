#include<iostream>
using namespace std;

class student 
{
    public:

    string name;
    string id;

    void show()
    {
        cout<<"Student's name:"<<name<<endl;
        cout<<"School Id:"<<id<<endl;
    }

    void Setname(string t_name)
    {
        name=t_name;
    }

    void Setid(string t_id)
    {
        id=t_id;
    }
};

int main()
{
    student stu;
    
    //cin>>stu.name>>stu.id;
    //cout<<"Student's name:"<<stu.name<<endl;
    //cout<<"School Id:"<<stu.id<<endl;

    string t_name;
    cin>>t_name;
    stu.Setname(t_name);

    string t_id;
    cin>>t_id;
    stu.Setid(t_id);

    stu.show();

    system("pause");
    return 0;
}