/******************************************************************************
** ������߼����Կγ���� 
**
** Example: ������Ϣ����ϵͳ 
**
** ����: �ŷ�
**
** ʱ��: Dec., 2024.
**
** All rights reserved. Copyright (c) 2024-2025.  
**
** ˼·: ��һ����������s�������ְ���Ĺ�����Ϣ��������main����ʱ��ԭʼ�Ĺ�������
         �ļ��ж�ȡ��������s���Լ����˳�����ǰ��s������д�빤�������ļ����⣬��
		 ���Ĳ�������ֱ�Ӳ����ļ��������������s���ɡ������������ѯ���޸ġ����ӡ�
		 ɾ��������Ȳ��������Ƕ�����s�������㡣
******************************************************************************/

#include <iostream>		// ��������� 
#include <iomanip>		// ����ʽ 
#include <fstream>		// �ļ��� 
#include <string>		// �ַ��� 
#include <vector>		// ��׼ģ���-�������� 
#include <algorithm>	// ��׼ģ���-�㷨�� 

using namespace std;

// ְ��������Ϣ���Լ�ְ��������Ϣ������Ķ��� ---------------------------------------------- 
class CManager;	// ǰ��������������CWorker�����õ��˺��涨���CManager�ࣩ 

// ְ��������Ϣ�� 
class CWorker
{
protected:
	int gh;			// ����
	string name;	// ����
	float jbgz;		// ��������
	float jj;		// ����
	float kk;		// �ۿ�
	float yfgz;		// Ӧ������(=��������+����-�ۿ�)
	float sk;		// ˰��(����Ӧ�����ʽ��н��ݽ�˰)
	float sfgz;		// ʵ������(=Ӧ������-˰��)
	
	friend class CManager;	// CManager��Ϊ CWorker����Ԫ����ֱ�Ӳ���CWorker�����ݳ�Ա 
};

// ְ��������Ϣ������
class CManager
{
public:
	CManager(string szFileName);	// ���캯��(�贫�빤����Ϣ�ļ���) 
	~CManager();	// ��������(��sд�빤����Ϣ�ļ�) 
	
	void ShowMainMenu();	// ��ʾ�����棨�ṩ������ģ�����ڣ� 
	
	void Read_File(string szFileName);	// �ӹ�����Ϣ�ļ��ж���ְ���Ĺ�����Ϣ����
	void Write_File(string szFileName);	// ��ְ���Ĺ�����Ϣ���ݱ��浽������Ϣ�����ļ���
	
public: // ������ģ���ʵ�ֺ��� 
	int Quit();		// �˳����� 
	void Caculate();// ����ģ��(����ÿ��ְ����Ӧ�����ʡ�˰�ʵ������)
	void Append();	// ����ģ��	
	void Display();	// ���ģ��	
	void Modify();	// �޸�ģ��	
	int Query();	// ��ѯģ��
	void Delete();	// ɾ��ģ��
	void Sort();	// ����ģ��(��ʵ�����ʽ��н�������)
	
protected:
	vector<CWorker> s;	// ���ְ���Ĺ�����Ϣ����
	string m_szFileName;// ְ��������Ϣ�ļ���������д�ļ���Ŀ���ļ��� 
};

// ���캯��(�贫�빤����Ϣ�ļ���) 
CManager::CManager(string szFileName)
{
	m_szFileName = szFileName;
	Read_File(szFileName);	// �ӹ�����Ϣ�ļ��ж���ְ���Ĺ�����Ϣ���� 
}

// ��������(��sд�빤����Ϣ�ļ�) 
CManager::~CManager()
{
	// �˳�ϵͳǰ���ȱ��������
	Write_File(m_szFileName);
}

// ����ģ�麯���Ķ���  ---------------------------------------------------

