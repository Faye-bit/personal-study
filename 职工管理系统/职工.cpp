#include<iostream>
#include<string>
#include<fstream>
using namespace std;


class staff;

class staff_manager
{
private:
    staff** s;
    int ans;

public:
    static void menu()
    {
        cout << "*********************************************" << endl;
	    cout << "*********  欢迎使用职工管理系统！  **********" << endl;
	    cout << "*************  0.退出管理程序   *************" << endl;
	    cout << "*************  1.增加职工信息   *************" << endl;
	    cout << "*************  2.显示职工信息   *************" << endl;
	    cout << "*************  3.删除离职职工   *************" << endl;
	    cout << "*************  4.修改职工信息   *************" << endl;
	    cout << "*************  5.查找职工信息   *************" << endl;
	    cout << "*************  6.按照编号排序   *************" << endl;
	    cout << "*************  7.清空所有文档   *************" << endl;
	    cout << "*********************************************" << endl;
	    cout << endl;
        cout <<"输入对应数字使用相应功能：";
    }

    void read();
    void write() const;

    staff_manager();
    ~staff_manager();

    void add();
    void display() const;
    int find() const;
    void del();
    void modify();
    void search() const;
    void sort();
    void empty();
    static void quit();

    void go()
    {
        while(true)
        {
            menu();
            int choice=0;
            cin>>choice;

            switch(choice)
            {
                case 1:
                {
                    add();
                    break;
                }
                case 2:
                {
                    display();
                    break;
                }
                case 3:
                {
                    del();
                    break;
                }
                case 4:
                {
                    modify();
                    break;
                }
                case 5:
                {
                    search();
                    break;
                }
                case 6:
                {
                    sort();
                    break;
                }
                case 7:
                {
                    empty();
                    break;
                }
                case 0:
                {
                    quit();
                    break;
                }
                default:
                {
                    cout<<"更多功能正在开发中......"<<endl;

                    system("pause");
                    system("cls");
                    break;
                }
            }
        }
    }
};

class staff
{
    friend class staff_manager;
protected:
    int m_id;
    string m_name;
    int m_position;
    virtual void get_position()=0;
    virtual void show()=0;

public:
    virtual ~staff() = default;

    staff(int& t_id,string& t_name,int p):m_id(t_id),m_name(t_name),m_position(p){};
    //virtual ~staff()=0;
};

class employee:public staff
{
    friend class staff_manager;
public:
    void get_position() override
    {
        cout<<"职位：员工  ";
        cout<<"职责：完成经理交给的任务"<<endl;
    }
    void show() override
    {
        cout<<"职工编号："<<this->m_id<<"  ";
        cout<<"职工姓名："<<this->m_name<<"  ";
        this->get_position();
    }

    employee(int& t_id,string& t_name):staff(t_id,t_name,1){};
    //~employee(){}
};

class manager:public staff
{
    friend class staff_manager;
public:
    void get_position() override
    {
        cout<<"职位：经理"<<"  ";
        cout<<"职责：完成总裁交给的任务，并下发任务给员工"<<endl;
    }
    void show() override
    {
        cout<<"职工编号："<<this->m_id<<"  ";
        cout<<"职工姓名："<<this->m_name<<"  ";
        this->get_position();
    }

    manager(int& t_id,string& t_name):staff(t_id,t_name,2){};
    //~manager(){}
};

class boss:public staff
{
    friend class staff_manager;
public:
    void get_position() override
    {
        cout<<"职位：总裁"<<"  ";
        cout<<"职责：管理公司所有事务"<<endl;
    }
    void show() override
    {
        cout<<"职工编号："<<this->m_id<<"  ";
        cout<<"职工姓名："<<this->m_name<<"  ";
        this->get_position();
    }

    boss(int& t_id,string& t_name):staff(t_id,t_name,3){};
    //~boss(){}
};

void staff_manager::add()
{
    int n;
    cout<<"请输入增加职工的数量：";
    cin>>n;

    if(n>0)
    {
        int n_ans=this->ans+n;
        staff** n_s= new staff*[n_ans];

        for(int i=0;i<ans;i++)
        {
            n_s[i]=this->s[i];
        }

        for(int i=0;i<n;i++)
        {
            int t_id;
            string t_name;
            int opt=0;

            cout<<"请输入第"<<i+1<<"名新职工的职工编号：";
            cin>>t_id;
            cout<<"请输入第"<<i+1<<"名新职工的职工姓名：";
            cin>>t_name;
            cout<<"1、员工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、总裁"<<endl;
            cout<<"请选择第"<<i+1<<"名新职工的职工岗位："<<endl;
            cin>>opt;

            switch(opt)
            {
                case 1:
                {
                    n_s[ans+i]=new employee(t_id,t_name);
                    break;
                }
                case 2:
                {
                    n_s[ans+i]=new manager(t_id,t_name);
                    break;
                }
                case 3:
                {
                    n_s[ans+i]=new boss(t_id,t_name);
                    break;
                }
                default:
                {
                    cout<<"输入有误，请重新输入！"<<endl;
                    break;
                }
            }
        }

        if(s!=nullptr)
        {
            delete[] s;
        }

        this->s=n_s;
        this->ans=n_ans;
        write();
        cout<<n<<"名新职工已添加完成！"<<endl;

        system("pause");
        system("cls");
    }
    else
    {
        cout<<"输入有误！"<<endl;
    }

}

void staff_manager::quit()
{
    cout<<"Y.确认      N.取消"<<endl;
    cout<<"是否确认退出职工管理系统？"<<endl;
    char opt;
    cin>>opt;

    if(opt=='y'||opt=='Y')
    {
        cout<<"感谢您的使用！"<<endl;
        system("cls");
        exit(0);
    }
    else
    {
        system("cls");
    }
}

