#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
#include<functional>
#include<iomanip>
using namespace std;

class identity
{
protected:
    string m_name;
    int m_id;
    string m_password;

public:
    virtual ~identity() = default;

    virtual void menu()=0;

    // bool operator>(identity& other)
    // {
    //     if(this->m_id!=other.m_id)
    //     {
    //         return (this->m_id)>(other.m_id);
    //     }
    // }

    string getname() const
    {
        return m_name;
    }

    int getid() const
    {
        return m_id;
    }
    
    string getpassword() const
    {
        return m_password;
    }
};

class sortrule1
{
public:
    bool operator()(const identity& p1,const identity& p2) const
    {
        if(p1.getid()!=p2.getid()){return p1.getid()<p2.getid();}
    }
};

class student final :public identity
{
public:
    void menu() override;
    
    student();

    explicit student(const string& name,int id,const string& password);

    void apply();

    void show_my_order();

    void show_all_order();

    void cancel_order();
    
};

class computer_room
{
public:
    int m_room_id;
    int m_coom_capacity;

    computer_room(){}

    computer_room(const int& room_id,const int& room_capacity)
    {
        m_room_id=room_id;
        m_coom_capacity=room_capacity;
    }
};

class book
{
public:
    int m_s_id;
    string m_s_name;
    int m_room;
    int m_day;//数字 1、2、3、4、5、6、7分别代表周一到周日
    int m_period;//数字 1、2、3分别代表上午、下午和晚上
    string m_Time;
    bool vaild;//false 代表 未得到教师的同意  true 代表得到了老师的同意
    bool cancel;//false 代表未被取消  true 代表已被取消

    book(){}

    book(int s_id,string s_name,int room_id,int day,int period):m_s_id(s_id),m_s_name(s_name),m_room(room_id),m_day(day),m_period(period)
    {
        vaild=false;
        cancel=false;

        string d,p;
        switch(m_day)
        {
            case 1:{d="周一";break;}
            case 2:{d="周二";break;}
            case 3:{d="周三";break;}
            case 4:{d="周四";break;}
            case 5:{d="周五";break;}
            case 6:{d="周六";break;}
            case 7:{d="周日";break;}
        }
        switch(m_period)
        {
            case 1:{p="上午";break;}
            case 2:{p="下午";break;}
            case 3:{p="晚上";break;}
        }
        m_Time=(d+p);
    }

    book(int s_id,string s_name,int room_id,int day,int period,bool v,bool c):m_s_id(s_id),m_s_name(s_name),m_room(room_id),m_day(day),m_period(period),vaild(v),cancel(c)
    {
        string d,p;
        switch(m_day)
        {
            case 1:{d="周一";break;}
            case 2:{d="周二";break;}
            case 3:{d="周三";break;}
            case 4:{d="周四";break;}
            case 5:{d="周五";break;}
            case 6:{d="周六";break;}
            case 7:{d="周日";break;}
        }
        switch(m_period)
        {
            case 1:{p="上午";break;}
            case 2:{p="下午";break;}
            case 3:{p="晚上";break;}
        }
        m_Time=(d+p);
    }

    void book_print()
    {
        cout<<"机房编号："<<setfill('0')<<setw(3)<<m_room<<'\t'<<"预约时间："<<m_Time<<"\t"<<"预约人姓名："<<m_s_name<<'\t'<<"预约人学号："<<m_s_id<<'\t';
        if(cancel){cout<<"已取消"<<'\n';}
        else if(vaild&&!cancel){cout<<"已确认"<<'\n';}        
        else{cout<<"未确认"<<'\n';}
    }

    
};

class sortrule2
{
    bool operator()(const book& b1,const book& b2) const
    {
        if(b1.m_day!=b2.m_day){return b1.m_day<b2.m_day;}
        else if(b1.m_period!=b2.m_period){return b1.m_period<b2.m_period;}
    }

};

student::student(){}

student::student(const string& name,int id, const string& password)
{
    m_name=name;
    m_id=id;
    m_password=password;
}

