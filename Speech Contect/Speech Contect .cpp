#include<iostream>
#include<fstream>
#include<algorithm>
#include<functional>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<ctime>
#include<thread>
#include<chrono>
#define num 12
using namespace std;

class Speaker
{
private:
    int m_id;
    vector<int> m_score;
public:
    Speaker() : m_id(0) {}

    Speaker(int id):m_id(id){}

    Speaker(int id,int score1,int score2):m_id(id)
    {
        m_score.push_back(score1);
        m_score.push_back(score2);
    }

    int getid() const
    {
        return m_id;
    }

    int getscore_1() const
    {
        return m_score.front();
    }

    int getscore_2() const
    {
        return m_score.back();
    }

    void setscore(int score)
    {
        m_score.push_back(score);
    }


};

void myprint_1(const Speaker& s)
{
    cout<<"选手编号："<<s.getid()<<endl;
}

void myprint_2(const Speaker& s)
{
    cout<<"选手编号"<<s.getid()<<" 第一轮得分："<<s.getscore_1()<<endl;
}

void myprint_3(const Speaker& s)
{
    cout<<"选手编号"<<s.getid()<<" 第二轮得分："<<s.getscore_2()<<endl;
}

void myprint_4(const Speaker& s)
{
    cout<<"选手编号"<<s.getid()<<" 第一轮得分："<<s.getscore_1()<<" 第二轮得分："<<s.getscore_2()<<endl;
}

bool mysortrule_1(const Speaker& s1,const Speaker& s2)
{
    if(s1.getscore_1()!=s2.getscore_1()) return s1.getscore_1()>s2.getscore_1();
    return s1.getid() < s2.getid();
}

bool mysortrule_2(const Speaker& s1,const Speaker& s2)
{
    if(s1.getscore_2()!=s2.getscore_2()) return s1.getscore_2()>s2.getscore_2();
    return s1.getid() < s2.getid();
}

class mycompare
{
public:
    bool operator()(const Speaker& s1,const Speaker& s2) const
    {
        if(s1.getscore_1()!=s2.getscore_1()) return s1.getscore_1()>s2.getscore_1();
        return s1.getid() < s2.getid();
    }
};

class Manager
{
private:
    multimap<int,Speaker> record;

public:
    void menu();
    void start();
    void read();
    void show_record();
    void save(const vector<Speaker>& vs) const;
    void clear();
    void introduce();
    void quit();
    void go();
 
};

void Manager::menu()
{
    cout <<"—————————————————————————————————————————————" << endl;
    cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
    cout << "*************  4.查看比赛规则  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
    cout <<"—————————————————————————————————————————————" << endl;
	cout << endl;
}

