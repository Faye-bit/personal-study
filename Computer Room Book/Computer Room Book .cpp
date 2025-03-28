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
    int m_day;//���� 1��2��3��4��5��6��7�ֱ������һ������
    int m_period;//���� 1��2��3�ֱ�������硢���������
    string m_Time;
    bool vaild;//false ���� δ�õ���ʦ��ͬ��  true ����õ�����ʦ��ͬ��
    bool cancel;//false ����δ��ȡ��  true �����ѱ�ȡ��

    book(){}

    book(int s_id,string s_name,int room_id,int day,int period):m_s_id(s_id),m_s_name(s_name),m_room(room_id),m_day(day),m_period(period)
    {
        vaild=false;
        cancel=false;

        string d,p;
        switch(m_day)
        {
            case 1:{d="��һ";break;}
            case 2:{d="�ܶ�";break;}
            case 3:{d="����";break;}
            case 4:{d="����";break;}
            case 5:{d="����";break;}
            case 6:{d="����";break;}
            case 7:{d="����";break;}
        }
        switch(m_period)
        {
            case 1:{p="����";break;}
            case 2:{p="����";break;}
            case 3:{p="����";break;}
        }
        m_Time=(d+p);
    }

    book(int s_id,string s_name,int room_id,int day,int period,bool v,bool c):m_s_id(s_id),m_s_name(s_name),m_room(room_id),m_day(day),m_period(period),vaild(v),cancel(c)
    {
        string d,p;
        switch(m_day)
        {
            case 1:{d="��һ";break;}
            case 2:{d="�ܶ�";break;}
            case 3:{d="����";break;}
            case 4:{d="����";break;}
            case 5:{d="����";break;}
            case 6:{d="����";break;}
            case 7:{d="����";break;}
        }
        switch(m_period)
        {
            case 1:{p="����";break;}
            case 2:{p="����";break;}
            case 3:{p="����";break;}
        }
        m_Time=(d+p);
    }

    void book_print()
    {
        cout<<"������ţ�"<<setfill('0')<<setw(3)<<m_room<<'\t'<<"ԤԼʱ�䣺"<<m_Time<<"\t"<<"ԤԼ��������"<<m_s_name<<'\t'<<"ԤԼ��ѧ�ţ�"<<m_s_id<<'\t';
        if(cancel){cout<<"��ȡ��"<<'\n';}
        else if(vaild&&!cancel){cout<<"��ȷ��"<<'\n';}        
        else{cout<<"δȷ��"<<'\n';}
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
        cout << "��ӭѧ������" << this->m_name << "��¼��" << endl;
	    cout << "\t\t ----------------------------------\n";
	    cout << "\t\t|                                 |\n";
	    cout << "\t\t|          1.����ԤԼ              |\n";
	    cout << "\t\t|                                 |\n";
	    cout << "\t\t|          2.�鿴�ҵ�ԤԼ         |\n";
	    cout << "\t\t|                                 |\n";
	    cout << "\t\t|          3.�鿴����ԤԼ         |\n";
	    cout << "\t\t|                                 |\n";
	    cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	    cout << "\t\t|                                 |\n";
	    cout << "\t\t|          0.�˳���¼              |\n";
	    cout << "\t\t|                                 |\n";
	    cout << "\t\t ----------------------------------\n";
        int opt;
        cout<<" ����������ѡ��";
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
                cout<<"��ȷ��Ҫ�˳���¼��"<<endl;
                cout<<"Y.ȷ��     N.ȡ��"<<endl;
                char choice;
                cin>>choice;
        
                if(choice=='y'||choice=='Y')
                {
                    running=false;
                    cout<<"���˳���¼��"<<endl;
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
                cout<<"���๦�����ڿ�����......"<<endl;
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
        cout<<"���ļ�ʧ�ܣ������ļ��Ƿ���ڡ�"<<endl;
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
        cout<<"���ļ�ʧ�ܣ������ļ��Ƿ���ڡ�"<<endl;
        return;
    }
    string line;
    vector<book> v_b;
    cout<<"�����Ǳ��ܵ�ȫ��ԤԼ��¼��"<<endl;
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
    cout<<"������ѧУ�Ļ�����Ϣ��"<<endl;
    for(vector<computer_room>::iterator it=v_c.begin();it!=v_c.end();it++)
    {
        cout<<"�������"<<it->m_room_id<<'\t'<<"����������"<<it->m_coom_capacity<<'\n';
    }
   
    int day,period;
    bool retry = true;
    do 
    {
        cout<<'\n'<<"ѡ����ҪԤԼ�Ļ�����ţ�";
        cin>>id;
        
        cout<<"1.��һ  2.�ܶ�  3.����  4.����  5.����  6.����  7.����"<<endl;
        cout<<"��ѡ����ҪԤԼ�Ļ���ʱ�䣨�����Ӧ�����֣���";
        cin>>day;
        cout<<"1.����  2.����  3.����"<<endl;
        cout<<"��ѡ����ҪԤԼ��ʱ��Σ�";
        cin>>period;

        for(vector<book>::iterator it=v_b.begin();it!=v_b.end();it++) 
        {
            if(it->m_room==id && it->m_day==day && it->m_period==period && it->cancel==false) 
            {
                cout << "��Ǹ�����ʱ��εĸû����Ѿ�����ԤԼ���ˣ���һ����������ʱ���ɡ�" << endl;
                // ������������߼�
                cout << "�Ƿ�����ԤԼ��(1-����ԤԼ 0-ȡ��ԤԼ)��";
                int choice;
                cin >> choice;
                if(choice == 1) 
                {
                    system("cls");
                    retry = true;
                    break; // ����forѭ�������½���do-whileѭ��
                }
                else 
                {  
                    system("pause");
                    system("cls");
                    return; // ֱ���˳�ԤԼ����
                }
            }
            retry = false; // û�г�ͻʱ�˳�ѭ��
        }
        
    } while(retry);

    book b(this->getid(),this->getname(),id,day,period);

    ofstream out("data\\book.txt",ios::app);
    if(!out)
    {
        cout<<"���ļ�ʧ�ܣ������ļ��Ƿ���ڡ�"<<endl;
        return;
    }
    out<<b.m_room<<'\t'<<b.m_s_name<<'\t'<<b.m_s_id<<'\t'<<b.m_day<<'\t'<<b.m_period<<'\t'<<b.vaild<<'\t'<<b.cancel<<'\n';
    out.close();
    cout<<"����ԤԼ�ɹ��������ĵȴ���ʦ����ˡ�����"<<endl;

    system("pause");
    system("cls");
}

