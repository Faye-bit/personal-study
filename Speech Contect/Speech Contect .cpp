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
    cout <<"������������������������������������������������������������������������������������������" << endl;
    cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
    cout << "*************  4.�鿴��������  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
    cout <<"������������������������������������������������������������������������������������������" << endl;
	cout << endl;
}

void Manager::start()
{
    srand((unsigned int)time(NULL));

    //�ȳ�ʼ������ѡ��
    vector<Speaker> vs1;
    for(int i=1;i<(num+1);i++)
    {
        vs1.push_back(Speaker(10000+i));
    }

    cout<<"������ʼ��ѡ�ֿ�ʼ��ǩ���顣"<<endl;
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
    cout<<endl<<"������������������������������������������������������������������������������������"<<endl;
    cout<<"��ǩ��ɣ�������£�"<<endl;
    cout<<"��һ���ѡ��Ϊ��"<<endl;
    for_each(vs1.begin(),vs1.end(),myprint_1);
    cout<<endl<<"�ڶ����ѡ��Ϊ��"<<endl;
    for_each(vs2.begin(),vs2.end(),myprint_1);
    cout<<endl;
    system("pause");
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
    cout<<endl;
    system("pause");

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
    cout<<endl;
    system("pause");
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
    cout<<endl;
    system("pause");

    cout<<endl<<"������������������������������������������������������������������������������������"<<endl;
    cout<<"�����ձ������Ϊ��"<<endl;
    sort(vs3.begin(),vs3.end(),mysortrule_2);
    cout<<"��һ����";
    myprint_4(vs3[0]);
    cout<<"�ڶ�����";
    myprint_4(vs3[1]);
    cout<<"��������";
    myprint_4(vs3[2]);
    cout<<endl;
    //�����������
    system("pause");
    cout<<"����������..."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    save(vs3);
    cout<<"����ɹ���"<<endl;
    system("pause");
}

void Manager::read()
{
    ifstream in("data.csv");
    if(!in)
    {
        cout<<"�����¼�ļ������ڣ�"<<endl;
        return; // �޸�1�����˳�����
    }

    record.clear();
    string line;
    int session = 1; // ��ǰ����
    
    // ÿ�ζ�ȡ3����¼Ϊһ��
    vector<Speaker> temp;
    while(getline(in, line)&&!line.empty())
    {
        // ����������
        stringstream ss(line);
        string id_str, score1_str, score2_str;
        getline(ss, id_str, '\t');
        getline(ss, score1_str, '\t');
        getline(ss, score2_str, '\t');

        if(id_str.empty()) continue;
        

        Speaker ts(stoi(id_str), stoi(score1_str), stoi(score2_str));
        temp.push_back(ts);

        // ÿ�ռ�3��ѡ�ּ�¼����һ��
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
        cout<<"�����¼�����ڣ����Ƚ��б�����"<<endl;
    }
    in.close(); // ��ȷ�ر��ļ�����λ��
}

void Manager::show_record()
{
    read();
    for(multimap<int,Speaker>::iterator it=record.begin();it!=record.end();it++)
    {
        cout<<"��"<<it->first<<"���ݽ�����"<<endl;
        cout<<"��һ����";
        myprint_4(it->second);
        it++;
        cout<<"�ڶ�����";
        myprint_4(it->second);
        it++;
        cout<<"��������";
        myprint_4(it->second);
        cout<<endl;
    }

}

void Manager::save(const vector<Speaker>& vs) const
{
    ofstream out("data.csv",ios::app);
    if(!out)
    {
        cout<<"���ļ�ʧ�ܣ�\n�����ļ��Ƿ���ڣ�\n�����˳�ϵͳ��"<<endl;
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
    cout<<"��ȷ��Ҫ������ڱ�ϵͳ�����е����ݣ�"<<endl;
    cout<<"Y.ȷ��                       N.ȡ��"<<endl;
    cout<<"����Ϊ�����棬��������ѡ��";
    cin>>opt;

    if (opt=='y'||opt=='Y')
    {
        ofstream out("data.csv",ios::trunc);
        out.close();
        cout<<"��Ϊ������������ݣ�"<<endl;
    }
    else
    {
        cout<<"����ȡ���ò�����"<<endl;
    }
}

void Manager::introduce()
{
    cout<<"����������������������������������������������������������������������������������������������������������������������������������������������������"<<endl;
    cout<<"ѧУ����һ���ݽ�����������**12����**�μӡ�**����������**����һ��Ϊ��̭�����ڶ���Ϊ������"<<endl;
    cout<<"������ʽ��**���������ÿ��6����**��ѡ��ÿ��Ҫ������飬���б�����"<<endl;
    cout<<"ÿ��ѡ�ֶ��ж�Ӧ��**���**���� 10001 ~ 10012��"<<endl;
    cout<<"��һ�ַ�Ϊ����С�飬ÿ��6���ˡ� ���尴��ѡ�ֱ�Ž���**��ǩ**��˳���ݽ���"<<endl;
    cout<<"��С���ݽ������̭����������������ѡ�֣�**ǰ��������**��������һ�ֵı�����"<<endl;
    cout<<"�ڶ���Ϊ������**ǰ����ʤ��**��"<<endl;
    cout<<"ÿ�ֱ���������Ҫ**��ʾ����ѡ�ֵ���Ϣ**��"<<endl;
    cout<<"������û���������������ˣ�����������"<<endl;
    cout<<"����������������������������������������������������������������������������������������������������������������������������������������������������"<<endl;
    cout<<endl;
}

void Manager::quit()
{
    cout<<"Y.ȷ��      N.ȡ��"<<endl;
    cout<<"�Ƿ�ȷ���˳��ݽ�����ϵͳ��"<<endl;
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

void Manager::go()
{
    while(1)
    {
        menu();
        cout<<"����������ѡ��";
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
                cout<<"���๦�����ڿ�����......"<<endl;
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