void staff_manager::display() const
{
    if(ans>0)
    {
        for(int i=0;i<ans;i++)
        {
            this->s[i]->show();
        }
    }
    else
    {
        cout<<"暂无职工信息......"<<endl;
    }

    system("pause");
    system("cls");
}

int staff_manager::find() const
{
    int x=-1;

    if (ans>0)
    {
        cout<<"请输入目标职工的姓名："<<endl;
        string input;
        cin>>input;

        for(int i=0;i<ans;i++)
        {
            if(s[i]->m_name==input)
            {
                x=i;
            }
        }
    }
    else
    {
        cout<<"目前还没有任何职工信息，清先添加职工信息"<<endl;
    }

    return x;
}

void staff_manager::del()
{
    int x=find();

    if(x>-1&&ans>0)
    {
        for(int i=x;i<ans-1;i++)
        {
            s[i]=s[i+1];
        }
    }

    delete s[ans-1];
    s[ans-1]=nullptr;
    ans--;
    write();
    cout<<"删除成功！"<<endl;
}

void staff_manager::modify()
{
    int x=find();
    if (x>-1)
    {
        int t_id;
        string t_name;
        int t_position;

        s[x]->show();
        cout<<"这是您要修改的职工信息，是否要继续？\nY.继续       N.取消";
        char opt;
        cin>>opt;

        if (opt=='y'||opt=='Y')
        {
            cout<<"请输入修改后的职工编号：";
            cin>>t_id;
            cout<<"请输入修改后的职工姓名：";
            cin>>t_name;
            cout<<"1.员工\n2.经理\n3.总裁\n";
            cout<<"请选择修改后的职工岗位："<<endl;
            cin>>t_position;

            delete s[x];
            if (t_position==1)
            {
                s[x]=new employee(t_id,t_name);
            }
            else if (t_position==2)
            {
                s[x]=new manager(t_id,t_name);
            }
            else if (t_position==3)
            {
                s[x]=new boss(t_id,t_name);
            }

            write();
            cout<<"已修改完成！"<<endl;

            system("pause");
            system("cls");
        }
    }
}

void staff_manager::search() const
{
    int x=find();
    s[x]->show();

    system("pause");
    system("cls");

}

void staff_manager::sort()
{
    if (ans>0)
    {
        cout<<"1.按职工编号升序排序    2.按职工编号降序排序\n";
        cout<<"请选择排序方式：";
        int opt;
        cin>>opt;

        for (int i=0;i<ans-1;i++)
        {
            for (int j=0;j<ans-i-1;j++)
            {
                if (opt==1)
                {
                    if (s[j]->m_id>s[j+1]->m_id)
                    {
                        staff* temp=s[j];
                        s[j]=s[j+1];
                        s[j+1]=temp;
                    }
                }
                if (opt==2)
                {
                    if (s[j]->m_id<s[j+1]->m_id)
                    {
                        staff* temp=s[j];
                        s[j]=s[j+1];
                        s[j+1]=temp;
                    }
                }
            }
        }

        cout<<"排序成功！\n排序后结果为：\n";
        display();
        write();
    }
    else
    {
        cout<<"目前还没有任何职工信息，清先添加职工信息"<<endl;
    }
}

void staff_manager::empty()
{
    char opt;
    cout<<"您确定要清空您在本系统中所有的职工信息数据？"<<endl;
    cout<<"Y.确定                       N.取消"<<endl;
    cout<<"该行为不可逆，请您慎重选择：";
    cin>>opt;

    if (opt=='y'||opt=='Y')
    {
        ans=0;
        delete[] s;
        s=nullptr;
        write();
        cout<<"您已清空职工信息系统！"<<endl;
    }
    else
    {
        cout<<"您已取消该操作！"<<endl;
    }

    system("pause");
    system("cls");
}

void staff_manager::read()
{
    ifstream infile("data.txt");
    if(!infile)
    {
        cout<<"打开文件失败！\n请检查文件是否存在！\n即将退出系统！"<<endl;
        exit(0);
    }

    infile>>ans;
    staff** t_s=new staff*[ans];

    int t_id;
    string t_name;
    int t_position;

    int i=0;
    while(infile>>t_id>>t_name>>t_position&&i<ans)
    {
        if(t_position==1)
        {
            t_s[i]=new employee(t_id,t_name);
        }
        if(t_position==2)
        {
            t_s[i]=new manager(t_id,t_name);
        }
        if(t_position==3)
        {
            t_s[i]=new boss(t_id,t_name);
        }
        i++;
    }
    infile.close();

    if(s!=nullptr)
    {
        delete[] s;
    }

    s=t_s;
}

void staff_manager::write() const
{
    ofstream outfile("data.txt");
    if(!outfile)
    {
        cout<<"打开文件失败！\n请检查文件是否存在！\n即将退出系统！"<<endl;
        exit(0);
    }

    outfile<<ans<<endl;
    int i=0;
    while(i<ans)
    {
        outfile<<s[i]->m_id<<"\t"<<s[i]->m_name<<"\t"<<s[i]->m_position<<endl;
        i++;
    }
    outfile.close();
}

staff_manager::staff_manager()
{
   ans=0;
   s=nullptr;

   read();
}

staff_manager::~staff_manager()
{
    if(s!=nullptr)
    {
        delete[] s;
    }
}

int main()
{
    staff_manager sm;
    sm.go();
}

//
// Created by Faye on 25-1-29.
//