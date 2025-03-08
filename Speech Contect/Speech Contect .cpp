#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<map>
#include<set>
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

class mycompare
{
public:
    bool operator()(const Speaker& s1,const Speaker& s2) const
    {
        if(s1.getscore_1()!=s2.getscore_1()) return s1.getscore_1()>s2.getscore_1();
        return s1.getid() < s2.getid();
    }
};

void game()
{
    srand((unsigned int)time(NULL));

    //先初始化参赛选手
    vector<Speaker> vs1;
    for(int i=1;i<(num+1);i++)
    {
        vs1.push_back(Speaker(10000+i));
    }

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
    cout<<"抽签完成，结果如下："<<endl;
    cout<<"第一组的选手为："<<endl;
    for_each(vs1.begin(),vs1.end(),myprint_1);
    cout<<endl<<"第二组的选手为："<<endl;
    for_each(vs2.begin(),vs2.end(),myprint_1);
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
}

int main()
{
    game();
    
    return 0;
}