void student::menu()
{
    bool running =true;
    while(running)
    {
        cout << "欢迎学生代表：" << this->m_name << "登录！" << endl;
	    cout << "\t\t ----------------------------------\n";
	    cout << "\t\t|                                 |\n";
	    cout << "\t\t|          1.申请预约              |\n";
	    cout << "\t\t|                                 |\n";
	    cout << "\t\t|          2.查看我的预约         |\n";
	    cout << "\t\t|                                 |\n";
	    cout << "\t\t|          3.查看所有预约         |\n";
	    cout << "\t\t|                                 |\n";
	    cout << "\t\t|          4.取消预约              |\n";
	    cout << "\t\t|                                 |\n";
	    cout << "\t\t|          0.退出登录              |\n";
	    cout << "\t\t|                                 |\n";
	    cout << "\t\t ----------------------------------\n";
        int opt;
        cout<<" 请输入您的选择：";
        cin>>opt;
        switch(opt)
        {
            case 1:
            {
                this->apply();
                break;
            }

            case 2:
            {
                this->show_my_order();
                break;
            }

            case 3:
            {
                this->show_all_order();
                break;
            }

            case 4:
            {
                this->cancel_order();
                break;
            }

            case 0:
            {
                cout<<"您确定要退出登录吗？"<<endl;
                cout<<"Y.确定     N.取消"<<endl;
                char choice;
                cin>>choice;
        
                if(choice=='y'||choice=='Y')
                {
                    running=false;
                    cout<<"已退出登录！"<<endl;
                    system("pause");
                    system("cls");
                }
                else
                {
                    system("cls");
                }
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

void student::apply()
{
    ifstream in2("data\\computer room.txt");
    vector<computer_room> v_c;
    int id,capacity;
    if(!in2)
    {
        cout<<"打开文件失败！请检查文件是否存在。"<<endl;
        return;
    }
    while(in2>>id>>capacity)
    {
        v_c.push_back(computer_room(id,capacity));
    }
    in2.close();

    //this->show_all_order();
    ifstream in1("data\\book.txt");
    if(!in1)
    {
        cout<<"打开文件失败！请检查文件是否存在。"<<endl;
        return;
    }
    string line;
    vector<book> v_b;
    cout<<"以下是本周的全部预约记录："<<endl;
    while(getline(in1,line))
    {
        if(line.empty()){continue;}
        string room_str,s_id_str,s_name_str,day_str,period_str,vaild_str,cancel_str;
        stringstream ss(line);
        getline(ss,room_str,'\t');
        getline(ss,s_name_str,'\t');
        getline(ss,s_id_str,'\t');
        getline(ss,day_str,'\t');
        getline(ss,period_str,'\t');
        getline(ss,vaild_str,'\t');
        getline(ss,cancel_str,'\n');
        int room=stoi(room_str);
        int s_id=stoi(s_id_str);
        int day=stoi(day_str);
        int period=stoi(period_str);
        bool vaild=stoi(vaild_str);
        bool cancel=stoi(cancel_str);
        book(s_id,s_name_str,room,day,period,vaild,cancel).book_print();
        v_b.push_back(book(s_id,s_name_str,room,day,period,vaild,cancel));
    }
    cout<<endl;
    in1.close();
    cout<<"以下是学校的机房信息："<<endl;
    for(vector<computer_room>::iterator it=v_c.begin();it!=v_c.end();it++)
    {
        cout<<"机房编号"<<it->m_room_id<<'\t'<<"机房容量："<<it->m_coom_capacity<<'\n';
    }
   
    int day,period;
    bool retry = true;
    do 
    {
        cout<<'\n'<<"选择您要预约的机房编号：";
        cin>>id;
        
        cout<<"1.周一  2.周二  3.周三  4.周四  5.周五  6.周六  7.周日"<<endl;
        cout<<"请选择您要预约的机房时间（输入对应的数字）：";
        cin>>day;
        cout<<"1.上午  2.下午  3.晚上"<<endl;
        cout<<"请选择您要预约的时间段：";
        cin>>period;

        for(vector<book>::iterator it=v_b.begin();it!=v_b.end();it++) 
        {
            if(it->m_room==id && it->m_day==day && it->m_period==period && it->cancel==false) 
            {
                cout << "抱歉，这个时间段的该机房已经有人预约过了，换一个机房或者时间点吧。" << endl;
                // 添加重新输入逻辑
                cout << "是否重新预约？(1-重新预约 0-取消预约)：";
                int choice;
                cin >> choice;
                if(choice == 1) 
                {
                    system("cls");
                    retry = true;
                    break; // 跳出for循环，重新进入do-while循环
                }
                else 
                {  
                    system("pause");
                    system("cls");
                    return; // 直接退出预约流程
                }
            }
            retry = false; // 没有冲突时退出循环
        }
        
    } while(retry);

    book b(this->getid(),this->getname(),id,day,period);

    ofstream out("data\\book.txt",ios::app);
    if(!out)
    {
        cout<<"打开文件失败！请检查文件是否存在。"<<endl;
        return;
    }
    out<<b.m_room<<'\t'<<b.m_s_name<<'\t'<<b.m_s_id<<'\t'<<b.m_day<<'\t'<<b.m_period<<'\t'<<b.vaild<<'\t'<<b.cancel<<'\n';
    out.close();
    cout<<"您已预约成功，请耐心等待教师的审核。。。"<<endl;

    system("pause");
    system("cls");
}

void student::show_my_order()
{
    ifstream in("data\\book.txt");
    if(!in)
    {
        cout<<"打开文件失败!请检查文件是否存在。"<<endl;
        return;
    }
    string line;
    vector<book> v_b;
    while(getline(in,line))
    {
        if(line.empty()){continue;}
        string room_str,s_id_str,s_name_str,day_str,period_str,vaild_str,cancel_str;
        stringstream ss(line);
        getline(ss,room_str,'\t');
        getline(ss,s_name_str,'\t');
        getline(ss,s_id_str,'\t');
        getline(ss,day_str,'\t');
        getline(ss,period_str,'\t');
        getline(ss,vaild_str,'\t');
        getline(ss,cancel_str,'\n');
        int room=stoi(room_str);
        int s_id=stoi(s_id_str);
        int day=stoi(day_str);
        int period=stoi(period_str);
        bool vaild=stoi(vaild_str);
        bool cancel=stoi(cancel_str);
        if(s_id==this->m_id&&s_name_str==this->m_name)
        {
            book(s_id,s_name_str,room,day,period,vaild,cancel).book_print();
            v_b.push_back(book(s_id,s_name_str,room,day,period,vaild,cancel));
        }
        
    }
    if(v_b.size()==0)
    {
        cout<<"您本周还没有预约记录。"<<endl;
    }
    cout<<endl;
    in.close();

    system("pause");
    system("cls");
}

void student::show_all_order()
{
    ifstream in("data\\book.txt");
    if(!in)
    {
        cout<<"打开文件失败！请检查文件是否存在。"<<endl;
        return;
    }
    string line;
    cout<<"以下是本周的全部预约记录："<<endl;
    while(getline(in,line))
    {
        if(line.empty()){continue;}
        string room_str,s_id_str,s_name_str,day_str,period_str,vaild_str,cancel_str;
        stringstream ss(line);
        getline(ss,room_str,'\t');
        getline(ss,s_name_str,'\t');
        getline(ss,s_id_str,'\t');
        getline(ss,day_str,'\t');
        getline(ss,period_str,'\t');
        getline(ss,vaild_str,'\t');
        getline(ss,cancel_str,'\n');
        int room=stoi(room_str);
        int s_id=stoi(s_id_str);
        int day=stoi(day_str);
        int period=stoi(period_str);
        bool vaild=stoi(vaild_str);
        bool cancel=stoi(cancel_str);
        book(s_id,s_name_str,room,day,period,vaild,cancel).book_print();
    }
    cout<<endl;
    in.close();

    system("pause");
    system("cls");
}

void student::cancel_order()
{
    ifstream in("data\\book.txt");
    if(!in)
    {
        cout<<"打开文件失败!请检查文件是否存在。"<<endl;
        return;
    }
    string line;
    vector<book> v_b;
    int n=1;
    cout<<"以下是您本周的预约记录："<<endl;
    while(getline(in,line))
    {
        if(line.empty()){continue;}
        string room_str,s_id_str,s_name_str,day_str,period_str,vaild_str,cancel_str;
        stringstream ss(line);
        getline(ss,room_str,'\t');
        getline(ss,s_name_str,'\t');
        getline(ss,s_id_str,'\t');
        getline(ss,day_str,'\t');
        getline(ss,period_str,'\t');
        getline(ss,vaild_str,'\t');
        getline(ss,cancel_str,'\n');
        int room=stoi(room_str);
        int s_id=stoi(s_id_str);
        int day=stoi(day_str);
        int period=stoi(period_str);
        bool vaild=stoi(vaild_str);
        bool cancel=stoi(cancel_str);
        if(s_id==this->m_id&&s_name_str==this->m_name)
        {
            cout<<setfill('0')<<setw(2)<<n<<'\t';
            book(s_id,s_name_str,room,day,period).book_print();
            
        }
        v_b.push_back(book(s_id,s_name_str,room,day,period,vaild,cancel));
        n++;
    }
    cout<<endl;
    int index=0;
    cout<<"请选择您要取消的预约记录（输入记录前的编号）：";
    cin>>index;
    index--;
    if(v_b[index].m_s_name==this->m_name&&v_b[index].m_s_id==this->m_id)
    {
        v_b[index].cancel=true;
        ofstream out("data\\book.txt",ios::trunc);
        if(!out)
        {
            cout<<"打开文件失败！请检查文件是否存在。";
            return;
        }
        for(vector<book>::iterator it=v_b.begin();it!=v_b.end();it++)
        {
        //out<<b.m_room<<'\t'<<b.m_s_name<<'\t'<<b.m_s_id<<'\t'<<b.m_day<<'\t'<<b.m_period<<'\t'<<b.vaild<<'\t'<<b.cancel<<'\n';
        out<<it->m_room<<'\t'<<it->m_s_name<<'\t'<<it->m_s_id<<'\t'<<it->m_day<<'\t'<<it->m_period<<'\t'<<it->vaild<<'\t'<<it->cancel<<'\n';
        }
        out.close();
        cout<<"您已成功取消预约！"<<endl;
    }
    else
    {
        cout<<"请输入正确的编号！"<<endl;
        system("pause");
        system("cls");
        return;
    }
    
    system("pause");
    system("cls");
}

class teacher:public identity
{
public:
    teacher();

    explicit teacher(const string& name,int id,const string& password);

    void menu() override;

    void show_all_order();

    void vaild_order();
};

teacher::teacher(){}

teacher::teacher(const string& name,int id,const string& password)
{
    m_name=name;
    m_id=id;
    m_password=password;
}

void teacher::menu()
{
    bool running=true;
    while(running)
    {
        cout << "欢迎教师：" << this->m_name << "登录！" << endl;
	    cout << "\t\t ----------------------------------\n";
	    cout << "\t\t|                                  |\n";
	    cout << "\t\t|          1.查看所有预约          |\n";
	    cout << "\t\t|                                  |\n";
	    cout << "\t\t|          2.审核预约              |\n";
	    cout << "\t\t|                                  |\n";
	    cout << "\t\t|          0.注销登录              |\n";
	    cout << "\t\t|                                  |\n";
	    cout << "\t\t ----------------------------------\n";
	    int opt;
        cout << "请选择您的操作： ";
        cin>>opt;

        switch(opt)
        {
            case 1:
            {
                this->show_all_order();
                break;
            }

            case 2:
            {
                this->vaild_order();
                break;
            }

            case 0:
            {
                cout<<"您确定要退出登录吗？"<<endl;
                cout<<"Y.确定     N.取消"<<endl;
                char choice;
                cin>>choice;
        
                if(choice=='y'||choice=='Y')
                {
                    running=false;
                    cout<<"已退出登录！"<<endl;
                    system("pause");
                    system("cls");
                }
                else
                {
                    system("cls");
                }
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

void teacher::show_all_order()
{
    ifstream in("data\\book.txt");
    if(!in)
    {
        cout<<"打开文件失败！请检查文件是否存在。"<<endl;
        return;
    }
    string line;
    cout<<"以下是本周的全部预约记录："<<endl;
    while(getline(in,line))
    {
        if(line.empty()){continue;}
        string room_str,s_id_str,s_name_str,day_str,period_str,vaild_str,cancel_str;
        stringstream ss(line);
        getline(ss,room_str,'\t');
        getline(ss,s_name_str,'\t');
        getline(ss,s_id_str,'\t');
        getline(ss,day_str,'\t');
        getline(ss,period_str,'\t');
        getline(ss,vaild_str,'\t');
        getline(ss,cancel_str,'\n');
        int room=stoi(room_str);
        int s_id=stoi(s_id_str);
        int day=stoi(day_str);
        int period=stoi(period_str);
        bool vaild=stoi(vaild_str);
        bool cancel=stoi(cancel_str);
        book(s_id,s_name_str,room,day,period,vaild,cancel).book_print();
    }
    cout<<endl;
    in.close();

    system("pause");
    system("cls");
}

void teacher::vaild_order()
{
    ifstream in("data\\book.txt");
    if(!in)
    {
        cout<<"打开文件失败!请检查文件是否存在。"<<endl;
        return;
    }
    string line;
    vector<book> v_b;
    int n=1;
    cout<<"以下是本周的所有预约记录："<<endl;
    while(getline(in,line))
    {
        if(line.empty()){continue;}
        string room_str,s_id_str,s_name_str,day_str,period_str,vaild_str,cancel_str;
        stringstream ss(line);
        getline(ss,room_str,'\t');
        getline(ss,s_name_str,'\t');
        getline(ss,s_id_str,'\t');
        getline(ss,day_str,'\t');
        getline(ss,period_str,'\t');
        getline(ss,vaild_str,'\t');
        getline(ss,cancel_str,'\n');
        int room=stoi(room_str);
        int s_id=stoi(s_id_str);
        int day=stoi(day_str);
        int period=stoi(period_str);
        bool vaild=stoi(vaild_str);
        bool cancel=stoi(cancel_str);
        if(vaild==false&&cancel==false)
        {
            cout<<setfill('0')<<setw(2)<<n<<'\t';
            book(s_id,s_name_str,room,day,period).book_print();
            
        }
        v_b.push_back(book(s_id,s_name_str,room,day,period,vaild,cancel));
        n++;
    }
    cout<<endl;
    int index=0;
    cout<<"请选择您要确认的预约记录（输入记录前的编号）：";
    cin>>index;
    index--;
    if(v_b[index].vaild==false&&v_b[index].cancel==false)
    {
        v_b[index].vaild=true;
        ofstream out("data\\book.txt",ios::trunc);
        if(!out)
        {
            cout<<"打开文件失败！请检查文件是否存在。";
            return;
        }
        for(vector<book>::iterator it=v_b.begin();it!=v_b.end();it++)
        {
        //out<<b.m_room<<'\t'<<b.m_s_name<<'\t'<<b.m_s_id<<'\t'<<b.m_day<<'\t'<<b.m_period<<'\t'<<b.vaild<<'\t'<<b.cancel<<'\n';
        out<<it->m_room<<'\t'<<it->m_s_name<<'\t'<<it->m_s_id<<'\t'<<it->m_day<<'\t'<<it->m_period<<'\t'<<it->vaild<<'\t'<<it->cancel<<'\n';
        }
        out.close();
        cout<<"您已确认该预约！"<<endl;
    }
    else
    {
        cout<<"编号输入有误，请输入正确的编号！"<<endl;
        system("pause");
        system("cls");
        return;
    }
    
    system("pause");
    system("cls");
}

class manager:public identity
{
public:
    manager();

    manager(const string& name,int id,const string& password);

    void menu() override;

    void add_user();

    void show_user();

    void show_room();

    void clear_book();
};

manager::manager(){}

manager::manager(const string& name,int id,const string& password)
{
    m_name=name;
    m_id=id;
    m_password=password;
}

void manager::menu()
{
    bool running=true;
    while(running)
    {
        cout << "欢迎管理员："<<this->m_name << "登录！" << endl;
	    cout << "\t\t ---------------------------------\n";
	    cout << "\t\t|                                |\n";
	    cout << "\t\t|          1.添加账号            |\n";
	    cout << "\t\t|                                |\n";
	    cout << "\t\t|          2.查看账号            |\n";
	    cout << "\t\t|                                |\n";
	    cout << "\t\t|          3.查看机房            |\n";
	    cout << "\t\t|                                |\n";
	    cout << "\t\t|          4.清空预约            |\n";
	    cout << "\t\t|                                |\n";
	    cout << "\t\t|          0.注销登录            |\n";
	    cout << "\t\t|                                |\n";
	    cout << "\t\t ---------------------------------\n";
        cout << "请输入您的命令：";
        int opt=-1;
        cin>>opt;

        switch(opt)
        {
            case 1:
            {
                this->add_user();
                break;
            }
            
            case 2:
            {
                this->show_user();
                break;
            }

            case 3:
            {
                this->show_room();
                break;
            }

            case 4:
            {
                this->clear_book();
                break;
            }

            case 0:
            {
                cout<<"您确定要退出登录吗？"<<endl;
                cout<<"Y.确定     N.取消"<<endl;
                char choice;
                cin>>choice;
        
                if(choice=='y'||choice=='Y')
                {
                    running=false;
                    cout<<"已退出登录！"<<endl;
                    system("pause");
                    system("cls");
                }
                else
                {
                    system("cls");
                }
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

void manager::add_user()
{
    cout<<"1.学生代表         2.教师"<<endl;
    cout<<"请选择您想要新建的账号身份：";
    int opt;
    cin>>opt;
    if(opt==1)
    {   
        cout<<"您需要新建多少个学生代表账号"<<endl;
        int num;
        cin>>num;
        cout<<"正在新建个"<<num<<"个学生代表账号"<<endl;
        map<int,student> m_s1;
        ifstream in("data\\student.txt");//先读取文件信息，获取已有的学生代表账号信息
        if (!in.is_open()) //打开文件失败提示
        {
            cout << "无法打开学生代表数据文件" << endl;
            return;
        }
        
        string line;
        //eof检测
        while (getline(in, line)) 
        {
            if (line.empty()) continue;  //跳过空行
            
            stringstream ss(line);
            string name_str, id_str, password_str;
            //错误处理
            if (!getline(ss, name_str, '\t') || !getline(ss, id_str, '\t') || !getline(ss, password_str, '\n')) 
            {
                cout << "数据格式错误：" << line << endl;
                continue;
            }
            int student_id=stoi(id_str);
            m_s1.try_emplace(student_id, name_str, student_id, password_str);//将已有的学生代表账号数据存入容器，为后续学号唯一性检测做准备
        }

        for(int i=0;i<num;i++)
        {
            string name,id,password;
            cout<<"请输入第"<<(i+1)<<"个学生代表账号的信息"<<endl;
            cout<<"姓名：";
            cin>>name;
            cout<<"学号：";
            cin>>id;
            cout<<"密码：";
            cin>>password;
            int student_id=stoi(id);
            auto result=m_s1.try_emplace(student_id,name,student_id,password);
            if(result.second)//运用map容器的key值唯一性来实现学号唯一性检测
            {
                cout<<"新建学生代表账号成功！"<<endl;
            }
            else
            {
                cout<<"已存在相同学号的账号，新建学生代表账号失败！"<<endl;
                cout<<"请重新输入账号信息。"<<endl;
                i--;
            }
        }
        ofstream out("data\\student.txt",ios::trunc);//将原有的和新建的账号信息一起存入文件
        //sort(m_s.begin(),m_s.end(),sortrule());//先将容器内元素排序
        for(map<int,student>::iterator it=m_s1.begin();it!=m_s1.end();it++)//写入文件
        {
            out<<it->second.getname()<<'\t'<<it->second.getid()<<'\t'<<it->second.getpassword()<<'\n';
        }
        cout<<num<<"个学生代表账号已新建完成！"<<endl;

        in.close();
        system("pause");
        system("cls");
    }
    else if(opt==2)
    {
        cout<<"您需要新建多少个教师账号"<<endl;
        int num;
        cin>>num;
        cout<<"正在新建个"<<num<<"个教师账号"<<endl;
        map<int,teacher> m_t2;
        ifstream in("data\\teacher.txt");//先读取文件信息，获取已有的学生代表账号信息
        if (!in.is_open()) //打开文件失败提示
        {
            cout << "无法打开教师数据文件" << endl;
            return;
        }
        
        string line;
        //eof检测
        while (getline(in, line)) 
        {
            if (line.empty()) continue;  //跳过空行
            
            stringstream ss(line);
            string name_str, id_str, password_str;
            //错误处理
            if (!getline(ss, name_str, '\t') || !getline(ss, id_str, '\t') || !getline(ss, password_str, '\n')) 
            {
                cout << "数据格式错误：" << line << endl;
                continue;
            }
                // 原代码尝试用 string 类型的 name_str 等构造 teacher 对象，构造函数要求的是引用类型，这里将 stoi(id_str) 的结果存储在一个变量中，避免使用右值引用
                int id = stoi(id_str);
                m_t2.try_emplace(id,name_str, id, password_str);
                //将已有的教师账号数据存入容器，为后续工号唯一性检测做准备
        }

        for(int i=0;i<num;i++)
        {
            string name,id,password;
            cout<<"请输入第"<<(i+1)<<"个教师账号的信息"<<endl;
            cout<<"姓名：";
            cin>>name;
            cout<<"工号：";
            cin>>id;
            cout<<"密码：";
            cin>>password;
            
            // 原代码中 stoi(id) 是一个右值，而 teacher 构造函数的 id 参数是一个非 const 左值引用，会导致编译错误
            // 这里将 stoi(id) 的结果存储在一个变量中，避免使用右值引用
            int teacher_id = stoi(id);
            auto result = m_t2.try_emplace(teacher_id, name, teacher_id, password);
            if(result.second)//运用map容器的key值唯一性来实现学号唯一性检测
            {
                cout<<"新建教师账号成功！"<<endl;
            }
            else
            {
                cout<<"已存在相同工号的账号，新建教师账号失败！"<<endl;
                cout<<"请重新输入账号信息。"<<endl;
                i--;
            }
        }
        ofstream out("data\\teacher.txt",ios::trunc);//将原有的和新建的账号信息一起存入文件
        //sort(m_t.begin(),m_t.end(),sortrule());
        for(map<int,teacher>::iterator it=m_t2.begin();it!=m_t2.end();it++)
        {
            out<<it->second.getname()<<'\t'<<it->second.getid()<<'\t'<<it->second.getpassword()<<'\n';
        }
        cout<<num<<"个教师账号已新建完成！"<<endl;

        in.close();
        system("pause");
        system("cls");
    }
}

void manager::show_user()
{
    int opt;
    cout<<"1.学生代表账号列表    2.教师账号列表   3.我全都要"<<'\n'<<"请输入你想要查看的账号列表：";
    cin>>opt;
    cout<<endl;
    if(opt==1)
    {
        ifstream in("data\\student.txt");//先读取文件信息，获取已有的学生代表账号信息
        if (!in.is_open()) //打开文件失败提示
        {
            cout << "无法打开学生代表数据文件" << endl;
            return;
        }
        vector<student> v_s;
        string line;
        while(getline(in, line))//将读取的账号信息存放到vector容器中去
        {
            if(line.empty()){continue;}
            stringstream ss(line);
            string name_str,id_str,password_str;
            if(!getline(ss,name_str,'\t')||!getline(ss,id_str,'\t')||!getline(ss,password_str,'\t'))
            {
                cout << "数据格式错误：" << line << endl;
                continue;
            }
            int student_id=stoi(id_str);
            v_s.push_back(student(name_str,student_id,password_str));
        }
        cout<<"学生代表账号如下："<<endl;
        for(vector<student>::iterator it=v_s.begin();it!=v_s.end();it++)
        {
            cout<<it->getname()<<" "<<it->getid()<<" "<<it->getpassword()<<endl;
        }
        in.close();
        cout<<endl;
    }
    else if(opt==2)
    {
        ifstream in("data\\teacher.txt");//先读取文件信息，获取已有的学生代表账号信息
        if (!in.is_open()) //打开文件失败提示
        {
            cout << "无法打开教师数据文件" << endl;
            return;
        }
        vector<teacher> v_t;
        string line;
        while(getline(in, line))//将读取的账号信息存放到vector容器中去
        {
            if(line.empty()){continue;}
            stringstream ss(line);
            string name_str,id_str,password_str;
            if(!getline(ss,name_str,'\t')||!getline(ss,id_str,'\t')||!getline(ss,password_str,'\t'))
            {
                cout << "数据格式错误：" << line << endl;
                continue;
            }
            int teacher_id = stoi(id_str);
            v_t.push_back(teacher(name_str, teacher_id, password_str));
        }
        cout<<"教师账号如下："<<endl;
        for(vector<teacher>::iterator it=v_t.begin();it!=v_t.end();it++)
        {
            cout<<it->getname()<<" "<<it->getid()<<" "<<it->getpassword()<<endl;
        }
        in.close();
        cout<<endl;
    }
    else if(opt==3)
    {
        ifstream in1("data\\student.txt");//先读取文件信息，获取已有的学生代表账号信息
        if (!in1.is_open()) //打开文件失败提示
        {
            cout << "无法打开学生代表数据文件" << endl;
            return;
        }
        vector<student> v_s;
        string line1;
        while(getline(in1, line1))//将读取的账号信息存放到vector容器中去
        {
            if(line1.empty()){continue;}
            stringstream ss(line1);
            string name_str,id_str,password_str;
            if(!getline(ss,name_str,'\t')||!getline(ss,id_str,'\t')||!getline(ss,password_str,'\t'))
            {
                cout << "数据格式错误：" << line1 << endl;
                continue;
            }
            // 原代码中调用了 student 构造函数，但该构造函数的 id 参数是 int 类型，而传入的是 string 类型，导致编译错误
            // 这里将 stoi(id_str) 的结果存储在一个变量中，避免使用右值引用
            int student_id = stoi(id_str);
            v_s.push_back(student(name_str, student_id, password_str));
        }
        cout<<"学生代表账号如下："<<endl;
        for(vector<student>::iterator it=v_s.begin();it!=v_s.end();it++)
        {
            cout<<it->getname()<<" "<<it->getid()<<" "<<it->getpassword()<<endl;
        }
        cout<<endl;
        in1.close();

        ifstream in2("data\\teacher.txt");//先读取文件信息，获取已有的学生代表账号信息
        if (!in2.is_open()) //打开文件失败提示
        {
            cout << "无法打开教师数据文件" << endl;
            return;
        }
        vector<teacher> v_t;
        string line2;
        while(getline(in2, line2))//将读取的账号信息存放到vector容器中去
        {
            if(line2.empty()){continue;}
            stringstream ss(line2);
            string name_str,id_str,password_str;
            if(!getline(ss,name_str,'\t')||!getline(ss,id_str,'\t')||!getline(ss,password_str,'\t'))
            {
                cout << "数据格式错误：" << line2 << endl;
                continue;
            }
            // 原代码使用 string 类型的 id_str 调用 teacher 构造函数，构造函数要求的是 int 类型的 id
            // 这里将 stoi(id_str) 的结果存储在一个变量中，避免使用右值引用
            int teacher_id = stoi(id_str);
            v_t.push_back(teacher(name_str, teacher_id, password_str));
        }
        cout<<"教师账号如下："<<endl;
        for(vector<teacher>::iterator it=v_t.begin();it!=v_t.end();it++)
        {
            cout<<it->getname()<<" "<<it->getid()<<" "<<it->getpassword()<<endl;
        }
        cout<<endl;
        in2.close();
    }
    else
    {
        cout<<"输入有误！"<<endl;
    }

    system("pause");
    system("cls");
}

void manager::show_room()
{
    ifstream in("data\\computer room.txt");
    vector<computer_room> rooms;
    int room_id,room_capacity;
    while(in>>room_id>>room_capacity)
    {
        rooms.push_back(computer_room(room_id,room_capacity));
    }
    in.close();
    cout<<"机房信息如下："<<endl;
    for(vector<computer_room>::iterator it=rooms.begin();it!=rooms.end();it++)
    {
        cout<<"机房编号："<<it->m_room_id<<"\t"<<"机房容量："<<it->m_coom_capacity<<endl;
    }
    cout<<endl;

    system("pause");
    system("cls");
}

void manager::clear_book()
{
    char opt;
    cout<<"您确定要清空当前的所有预约记录？"<<endl;
    cout<<"Y.确定                N.取消"<<endl;
    cout<<"该行为不可逆，请您慎重选择：";
    cin>>opt;

    if (opt=='y'||opt=='Y')
    {
        ofstream out("data\\book.txt",ios::trunc);
        out.close();
        cout<<"已为您清空所有预约记录！"<<endl;
    }
    else
    {
        cout<<"您已取消该操作！"<<endl;
    }
    system("pause");
    system("cls");
}

class my_system
{
public:
    static void s_Menu()
    {
        cout << "======================  欢迎来到机房预约系统  ====================="  << endl;
	    cout << "\t\t -------------------------------\n";
	    cout << "\t\t|                               |\n";
	    cout << "\t\t|          1.学生代表           |\n";
	    cout << "\t\t|                               |\n";
	    cout << "\t\t|          2.老    师           |\n";
	    cout << "\t\t|                               |\n";
	    cout << "\t\t|          3.管 理 员           |\n";
	    cout << "\t\t|                               |\n";
	    cout << "\t\t|          0.退    出           |\n";
	    cout << "\t\t|                               |\n";
	    cout << "\t\t -------------------------------\n";
    }

    static void Login(int select)//实现登录功能
    {
        if(select==1)//学生账号登录
        {   //提示用户输入账号密码
            string id,password;
            cout<<"请输入您的学号：";
            cin>>id;
            cout<<"请输入您的密码：";
            cin>>password;

            ifstream in("data\\student.txt");
            bool login =false;//登录状态布尔值

            if(!in)
            {
                cout<<"文件打开失败！即将提出程序。"<<endl;
                return;
            }

            string name_str,id_str,password_str;
            while(in>>name_str>>id_str>>password_str)//判断输入的账号密码是否正确
            {
                if(id==id_str&&password==password_str)
                {   
                    login=true;
                    cout<<"登录成功！即将进入系统。"<<endl;
                    in.close();
                    system("pause");
                    system("cls");
                    identity* user = new student(name_str,stoi(id_str),password_str);
                    user->menu();//打开学生界面
                    delete user;
                    user=nullptr;
                }
            }  
            if(!login)//提示账号或密码错误提示
            {
                cout<<"账号或密码错误"<<endl;
                in.close();
                system("pause");
                system("cls");
            }
            
        }
        else if(select==2)//教师账号登录
        {   //提示用户输入账号密码
            string id,password;
            cout<<"请输入您的工号：";
            cin>>id;
            cout<<"请输入您的密码：";
            cin>>password;

            ifstream in("data\\teacher.txt");
            bool login=false;//登录状态布尔值

            if(!in)
            {
                cout<<"文件打开失败！即将提出程序。"<<endl;
                return;
            }

            string name_str,id_str,password_str;
            while(in>>name_str>>id_str>>password_str)//判断输入的账号密码是否正确
            {
                if(id==id_str&&password==password_str)
                {
                    login=true;
                    cout<<"登录成功！即将进入系统。"<<endl;
                    in.close();
                    system("pause");
                    system("cls");
                // 原代码中 stoi(id_str) 是一个右值，而 teacher 构造函数的 id 参数是一个非 const 左值引用，会导致编译错误
                // 这里将 stoi(id_str) 的结果存储在一个变量中，避免使用右值引用
                int teacher_id = stoi(id_str);
                identity* user = new teacher(name_str, teacher_id, password_str);
                    user->menu();//打开教师界面
                    delete user;
                    user=nullptr;
                }
            }  
            if(!login)//提示用户账号和密码错误
            {
                cout<<"账号或密码错误"<<endl;
                in.close();
                system("pause");
                system("cls");
            }
            
        }
        else if(select==3)//管理员账号登录
        {   //提示用户输入账号和密码
            string id,password;
            cout<<"请输入您的账号：";
            cin>>id;
            cout<<"请输入您的密码：";
            cin>>password;

            ifstream in("data\\manager.txt");
            bool login=false;//登录状态布尔值

            if(!in)
            {
                cout<<"文件打开失败！即将提出程序。"<<endl;
                return;
            }

            string name_str,id_str,password_str;
            while(in>>name_str>>id_str>>password_str)
            {
                if(id==id_str&&password==password_str)//判断用户输入的账号密码是否正确
                {
                    login=true;//登录成功，修改状态布尔值
                    cout<<"登录成功！即将进入系统。"<<endl;
                    in.close();
                    system("pause");
                    system("cls");
                    // 原代码中 stoi(id_str) 是一个右值，而 manager 构造函数的 id 参数是一个非 const 左值引用，会导致编译错误
                    // 这里将 stoi(id_str) 的结果存储在一个变量中，避免使用右值引用
                    int manager_id = stoi(id_str);
                    identity* user = new manager(name_str, manager_id, password_str);
                    user->menu();//打开管理员界面
                    delete user;
                    user=nullptr;
                }
            }  
            if(!login)//提示用户输入的账号或密码错误
            {
                cout<<"账号和密码错误"<<endl;
                in.close();
                system("pause");
                system("cls");
            }
        }
        else if(select==0)//退出功能
        {
            cout<<"Y.确认      N.取消"<<endl;
            cout<<"是否确认退出机房预约系统？"<<endl;
            char choice;
            cin>>choice;
        
            if(choice=='y'||choice=='Y')
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
        else//误输入提示
        {
            cout<<"输入有误！没有对应的身份类型。"<<endl;
        }
    }
};

int main()
{
    while(1)
    {
        my_system::s_Menu();
        int select;
        string id,password;
        cout<<"请选择您的身份：";
        cin>>select;
        my_system::Login(select);
    }
    
    return 0;
}