// �ӹ�����Ϣ�ļ��ж���ְ���Ĺ�����Ϣ����
void CManager::Read_File(string szFileName)
{
	// ���ļ������� 
	//std::ifstream in("��������.txt");	// ע��: �������ȫ·������Ҫ����ļ���Դ�����ļ���ͬһ·����
	std::ifstream in(szFileName.c_str());
	
 	if(!in)
 	{
 		cout<<"\n���ļ�ʧ�ܣ����ȼ����ļ��Ƿ���ڣ�\n�����˳�ϵͳ\n"<<endl;
 		exit(0);
 	}
 	
 	s.clear();	// ������� 	
 	// ����ļ�˳���򿪣���ʼһ���еض�����
 	// ÿ������������ְ���Ĺ��š��������������ʡ����𡢿ۿӦ�����ʡ�˰�ʵ������
 	// ����ĳ������Ϊ:     1	����	600	85	80	0	0	0
	while(!in.eof())
	{
		CWorker a;
		if(in>>a.gh>>a.name>>a.jbgz>>a.jj>>a.kk>>a.yfgz>>a.sk>>a.sfgz)// �����ɹ�(true)������ӵ����������� 
			s.push_back(a);
		else
		{
			in.clear();	// ���״̬Ϊ��Чʱ����ʹ��ָ�Ϊ��Ч״̬ ����ֹͣ���ļ� 
			break;
		}
	}
	in.close();
}

// ��ְ���Ĺ�����Ϣ���ݱ��浽������Ϣ�����ļ���
void CManager::Write_File(string szFileName)
{
	int i=0, N=s.size();
	// ���ļ�д���� 
	//ofstream out("��������.txt");	// ��Դ�����ļ���ͬһ·����д��ְ��������Ϣ����
	ofstream out(szFileName.c_str());	// ��Դ�����ļ���ͬһ·����д��ְ��������Ϣ����
 	if(!out)
 	{
 		cout<<"\n���ļ�ʧ�ܣ����ȼ����ļ��Ƿ���ڣ�\n�����˳�ϵͳ\n"<<endl;
 		exit(0);
 	}
 	
 	// ����ļ�˳���򿪣���ʼһ���е�д����
 	// ÿ������������ְ���Ĺ��š��������������ʡ����𡢿ۿӦ�����ʡ�˰�ʵ������
 	// ����ĳ������Ϊ:     1	����	600	85	80	0	0	0
 	for(i=0; i<N; i++)
 	{
 		out<<s[i].gh<<"\t"<<s[i].name<<"\t"<<s[i].jbgz<<"\t"<<s[i].jj<<"\t"<<s[i].kk<<"\t"<<s[i].yfgz<<"\t"<<s[i].sk<<"\t"<<s[i].sfgz<<endl;
 	}
	out.close();
}

// �˳����� 
int CManager::Quit()
{
	char c;
	cout<<("�����Ҫ�˳���ϵͳ��?(Y/N) [ ]\b\b");
	cin>>c;
	if(c=='Y'||c=='y')
	{
		cout<<"\nлл�ݹˣ���ӭ����!  :) \n"<<endl;
		system("pause");
		return 0;
	}
	else
	{
		cout<<"��л���Ĵ���֧��!\n"<<endl;
		return -1;
	}
}

// ����ģ��(����ÿ��ְ����Ӧ�����ʡ�˰�ʵ������)
void CManager::Caculate()
{
	int i=0, N=s.size();
	// ����ÿ��ְ����Ӧ�����ʡ�˰�ʵ������ 
	for(i=0; i<N; i++)
	{
		// ����Ӧ������ 
		s[i].yfgz = s[i].jbgz + s[i].jj - s[i].kk;
		
		// ����Ӧ�۵�˰�� 
		if(s[i].yfgz<2000.0f)
			s[i].sk = 0.0f;
		else if(s[i].yfgz<8000.0f)
			s[i].sk = 0.05f*(s[i].yfgz-2000.0f);
		else
			s[i].sk = 300.0f+0.1f*(s[i].yfgz-8000.0f);
		
		// ����ʵ������
		s[i].sfgz = s[i].yfgz - s[i].sk;
	}
}

// ����ģ��
void CManager::Append()
{
	int n, i;
	cout<<"�����������ӵ�ְ����: ";
	cin>>n;
	
	cout<<"�����������ӵ�ÿλְ�����ʵ���ϸ��Ϣ:\n"<<endl;
	for(i=0; i<n; i++)
	{
		cout<<"\n��"<<(i+1)<<"λְ���Ĺ�����Ϣ --------------"<<endl;
		CWorker a;
		cout<<"\t����: ";
		cin>>a.gh;		
		cout<<"\t����: ";
		cin>>a.name;		
		cout<<"\t��������: ";
		cin>>a.jbgz;		
		cout<<"\t����: ";
		cin>>a.jj;		
		cout<<"\t�ۿ�: ";
		cin>>a.kk;
		s.push_back(a);
	}

	// ����ְ����Ӧ�����ʡ�˰�ʵ������
	Caculate();
} 

