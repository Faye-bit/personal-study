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
    cout<<"ѡ�ֱ�ţ�"<<s.getid()<<endl;
}
void myprint_2(const Speaker& s)
{
    cout<<"ѡ�ֱ��"<<s.getid()<<" ��һ�ֵ÷֣�"<<s.getscore_1()<<endl;
}

void myprint_3(const Speaker& s)
{
    cout<<"ѡ�ֱ��"<<s.getid()<<" �ڶ��ֵ÷֣�"<<s.getscore_2()<<endl;
}

void myprint_4(const Speaker& s)
{
    cout<<"ѡ�ֱ��"<<s.getid()<<" ��һ�ֵ÷֣�"<<s.getscore_1()<<" �ڶ��ֵ÷֣�"<<s.getscore_2()<<endl;
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

    //�ȳ�ʼ������ѡ��
    vector<Speaker> vs1;
    for(int i=1;i<(num+1);i++)
    {
        vs1.push_back(Speaker(10000+i));
    }

    //���Ҳ���ѡ��
    cout<<"ѡ�ֳ�ǩ��..."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    random_shuffle(vs1.begin(),vs1.end());
    // for(vector<Speaker>::iterator it =vs1.begin();it!=vs1.end();it++)
    // {
    //     cout<<it->getid()<<endl;
    // }

    //������ѡ�ֽ��з���
    vector<Speaker> vs2;
    for(int i=0;i<(num/2);i++)
    {
        vs2.push_back(vs1.back());
        vs1.pop_back();
    }
    cout<<"��ǩ��ɣ�������£�"<<endl;
    cout<<"��һ���ѡ��Ϊ��"<<endl;
    for_each(vs1.begin(),vs1.end(),myprint_1);
    cout<<endl<<"�ڶ����ѡ��Ϊ��"<<endl;
    for_each(vs2.begin(),vs2.end(),myprint_1);
    cout<<endl<<"������������������������������������������������������������������������������������"<<endl;
    //������һ�ֱ�������ÿ��ѡ�ָ���
    cout<<endl<<"����������......"<<endl;
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
    cout<<"��һ���ѡ�ַ���Ϊ:"<<endl;
    for_each(vs1.begin(),vs1.end(),myprint_2);
    cout<<endl<<"�ڶ����ѡ�ַ���Ϊ:"<<endl;
    for_each(vs2.begin(),vs2.end(),myprint_2);

    //��һ�ֱ���������ѡ��������ѡ�֣��������
    cout<<endl<<"������������������������������������������������������������������������������������"<<endl;
    vector<Speaker> vs3;
    //multiset<Speaker,mycompare> ss;
    //vs3.resize(6);
    merge(vs1.rbegin()+3, vs1.rbegin()+6,vs2.rbegin()+3, vs2.rbegin()+6,  // ��һ��ǰ3��vs2.rbegin(), vs2.rbegin()+3,  // �ڶ���ǰ3��
      back_inserter(vs3),mysortrule_1);            // �Զ�����Ԫ��
    //    [](Speaker& a,Speaker& b) {
    //        return a.getscore_1() > b.getscore_1(); // ���ֽ���ϲ�
    //    });
    
    cout<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout<<"��һ�ֱ�����������������ѡ�����£�"<<endl;
    // for(vector<Speaker>::iterator it=vs3.begin();it!=vs3.end();it++)
    // {
    //     ss.insert(*it);
    // }
    sort(vs3.begin(),vs3.end(),mysortrule_1);
    for_each(vs3.begin(),vs3.end(),myprint_2);
    
    //������ʼ�������������ѡ�ָ���
    cout<<endl<<"������������������������������������������������������������������������������������"<<endl;
    cout<<"������ʼ"<<endl;
    cout<<"ѡ�����ڽ��б���....."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    for(vector<Speaker>::iterator it=vs3.begin();it!=vs3.end();it++)
    {
        int score=(rand()%21)+80;
        it->setscore(score);
    }
    cout<<"����ѡ�ֵ��ݽ���ϣ���ί������£�"<<endl;
    for_each(vs3.begin(),vs3.end(),myprint_3);
}

int main()
{
    game();
    
    return 0;
}