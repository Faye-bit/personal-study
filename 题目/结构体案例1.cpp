#include<iostream>
#include<string>
using namespace std;

struct student 
{
    string stu_name;
    int score;
};

struct teacher
{
    string tea_name;
    student stu[5];
};

struct teacher tea[3];

int main()
{
    for(int i= 0;i<3;i++)
    {
        cin>>tea[i].tea_name;
        for(int j=0;j<5;j++)
        {
            cin>>tea[i].stu[j].stu_name>>tea[i].stu[j].score;
        }
            
        
    }

    for(int i=0;i<3;i++)
    {
        cout<<tea[i].tea_name<<endl;
        for(int j=0;j<5;j++)
        {
            cout<<tea[i].stu[j].stu_name<<" "<<tea[i].stu[j].score<<endl;
        }
    }

    system("pause");
    return 0;
}