// ���ģ�� 
void CManager::Display()
{
	int i=0, N=s.size();
	system("cls");	// ����
	cout<<"����\t����\t����\t����\t�ۿ�\tӦ��\t˰��\tʵ��"<<endl; 
	for(i=0; i<N; i++)
 	{
 		cout<<s[i].gh<<"\t"<<s[i].name<<"\t"<<s[i].jbgz<<"\t"<<s[i].jj<<"\t"<<s[i].kk<<"\t"<<s[i].yfgz<<"\t"<<s[i].sk<<"\t"<<s[i].sfgz<<endl;
	 	if(i%10==9)	// ������ʾ 
	 	{
	 		cout<<"\n��������������\n";
	 		system("pause");
	 	}
 	}
}

// �޸�ģ��
void CManager::Modify()
{
	int j = -1, number=0, option=0;
	char c;

	// ���޸�֮ǰ������ְ����ѯ
	j = Query();
	if(j>=0)
	{// ��Բ��ҵ���ְ�������乤����Ϣ�����޸� 
		option = 0;
		while(!option)
		{
			cout<<"\n���޸ĸ�ְ�������������Ϣ:\n";
			cout<<"\n\t***     1: ����             2: ����\n";
			cout<<"\n\t***     3: ��������         4: ����\n";
			cout<<"\n\t***     5: �ۿ�\n";
			cout<<"\n\t------------------------------------------------------------------\n";
	
			while(!option)
			{
				cout<<"\n\t��ѡ�������: [ ]\b\b";
				cin>>option;
				
				if(option==1)	// �޸����� 
				{
					cout<<"\n������Ϊ: ";
					cin>>s[j].name;
				}
				else if(option==2)	// �޸Ĺ��� 
				{
					cout<<"\n���Ÿ�Ϊ: ";
					cin>>s[j].gh;
				}
				else if(option==3)	// �޸Ļ�������
				{
					cout<<"\n�������ʸ�Ϊ: ";
					cin>>s[j].jbgz;
				} 
				else if(option==4)	// �޸Ľ���
				{
					cout<<"\n�����Ϊ: ";
					cin>>s[j].jj;
				} 
				else if(option==5)	// �޸Ŀۿ�
				{
					cout<<"\n�ۿ��Ϊ: ";
					cin>>s[j].kk;
				} 
				else
				{
					cout<<"\n �������˴������ţ�����������!\n";
					option = 0;
					system("pause");
				}
			}
			
			// �޸�������¼���Ӧ�����ʡ�˰���ʵ������ 
			Caculate();
			
			// �Ƿ�����޸ĸ�ְ���Ĺ�����Ϣ
			cout<<"�Ƿ�����޸ĸ�ְ���Ĺ�����Ϣ?(Y/N) [ ]\b\b";
			cin>>c;
			if(c=='Y'||c=='y')
			{
				option = 0;
			}
		}	
	}
} 