void student::show_my_order()
{
    ifstream in("data\\book.txt");
    if(!in)
    {
        cout<<"���ļ�ʧ��!�����ļ��Ƿ���ڡ�"<<endl;
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
        cout<<"�����ܻ�û��ԤԼ��¼��"<<endl;
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
        cout<<"���ļ�ʧ�ܣ������ļ��Ƿ���ڡ�"<<endl;
        return;
    }
    string line;
    cout<<"�����Ǳ��ܵ�ȫ��ԤԼ��¼��"<<endl;
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
        cout<<"���ļ�ʧ��!�����ļ��Ƿ���ڡ�"<<endl;
        return;
    }
    string line;
    vector<book> v_b;
    int n=1;
    cout<<"�����������ܵ�ԤԼ��¼��"<<endl;
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
    cout<<"��ѡ����Ҫȡ����ԤԼ��¼�������¼ǰ�ı�ţ���";
    cin>>index;
    index--;
    if(v_b[index].m_s_name==this->m_name&&v_b[index].m_s_id==this->m_id)
    {
        v_b[index].cancel=true;
        ofstream out("data\\book.txt",ios::trunc);
        if(!out)
        {
            cout<<"���ļ�ʧ�ܣ������ļ��Ƿ���ڡ�";
            return;
        }
        for(vector<book>::iterator it=v_b.begin();it!=v_b.end();it++)
        {
        //out<<b.m_room<<'\t'<<b.m_s_name<<'\t'<<b.m_s_id<<'\t'<<b.m_day<<'\t'<<b.m_period<<'\t'<<b.vaild<<'\t'<<b.cancel<<'\n';
        out<<it->m_room<<'\t'<<it->m_s_name<<'\t'<<it->m_s_id<<'\t'<<it->m_day<<'\t'<<it->m_period<<'\t'<<it->vaild<<'\t'<<it->cancel<<'\n';
        }
        out.close();
        cout<<"���ѳɹ�ȡ��ԤԼ��"<<endl;
    }
    else
    {
        cout<<"��������ȷ�ı�ţ�"<<endl;
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
        cout << "��ӭ��ʦ��" << this->m_name << "��¼��" << endl;
	    cout << "\t\t ----------------------------------\n";
	    cout << "\t\t|                                  |\n";
	    cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	    cout << "\t\t|                                  |\n";
	    cout << "\t\t|          2.���ԤԼ              |\n";
	    cout << "\t\t|                                  |\n";
	    cout << "\t\t|          0.ע����¼              |\n";
	    cout << "\t\t|                                  |\n";
	    cout << "\t\t ----------------------------------\n";
	    int opt;
        cout << "��ѡ�����Ĳ����� ";
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
                cout<<"��ȷ��Ҫ�˳���¼��"<<endl;
                cout<<"Y.ȷ��     N.ȡ��"<<endl;
                char choice;
                cin>>choice;
        
                if(choice=='y'||choice=='Y')
                {
                    running=false;
                    cout<<"���˳���¼��"<<endl;
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
                cout<<"���๦�����ڿ�����......"<<endl;
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
        cout<<"���ļ�ʧ�ܣ������ļ��Ƿ���ڡ�"<<endl;
        return;
    }
    string line;
    cout<<"�����Ǳ��ܵ�ȫ��ԤԼ��¼��"<<endl;
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
        cout<<"���ļ�ʧ��!�����ļ��Ƿ���ڡ�"<<endl;
        return;
    }
    string line;
    vector<book> v_b;
    int n=1;
    cout<<"�����Ǳ��ܵ�����ԤԼ��¼��"<<endl;
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
    cout<<"��ѡ����Ҫȷ�ϵ�ԤԼ��¼�������¼ǰ�ı�ţ���";
    cin>>index;
    index--;
    if(v_b[index].vaild==false&&v_b[index].cancel==false)
    {
        v_b[index].vaild=true;
        ofstream out("data\\book.txt",ios::trunc);
        if(!out)
        {
            cout<<"���ļ�ʧ�ܣ������ļ��Ƿ���ڡ�";
            return;
        }
        for(vector<book>::iterator it=v_b.begin();it!=v_b.end();it++)
        {
        //out<<b.m_room<<'\t'<<b.m_s_name<<'\t'<<b.m_s_id<<'\t'<<b.m_day<<'\t'<<b.m_period<<'\t'<<b.vaild<<'\t'<<b.cancel<<'\n';
        out<<it->m_room<<'\t'<<it->m_s_name<<'\t'<<it->m_s_id<<'\t'<<it->m_day<<'\t'<<it->m_period<<'\t'<<it->vaild<<'\t'<<it->cancel<<'\n';
        }
        out.close();
        cout<<"����ȷ�ϸ�ԤԼ��"<<endl;
    }
    else
    {
        cout<<"�������������������ȷ�ı�ţ�"<<endl;
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
        cout << "��ӭ����Ա��"<<this->m_name << "��¼��" << endl;
	    cout << "\t\t ---------------------------------\n";
	    cout << "\t\t|                                |\n";
	    cout << "\t\t|          1.����˺�            |\n";
	    cout << "\t\t|                                |\n";
	    cout << "\t\t|          2.�鿴�˺�            |\n";
	    cout << "\t\t|                                |\n";
	    cout << "\t\t|          3.�鿴����            |\n";
	    cout << "\t\t|                                |\n";
	    cout << "\t\t|          4.���ԤԼ            |\n";
	    cout << "\t\t|                                |\n";
	    cout << "\t\t|          0.ע����¼            |\n";
	    cout << "\t\t|                                |\n";
	    cout << "\t\t ---------------------------------\n";
        cout << "�������������";
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
                cout<<"��ȷ��Ҫ�˳���¼��"<<endl;
                cout<<"Y.ȷ��     N.ȡ��"<<endl;
                char choice;
                cin>>choice;
        
                if(choice=='y'||choice=='Y')
                {
                    running=false;
                    cout<<"���˳���¼��"<<endl;
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
                cout<<"���๦�����ڿ�����......"<<endl;
                system("pause");
                system("cls");
                break;
            }
        }
    }

}