void Manager::start()
{
    srand((unsigned int)time(NULL));

    //先初始化参赛选手
    vector<Speaker> vs1;
    for(int i=1;i<(num+1);i++)
    {
        vs1.push_back(Speaker(10000+i));
    }

    cout<<"比赛开始，选手开始抽签分组。"<<endl;
    //打乱参赛选手
    cout<<"选手抽签中..."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    random_shuffle(vs1.begin(),vs1.end());
    // for(vector<Speaker>::iterator it =vs1.begin();it!=vs1.end();it++)
    // {
    //     cout<<it->getid()<<endl;
    // }

    //将参赛选手进行分组
    vector<Speaker> vs2;
    for(int i=0;i<(num/2);i++)
    {
        vs2.push_back(vs1.back());
        vs1.pop_back();
    }
    cout<<endl<<"——————————————————————————————————————————"<<endl;
    cout<<"抽签完成，结果如下："<<endl;
    cout<<"第一组的选手为："<<endl;
    for_each(vs1.begin(),vs1.end(),myprint_1);
    cout<<endl<<"第二组的选手为："<<endl;
    for_each(vs2.begin(),vs2.end(),myprint_1);
    cout<<endl;
    system("pause");
    cout<<endl<<"——————————————————————————————————————————"<<endl;
    //分组后第一轮比赛，给每个选手赋分
    cout<<endl<<"比赛进行中......"<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    for(vector<Speaker>::iterator it=vs1.begin();it!=vs1.end();it++)
    {
        int score=(rand()%51)+50;
        it->setscore(score);
    }
    for(vector<Speaker>::iterator it=vs2.begin();it!=vs2.end();it++)
    {
        int score=(rand()%51)+50;
        it->setscore(score);
    }
    
    sort(vs1.begin(),vs1.end(),mysortrule_1);
    sort(vs2.begin(),vs2.end(),mysortrule_1);
    cout<<"第一组的选手分数为:"<<endl;
    for_each(vs1.begin(),vs1.end(),myprint_2);
    cout<<endl<<"第二组的选手分数为:"<<endl;
    for_each(vs2.begin(),vs2.end(),myprint_2);
    cout<<endl;
    system("pause");

    //第一轮比赛结束，选出晋级的选手，进入决赛
    cout<<endl<<"——————————————————————————————————————————"<<endl;
    vector<Speaker> vs3;
    //multiset<Speaker,mycompare> ss;
    //vs3.resize(6);
    merge(vs1.rbegin()+3, vs1.rbegin()+6,vs2.rbegin()+3, vs2.rbegin()+6,  // 第一组前3名vs2.rbegin(), vs2.rbegin()+3,  // 第二组前3名
      back_inserter(vs3),mysortrule_1);            // 自动插入元素
    //    [](Speaker& a,Speaker& b) {
    //        return a.getscore_1() > b.getscore_1(); // 保持降序合并
    //    });
    
    cout<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout<<"第一轮比赛结束，晋级决赛选手如下："<<endl;
    // for(vector<Speaker>::iterator it=vs3.begin();it!=vs3.end();it++)
    // {
    //     ss.insert(*it);
    // }
    sort(vs3.begin(),vs3.end(),mysortrule_1);
    for_each(vs3.begin(),vs3.end(),myprint_2);
    cout<<endl;
    system("pause");
    //决赛开始，给进入决赛的选手赋分
    cout<<endl<<"——————————————————————————————————————————"<<endl;
    cout<<"决赛开始"<<endl;
    cout<<"选手正在进行比赛....."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    for(vector<Speaker>::iterator it=vs3.begin();it!=vs3.end();it++)
    {
        int score=(rand()%21)+80;
        it->setscore(score);
    }
    cout<<"所有选手的演讲完毕，评委打分如下："<<endl;
    for_each(vs3.begin(),vs3.end(),myprint_3);
    cout<<endl;
    system("pause");

    cout<<endl<<"——————————————————————————————————————————"<<endl;
    cout<<"则最终比赛结果为："<<endl;
    sort(vs3.begin(),vs3.end(),mysortrule_2);
    cout<<"第一名：";
    myprint_4(vs3[0]);
    cout<<"第二名：";
    myprint_4(vs3[1]);
    cout<<"第三名：";
    myprint_4(vs3[2]);
    cout<<endl;
    //保存比赛数据
    system("pause");
    cout<<"保存数据中..."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    save(vs3);
    cout<<"保存成功！"<<endl;
    system("pause");
}

void Manager::read()
{
    ifstream in("data.csv");
    if(!in)
    {
        cout<<"往届记录文件不存在！"<<endl;
        return; // 修改1：不退出程序
    }

    record.clear();
    string line;
    int session = 1; // 当前届数
    
    // 每次读取3个记录为一届
    vector<Speaker> temp;
    while(getline(in, line)&&!line.empty())
    {
        // 解析数据行
        stringstream ss(line);
        string id_str, score1_str, score2_str;
        getline(ss, id_str, '\t');
        getline(ss, score1_str, '\t');
        getline(ss, score2_str, '\t');

        if(id_str.empty()) continue;
        

        Speaker ts(stoi(id_str), stoi(score1_str), stoi(score2_str));
        temp.push_back(ts);

        // 每收集3个选手记录存入一届
        if(temp.size() == 3)
        {
            for(int i=0; i<3; ++i)
            {
                record.insert({session, temp[i]});
            }
            session++;
            temp.clear();
        }
    }
    if(line.empty())
    {
        cout<<"往届记录不存在，请先进行比赛。"<<endl;
    }
    in.close(); // 正确关闭文件流的位置
}