// ��ѯģ��
int CManager::Query()
{
	int i=0, j=-1, number=0, option=0, N=s.size();
	string name;
	
	// ����ʾ����ְ��������Ϣ 
	Display();

	// ��ͨ�����������߹��ţ����ҵ�Ҫ�޸ĵ�ְ��
	cout<<"\n\n";
	cout<<"\n\t�밴���·�ʽ��ѯְ���Ĺ�����Ϣ\n";
	cout<<"\n\t***     1: ����\n";
	cout<<"\n\t***     2: ����\n";
	cout<<"\n\t------------------------------------------------------------------\n";
	while(!option)
	{
		cout<<"\n\t��ѡ�������: [ ]\b\b";
		cin>>option;
		
		if(option==1)	// ��������ѯ 
		{
			cout<<"\n����������: ";
			cin>>name;
			
			for(i=0; i<N; i++)
			{
				if(name==s[i].name)
				{
					j = i;
					break;
				}
			}
			break;
		}
		else if(option==2)	// �����Ų�ѯ 
		{
			cout<<"\n�����빤��: ";
			cin>>number;
			
			for(i=0; i<N; i++)
			{
				if(number == s[i].gh)
				{
					j = i;
					break;
				}
			}
			break;
		}
		else
		{
			cout<<"\n �������˴������ţ�����������!\n";
			option = 0;
			system("pause");
		}
	}
	
	if(j<0)
	{
		cout<<"���޴���!\n";
		system("pause");
	}
	else
	{
		// ���޸�ǰ���鿴��ְ���Ĺ�����Ϣ 
		cout<<"��ְ���Ĺ�����Ϣ����:\n";
		cout<<"����    ����      ��������  ����      �ۿ�      Ӧ������  ˰��      ʵ������\n";
		cout<<s[j].gh<<"\t"<<s[j].name<<"\t"<<s[j].jbgz<<"\t"<<s[j].jj<<"\t"<<s[j].kk<<"\t"<<s[j].yfgz<<"\t"<<s[j].sk<<"\t"<<s[j].sfgz<<endl;
	}
	return j;
}

// ɾ��ģ��
void CManager::Delete()
{
	int i, j = -1;

	// ��ɾ��ǰ������ְ����ѯ
	j = Query();
	if(j>=0)
	{// // ��Բ��ҵ���ְ��������ɾ��
		char c;
		cout<<"\n��ȷ��Ҫɾ����ְ���Ĺ�����Ϣ��?(Y/N) [ ]\b\b";
		cin>>c;
		if(c=='Y'||c=='y')
		{
			s.erase(s.begin()+j);
		}
	}
}

// ����ģ��(��ʵ�����ʽ��н�������)
void CManager::Sort()
{
	int i, j, N=s.size();
	CWorker t;
	for(i=0; i<N-1; i++)	// ð�ݷ��������� 
	{
		for(j=0; j<N-1-i; j++)
		{
			if(s[j].sfgz<s[j+1].sfgz)
			{
				t = s[j];
				s[j] = s[j+1];
				s[j+1] = t;
			}
		}
	} 
}

// ������ 
void CManager::ShowMainMenu()
{
	int option=-1;	// ѡ��

	do 
	{
		 
		system("cls");	// ����
		system("color 3f");	// ������Ļ��ǰ�����֣��ͱ�������ɫ

		// ������
		cout<<"\n\t******************************************************************\n";
		cout<<"\n\t*********************    ְ��������Ϣϵͳ    *********************\n";
		cout<<"\n\t***     1: ���                                    2: ����     ***\n";
		cout<<"\n\t***     3: ����                                    4: �޸�     ***\n";
		cout<<"\n\t***     5: ɾ��                                    6: ��ѯ     ***\n";
		cout<<"\n\t***     7: ����                                    8: �˳�     ***\n";
		cout<<"\n\t------------------------------------------------------------------\n";
		cout<<"\n\t��ѡ�������(1-8): [ ]\b\b";
		cin>>option;

		switch(option)
		{
		case 1:	// ���ģ�� 
			Display();
			break;
		case 2:	// ����ģ��
			Caculate();
			break;
		case 3:	// ����ģ��
			Append();
			break;
		case 4:	// �޸�ģ��
			Modify();
			break;
		case 5:	// ɾ��ģ��
			Delete();
			break;
		case 6:	// ��ѯģ��
			Query();
			break;
		case 7:	// ����ģ��
			Sort();
			break;
		case 8:	// �˳����� 
			option = Quit();	// 0: ȷʵ�˳� 
			break;
		default:
			cout<<"\n �������˴������ţ�����������!";
			option = -1;
			break;
		}
		
		if(option)	// ��������˳����򷵻ص������� 
		{
			cout<<"\n�밴������������˵�����!\n";
			system("pause"); // �ȴ��������
		}
		
	} while (option);
}

// ������ 
int main()
{
	// ����һ��������Ϣ������� 
	CManager oMan("��������.txt");	
	// ʣ�µ�����ȫ����oMan����ȥ��
	oMan.ShowMainMenu();

	return 0;
}