void manager::add_user()
{
    cout<<"1.ѧ������         2.��ʦ"<<endl;
    cout<<"��ѡ������Ҫ�½����˺���ݣ�";
    int opt;
    cin>>opt;
    if(opt==1)
    {   
        cout<<"����Ҫ�½����ٸ�ѧ�������˺�"<<endl;
        int num;
        cin>>num;
        cout<<"�����½���"<<num<<"��ѧ�������˺�"<<endl;
        map<int,student> m_s1;
        ifstream in("data\\student.txt");//�ȶ�ȡ�ļ���Ϣ����ȡ���е�ѧ�������˺���Ϣ
        if (!in.is_open()) //���ļ�ʧ����ʾ
        {
            cout << "�޷���ѧ�����������ļ�" << endl;
            return;
        }
        
        string line;
        //eof���
        while (getline(in, line)) 
        {
            if (line.empty()) continue;  //��������
            
            stringstream ss(line);
            string name_str, id_str, password_str;
            //������
            if (!getline(ss, name_str, '\t') || !getline(ss, id_str, '\t') || !getline(ss, password_str, '\n')) 
            {
                cout << "���ݸ�ʽ����" << line << endl;
                continue;
            }
            int student_id=stoi(id_str);
            m_s1.try_emplace(student_id, name_str, student_id, password_str);//�����е�ѧ�������˺����ݴ���������Ϊ����ѧ��Ψһ�Լ����׼��
        }

        for(int i=0;i<num;i++)
        {
            string name,id,password;
            cout<<"�������"<<(i+1)<<"��ѧ�������˺ŵ���Ϣ"<<endl;
            cout<<"������";
            cin>>name;
            cout<<"ѧ�ţ�";
            cin>>id;
            cout<<"���룺";
            cin>>password;
            int student_id=stoi(id);
            auto result=m_s1.try_emplace(student_id,name,student_id,password);
            if(result.second)//����map������keyֵΨһ����ʵ��ѧ��Ψһ�Լ��
            {
                cout<<"�½�ѧ�������˺ųɹ���"<<endl;
            }
            else
            {
                cout<<"�Ѵ�����ͬѧ�ŵ��˺ţ��½�ѧ�������˺�ʧ�ܣ�"<<endl;
                cout<<"�����������˺���Ϣ��"<<endl;
                i--;
            }
        }
        ofstream out("data\\student.txt",ios::trunc);//��ԭ�еĺ��½����˺���Ϣһ������ļ�
        //sort(m_s.begin(),m_s.end(),sortrule());//�Ƚ�������Ԫ������
        for(map<int,student>::iterator it=m_s1.begin();it!=m_s1.end();it++)//д���ļ�
        {
            out<<it->second.getname()<<'\t'<<it->second.getid()<<'\t'<<it->second.getpassword()<<'\n';
        }
        cout<<num<<"��ѧ�������˺����½���ɣ�"<<endl;

        in.close();
        system("pause");
        system("cls");
    }
    else if(opt==2)
    {
        cout<<"����Ҫ�½����ٸ���ʦ�˺�"<<endl;
        int num;
        cin>>num;
        cout<<"�����½���"<<num<<"����ʦ�˺�"<<endl;
        map<int,teacher> m_t2;
        ifstream in("data\\teacher.txt");//�ȶ�ȡ�ļ���Ϣ����ȡ���е�ѧ�������˺���Ϣ
        if (!in.is_open()) //���ļ�ʧ����ʾ
        {
            cout << "�޷��򿪽�ʦ�����ļ�" << endl;
            return;
        }
        
        string line;
        //eof���
        while (getline(in, line)) 
        {
            if (line.empty()) continue;  //��������
            
            stringstream ss(line);
            string name_str, id_str, password_str;
            //������
            if (!getline(ss, name_str, '\t') || !getline(ss, id_str, '\t') || !getline(ss, password_str, '\n')) 
            {
                cout << "���ݸ�ʽ����" << line << endl;
                continue;
            }
                // ԭ���볢���� string ���͵� name_str �ȹ��� teacher ���󣬹��캯��Ҫ������������ͣ����ｫ stoi(id_str) �Ľ���洢��һ�������У�����ʹ����ֵ����
                int id = stoi(id_str);
                m_t2.try_emplace(id,name_str, id, password_str);
                //�����еĽ�ʦ�˺����ݴ���������Ϊ��������Ψһ�Լ����׼��
        }

        for(int i=0;i<num;i++)
        {
            string name,id,password;
            cout<<"�������"<<(i+1)<<"����ʦ�˺ŵ���Ϣ"<<endl;
            cout<<"������";
            cin>>name;
            cout<<"���ţ�";
            cin>>id;
            cout<<"���룺";
            cin>>password;
            
            // ԭ������ stoi(id) ��һ����ֵ���� teacher ���캯���� id ������һ���� const ��ֵ���ã��ᵼ�±������
            // ���ｫ stoi(id) �Ľ���洢��һ�������У�����ʹ����ֵ����
            int teacher_id = stoi(id);
            auto result = m_t2.try_emplace(teacher_id, name, teacher_id, password);
            if(result.second)//����map������keyֵΨһ����ʵ��ѧ��Ψһ�Լ��
            {
                cout<<"�½���ʦ�˺ųɹ���"<<endl;
            }
            else
            {
                cout<<"�Ѵ�����ͬ���ŵ��˺ţ��½���ʦ�˺�ʧ�ܣ�"<<endl;
                cout<<"�����������˺���Ϣ��"<<endl;
                i--;
            }
        }
        ofstream out("data\\teacher.txt",ios::trunc);//��ԭ�еĺ��½����˺���Ϣһ������ļ�
        //sort(m_t.begin(),m_t.end(),sortrule());
        for(map<int,teacher>::iterator it=m_t2.begin();it!=m_t2.end();it++)
        {
            out<<it->second.getname()<<'\t'<<it->second.getid()<<'\t'<<it->second.getpassword()<<'\n';
        }
        cout<<num<<"����ʦ�˺����½���ɣ�"<<endl;

        in.close();
        system("pause");
        system("cls");
    }
}