void Manager::show_record()
{
    read();
    for(multimap<int,Speaker>::iterator it=record.begin();it!=record.end();it++)
    {
        cout<<"第"<<it->first<<"届演讲比赛"<<endl;
        cout<<"第一名：";
        myprint_4(it->second);
        it++;
        cout<<"第二名：";
        myprint_4(it->second);
        it++;
        cout<<"第三名：";
        myprint_4(it->second);
        cout<<endl;
    }

}

void Manager::save(const vector<Speaker>& vs) const
{
    ofstream out("data.csv",ios::app);
    if(!out)
    {
        cout<<"打开文件失败！\n请检查文件是否存在！\n即将退出系统！"<<endl;
        exit(0);
    }

    for(vector<Speaker>::const_iterator it=vs.begin();it!=(vs.begin()+3);it++)
    {
        out<<it->getid()<<"\t"<<it->getscore_1()<<"\t"<<it->getscore_2()<<"\n";
    }

    out.close();
}

void Manager::clear()
{
    char opt;
    cout<<"您确定要清空您在本系统中所有的数据？"<<endl;
    cout<<"Y.确定                       N.取消"<<endl;
    cout<<"该行为不可逆，请您慎重选择：";
    cin>>opt;

    if (opt=='y'||opt=='Y')
    {
        ofstream out("data.csv",ios::trunc);
        out.close();
        cout<<"已为您清空所有数据！"<<endl;
    }
    else
    {
        cout<<"您已取消该操作！"<<endl;
    }
}

void Manager::introduce()
{
    cout<<"——————————————————————————————————————————————————————————————————————————"<<endl;
    cout<<"学校举行一场演讲比赛，共有**12个人**参加。**比赛共两轮**，第一轮为淘汰赛，第二轮为决赛。"<<endl;
    cout<<"比赛方式：**分组比赛，每组6个人**；选手每次要随机分组，进行比赛。"<<endl;
    cout<<"每名选手都有对应的**编号**，如 10001 ~ 10012。"<<endl;
    cout<<"第一轮分为两个小组，每组6个人。 整体按照选手编号进行**抽签**后顺序演讲。"<<endl;
    cout<<"当小组演讲完后，淘汰组内排名最后的三个选手，**前三名晋级**，进入下一轮的比赛。"<<endl;
    cout<<"第二轮为决赛，**前三名胜出**。"<<endl;
    cout<<"每轮比赛过后需要**显示晋级选手的信息**。"<<endl;
    cout<<"管你听没听懂，看就完事了（海皇音）！"<<endl;
    cout<<"——————————————————————————————————————————————————————————————————————————"<<endl;
    cout<<endl;
}

void Manager::quit()
{
    cout<<"Y.确认      N.取消"<<endl;
    cout<<"是否确认退出演讲比赛系统？"<<endl;
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

void Manager::go()
{
    while(1)
    {
        menu();
        cout<<"请输入您的选择：";
        int opt;
        cin>>opt;
        switch(opt)
        {
            case 0:
            {   
                quit();
                break;
            }

            case 1:
            {
                start();
                system("cls");
                break;
            }

            case 2:
            {
                show_record();
                system("pause");
                system("cls");
                break;
            }

            case 3:
            {
                clear();
                system("pause");
                system("cls");
                break;
            }

            case 4:
            {
                introduce();
                system("pause");
                system("cls");
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

int main()
{
    Manager m;
    m.go();
}