void manager::show_user()
{
    int opt;
    cout<<"1.ѧ�������˺��б�    2.��ʦ�˺��б�   3.��ȫ��Ҫ"<<'\n'<<"����������Ҫ�鿴���˺��б�";
    cin>>opt;
    cout<<endl;
    if(opt==1)
    {
        ifstream in("data\\student.txt");//�ȶ�ȡ�ļ���Ϣ����ȡ���е�ѧ�������˺���Ϣ
        if (!in.is_open()) //���ļ�ʧ����ʾ
        {
            cout << "�޷���ѧ�����������ļ�" << endl;
            return;
        }
        vector<student> v_s;
        string line;
        while(getline(in, line))//����ȡ���˺���Ϣ��ŵ�vector������ȥ
        {
            if(line.empty()){continue;}
            stringstream ss(line);
            string name_str,id_str,password_str;
            if(!getline(ss,name_str,'\t')||!getline(ss,id_str,'\t')||!getline(ss,password_str,'\t'))
            {
                cout << "���ݸ�ʽ����" << line << endl;
                continue;
            }
            int student_id=stoi(id_str);
            v_s.push_back(student(name_str,student_id,password_str));
        }
        cout<<"ѧ�������˺����£�"<<endl;
        for(vector<student>::iterator it=v_s.begin();it!=v_s.end();it++)
        {
            cout<<it->getname()<<" "<<it->getid()<<" "<<it->getpassword()<<endl;
        }
        in.close();
        cout<<endl;
    }
    else if(opt==2)
    {
        ifstream in("data\\teacher.txt");//�ȶ�ȡ�ļ���Ϣ����ȡ���е�ѧ�������˺���Ϣ
        if (!in.is_open()) //���ļ�ʧ����ʾ
        {
            cout << "�޷��򿪽�ʦ�����ļ�" << endl;
            return;
        }
        vector<teacher> v_t;
        string line;
        while(getline(in, line))//����ȡ���˺���Ϣ��ŵ�vector������ȥ
        {
            if(line.empty()){continue;}
            stringstream ss(line);
            string name_str,id_str,password_str;
            if(!getline(ss,name_str,'\t')||!getline(ss,id_str,'\t')||!getline(ss,password_str,'\t'))
            {
                cout << "���ݸ�ʽ����" << line << endl;
                continue;
            }
            int teacher_id = stoi(id_str);
            v_t.push_back(teacher(name_str, teacher_id, password_str));
        }
        cout<<"��ʦ�˺����£�"<<endl;
        for(vector<teacher>::iterator it=v_t.begin();it!=v_t.end();it++)
        {
            cout<<it->getname()<<" "<<it->getid()<<" "<<it->getpassword()<<endl;
        }
        in.close();
        cout<<endl;
    }
    else if(opt==3)
    {
        ifstream in1("data\\student.txt");//�ȶ�ȡ�ļ���Ϣ����ȡ���е�ѧ�������˺���Ϣ
        if (!in1.is_open()) //���ļ�ʧ����ʾ
        {
            cout << "�޷���ѧ�����������ļ�" << endl;
            return;
        }
        vector<student> v_s;
        string line1;
        while(getline(in1, line1))//����ȡ���˺���Ϣ��ŵ�vector������ȥ
        {
            if(line1.empty()){continue;}
            stringstream ss(line1);
            string name_str,id_str,password_str;
            if(!getline(ss,name_str,'\t')||!getline(ss,id_str,'\t')||!getline(ss,password_str,'\t'))
            {
                cout << "���ݸ�ʽ����" << line1 << endl;
                continue;
            }
            // ԭ�����е����� student ���캯�������ù��캯���� id ������ int ���ͣ���������� string ���ͣ����±������
            // ���ｫ stoi(id_str) �Ľ���洢��һ�������У�����ʹ����ֵ����
            int student_id = stoi(id_str);
            v_s.push_back(student(name_str, student_id, password_str));
        }
        cout<<"ѧ�������˺����£�"<<endl;
        for(vector<student>::iterator it=v_s.begin();it!=v_s.end();it++)
        {
            cout<<it->getname()<<" "<<it->getid()<<" "<<it->getpassword()<<endl;
        }
        cout<<endl;
        in1.close();

        ifstream in2("data\\teacher.txt");//�ȶ�ȡ�ļ���Ϣ����ȡ���е�ѧ�������˺���Ϣ
        if (!in2.is_open()) //���ļ�ʧ����ʾ
        {
            cout << "�޷��򿪽�ʦ�����ļ�" << endl;
            return;
        }
        vector<teacher> v_t;
        string line2;
        while(getline(in2, line2))//����ȡ���˺���Ϣ��ŵ�vector������ȥ
        {
            if(line2.empty()){continue;}
            stringstream ss(line2);
            string name_str,id_str,password_str;
            if(!getline(ss,name_str,'\t')||!getline(ss,id_str,'\t')||!getline(ss,password_str,'\t'))
            {
                cout << "���ݸ�ʽ����" << line2 << endl;
                continue;
            }
            // ԭ����ʹ�� string ���͵� id_str ���� teacher ���캯�������캯��Ҫ����� int ���͵� id
            // ���ｫ stoi(id_str) �Ľ���洢��һ�������У�����ʹ����ֵ����
            int teacher_id = stoi(id_str);
            v_t.push_back(teacher(name_str, teacher_id, password_str));
        }
        cout<<"��ʦ�˺����£�"<<endl;
        for(vector<teacher>::iterator it=v_t.begin();it!=v_t.end();it++)
        {
            cout<<it->getname()<<" "<<it->getid()<<" "<<it->getpassword()<<endl;
        }
        cout<<endl;
        in2.close();
    }
    else
    {
        cout<<"��������"<<endl;
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
    cout<<"������Ϣ���£�"<<endl;
    for(vector<computer_room>::iterator it=rooms.begin();it!=rooms.end();it++)
    {
        cout<<"������ţ�"<<it->m_room_id<<"\t"<<"����������"<<it->m_coom_capacity<<endl;
    }
    cout<<endl;

    system("pause");
    system("cls");
}

void manager::clear_book()
{
    char opt;
    cout<<"��ȷ��Ҫ��յ�ǰ������ԤԼ��¼��"<<endl;
    cout<<"Y.ȷ��                N.ȡ��"<<endl;
    cout<<"����Ϊ�����棬��������ѡ��";
    cin>>opt;

    if (opt=='y'||opt=='Y')
    {
        ofstream out("data\\book.txt",ios::trunc);
        out.close();
        cout<<"��Ϊ���������ԤԼ��¼��"<<endl;
    }
    else
    {
        cout<<"����ȡ���ò�����"<<endl;
    }
    system("pause");
    system("cls");
}

class my_system
{
public:
    static void s_Menu()
    {
        cout << "======================  ��ӭ��������ԤԼϵͳ  ====================="  << endl;
	    cout << "\t\t -------------------------------\n";
	    cout << "\t\t|                               |\n";
	    cout << "\t\t|          1.ѧ������           |\n";
	    cout << "\t\t|                               |\n";
	    cout << "\t\t|          2.��    ʦ           |\n";
	    cout << "\t\t|                               |\n";
	    cout << "\t\t|          3.�� �� Ա           |\n";
	    cout << "\t\t|                               |\n";
	    cout << "\t\t|          0.��    ��           |\n";
	    cout << "\t\t|                               |\n";
	    cout << "\t\t -------------------------------\n";
    }

    static void Login(int select)//ʵ�ֵ�¼����
    {
        if(select==1)//ѧ���˺ŵ�¼
        {   //��ʾ�û������˺�����
            string id,password;
            cout<<"����������ѧ�ţ�";
            cin>>id;
            cout<<"�������������룺";
            cin>>password;

            ifstream in("data\\student.txt");
            bool login =false;//��¼״̬����ֵ

            if(!in)
            {
                cout<<"�ļ���ʧ�ܣ������������"<<endl;
                return;
            }

            string name_str,id_str,password_str;
            while(in>>name_str>>id_str>>password_str)//�ж�������˺������Ƿ���ȷ
            {
                if(id==id_str&&password==password_str)
                {   
                    login=true;
                    cout<<"��¼�ɹ�����������ϵͳ��"<<endl;
                    in.close();
                    system("pause");
                    system("cls");
                    identity* user = new student(name_str,stoi(id_str),password_str);
                    user->menu();//��ѧ������
                    delete user;
                    user=nullptr;
                }
            }  
            if(!login)//��ʾ�˺Ż����������ʾ
            {
                cout<<"�˺Ż��������"<<endl;
                in.close();
                system("pause");
                system("cls");
            }
            
        }
        else if(select==2)//��ʦ�˺ŵ�¼
        {   //��ʾ�û������˺�����
            string id,password;
            cout<<"���������Ĺ��ţ�";
            cin>>id;
            cout<<"�������������룺";
            cin>>password;

            ifstream in("data\\teacher.txt");
            bool login=false;//��¼״̬����ֵ

            if(!in)
            {
                cout<<"�ļ���ʧ�ܣ������������"<<endl;
                return;
            }

            string name_str,id_str,password_str;
            while(in>>name_str>>id_str>>password_str)//�ж�������˺������Ƿ���ȷ
            {
                if(id==id_str&&password==password_str)
                {
                    login=true;
                    cout<<"��¼�ɹ�����������ϵͳ��"<<endl;
                    in.close();
                    system("pause");
                    system("cls");
                // ԭ������ stoi(id_str) ��һ����ֵ���� teacher ���캯���� id ������һ���� const ��ֵ���ã��ᵼ�±������
                // ���ｫ stoi(id_str) �Ľ���洢��һ�������У�����ʹ����ֵ����
                int teacher_id = stoi(id_str);
                identity* user = new teacher(name_str, teacher_id, password_str);
                    user->menu();//�򿪽�ʦ����
                    delete user;
                    user=nullptr;
                }
            }  
            if(!login)//��ʾ�û��˺ź��������
            {
                cout<<"�˺Ż��������"<<endl;
                in.close();
                system("pause");
                system("cls");
            }
            
        }
        else if(select==3)//����Ա�˺ŵ�¼
        {   //��ʾ�û������˺ź�����
            string id,password;
            cout<<"�����������˺ţ�";
            cin>>id;
            cout<<"�������������룺";
            cin>>password;

            ifstream in("data\\manager.txt");
            bool login=false;//��¼״̬����ֵ

            if(!in)
            {
                cout<<"�ļ���ʧ�ܣ������������"<<endl;
                return;
            }

            string name_str,id_str,password_str;
            while(in>>name_str>>id_str>>password_str)
            {
                if(id==id_str&&password==password_str)//�ж��û�������˺������Ƿ���ȷ
                {
                    login=true;//��¼�ɹ����޸�״̬����ֵ
                    cout<<"��¼�ɹ�����������ϵͳ��"<<endl;
                    in.close();
                    system("pause");
                    system("cls");
                    // ԭ������ stoi(id_str) ��һ����ֵ���� manager ���캯���� id ������һ���� const ��ֵ���ã��ᵼ�±������
                    // ���ｫ stoi(id_str) �Ľ���洢��һ�������У�����ʹ����ֵ����
                    int manager_id = stoi(id_str);
                    identity* user = new manager(name_str, manager_id, password_str);
                    user->menu();//�򿪹���Ա����
                    delete user;
                    user=nullptr;
                }
            }  
            if(!login)//��ʾ�û�������˺Ż��������
            {
                cout<<"�˺ź��������"<<endl;
                in.close();
                system("pause");
                system("cls");
            }
        }
        else if(select==0)//�˳�����
        {
            cout<<"Y.ȷ��      N.ȡ��"<<endl;
            cout<<"�Ƿ�ȷ���˳�����ԤԼϵͳ��"<<endl;
            char choice;
            cin>>choice;
        
            if(choice=='y'||choice=='Y')
            {
                cout<<"��л����ʹ�ã�"<<endl;
                system("cls");
                exit(0);
            }
            else
            {
                system("cls");
            }
        }
        else//��������ʾ
        {
            cout<<"��������û�ж�Ӧ��������͡�"<<endl;
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
        cout<<"��ѡ��������ݣ�";
        cin>>select;
        my_system::Login(select);
    }
    
    return 0;
}