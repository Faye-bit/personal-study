/****************************************************************
* ������߼����Կγ���� 
*
* �� Ŀ: ͨѶ¼����ϵͳ
* �� ��: �Ź���
* ʱ ��: 2024.12.05
* All right reserved.
****************************************************************/

#include <iostream>		// ��������� 
#include <iomanip>		// ����ʽ 
#include <fstream>		// �ļ��� 
#include <string>		// �ַ��� 
#include <vector>		// ��׼ģ���-�������� 
#include <algorithm>	// ��׼ģ���-�㷨�� 
#include <cmath>		// C������ѧ������ 
using namespace std;
#define max 1000

// �����������ǰ������ ------------------------------------------------------------------
void showmenu();
void addcontact();
int searchcontact();
void deletecontact();
void modifycontact();
void emptycontacts();
class contact;
class addresslist;

// ��Ƚṹ��ȫ�ֱ���/����ȵĶ��� ---------------------------------------------
class contact//������ϵ���ࣨcontact��
{
public:
	string m_name;//��ϵ������
	string m_company;//��ϵ�˹�����λ
	string m_email;//��ϵ�˵�������
	string m_phonenumber;//��ϵ�˵绰����

public:
	void print_single()//����Ϊ����������ӡ������ϵ�˵���Ϣ
	{
		cout<<"\n\t������"<<m_name<<endl;//��ӡ����
		cout<<"\n\t��˾��"<<m_company<<endl;//��ӡ��˾
		cout<<"\n\t���ʣ�"<<m_email<<endl;//��ӡ����
		cout<<"\n\t�绰��"<<m_phonenumber<<endl;//��ӡ�绰
		cout<<endl;
	}
};

class addresslist//����ͨѶ¼�ࣨaddresslist��
{
public:
	contact con[max];//��ϵ���������
	int n=0;//��ϵ�˸���

	void print_all()//����Ϊ����������ӡ������ϵ�˵���Ϣ
	{
		for(int i=0;i<n;i++)
		{
			con[i].print_single();
		}

		if(n==0)//û����ϵ�˵Ļ�����ӡ��ʾ�������Ŀǰ����ͨѶ¼��տ���Ҳ......
		{
			cout<<"Ŀǰ����ͨѶ¼��տ���Ҳ......"<<endl;
		}
	}
};

// �������Ķ��� ----------------------------------------------------------------
void showmenu()//����ʵ��չʾ���˵�����
{
	cout<<"\n\t******************************************************************\n";
	cout<<"\n\t*********************    ͨѶ�����ϵͳ    ************************\n";
	cout<<"\n\t***     1: ���                                    2���½�     ***\n";
	cout<<"\n\t***     3: �޸�                                    4: ɾ��     ***\n";
	cout<<"\n\t***     5: ��ѯ                                    6: ���     ***\n";
	cout<<"\n\t*********************    ��Ҫ�˳��밴0     ************************\n";
	cout<<"\n\t------------------------------------------------------------------\n";
	cout<<"\n\t��ѡ�������(1-6): [ ]\b\b";
}

void addcontact(addresslist &list)//����ʵ���½���ϵ�˹���
{
	cout<<"�½���ϵ��"<<endl;//��ʾ��
	cout<<"��������ϵ�˵�������";//��ʾ�û�������ϵ������
	cin>>list.con[list.n].m_name;
	cout<<"��������ϵ�˵Ĺ�˾��";//��ʾ�û�������ϵ�˹�˾
	cin>>list.con[list.n].m_company;
	cout<<"��������ϵ�˵ĵ��ʣ�";//��ʾ�û�������ϵ�˵���
	cin>>list.con[list.n].m_email;
	cout<<"��������ϵ�˵ĵ绰��";//��ʾ�û�������ϵ�˵绰
	cin>>list.con[list.n].m_phonenumber;
	list.n++;
	cout<<"�½���ϵ����ɣ�"<<endl;//��ʾ��
}

int searchcontact(addresslist &list)//����ʵ�ֲ�����ϵ�˹���
{
	string find;
	cin>>find;
	int y=-1;//�����������洢��ϵ�˵ı��
	for(int i=0;i<list.n;i++)//ͨ���û�������ַ���ƥ���Ӧ����ϵ��
	{
		if(find==list.con[i].m_name||find==list.con[i].m_phonenumber)
		{
			y=i;
		}
	}

	if(y!=-1)//�ҵ��˶�Ӧ����ϵ���򷵻���ϵ�˱��
	{
		return y;
	}
	else//��û���ҵ����û�������ַ���Ӧ����ϵ��������绰����ʾ�û���δ�ҵ������ϵ�ˣ������Ƿ�������ȷ...��
	{
		cout<<"δ�ҵ������ϵ�ˣ������Ƿ�������ȷ..."<<endl;
		return y;
	}
	
}

void modifycontact(addresslist &list)//����ʵ���޸���ϵ�˹���
{
	cout<<"����������Ҫ�޸ĵ���ϵ�˵��������ߵ绰��";//��ʾ��
	
	int y=searchcontact(list);//�ȵ��ò�����ϵ�˺����������û���Ҫ�޸ĵ���ϵ��
	if(y!=-1)
	{
		
		cout<<"�޸���ϵ��"<<endl;//��ʾ��
		cout<<"��������ϵ�˵�������";//��ʾ�û�������ϵ������
		cin>>list.con[y].m_name;
		cout<<"��������ϵ�˵Ĺ�˾��";//��ʾ�û�������ϵ�˹�˾
		cin>>list.con[y].m_company;
		cout<<"��������ϵ�˵ĵ��ʣ�";//��ʾ�û�������ϵ�˵���
		cin>>list.con[y].m_email;
		cout<<"��������ϵ�˵ĵ绰��";//��ʾ�û�������ϵ�˵绰
		cin>>list.con[y].m_phonenumber;
		cout<<"�޸���ϵ����ɣ�"<<endl;//��ʾ��
	}
}

void deletecontact(addresslist &list)//����ʵ��ɾ����ϵ�˹���
{
	cout<<"����������Ҫɾ������ϵ�˵��������ߵ绰��";//��ʾ��
	
	int y=searchcontact(list);//�ȵ��ò�����ϵ�˺����������û���Ҫɾ������ϵ��
	if(y!=-1)
	{	
		//ͨ����ָ����ϵ�˺������ϵ�˶���ǰ���ǵķ�ʽ��ʵ��ɾ����ϵ�˵Ĺ���
		for(int j=y;j<list.n;j++)
		{
			list.con[j]=list.con[j+1];
		}
		list.n--;//���Ҳ�ý���ϵ�˵ĸ�����һ
		cout<<"ɾ����ϵ�˳ɹ���"<<endl;//��ʾ��
	}
}

void emptycontacts(addresslist &list)//����ʵ�����ͨѶ¼�Ĺ���
{
	//��ʾ���ֹ�û������
	cout<<"��ȷ��Ҫ�������ͨѶ¼��[ ]"<<endl;
	cout<<"Y:ȷ��  N��ȡ��"<<endl;
	string z;
	cin>>z;
	if(z=="Y"||z=="y")
	{
		list.n=0;
		cout<<"����ͨѶ¼����գ�"<<endl;
	}
	else
	{
		cout<<"��ȡ����ղ�����"<<endl;
	}
}

// ������ ---------------------------------------------------------------------- 
int main( )
{
	addresslist list;//����һ��ͨѶ¼�б������������ϵ��
	// ���ļ�������
	std::ifstream in("Data.txt");
 	if(!in)//����ļ���ȡδ�ɹ�
 	{
 		cout<<"\n���ļ�ʧ�ܣ����ȼ����ļ��Ƿ���ڣ�\n�����˳�ϵͳ\n"<<endl;
 		exit(0);
 	}
 	
 	// ����ļ�˳���򿪣���ʼһ���еض�����
 	// ÿ������������ְ����������������λ�����ʺ͵绰����
	while (in >> list.con[list.n].m_name >> list.con[list.n].m_company >> list.con[list.n].m_email >> list.con[list.n].m_phonenumber)
	{
    	list.n++;
	}
	in.close(); 

	cout<<"��ӭʹ��ͨѶ¼����ϵͳ��"<<endl;//��ʾ��

	while(1)//ͨ��while����ѭ���ó��������ж����˳�
	{
		showmenu();//���ú���showmenu��չʾ���˵�
		cout<<endl;
		//ʹ���ࡢ������ʵ�ֹ���
		int x;
		cin>>x;
		switch(x)//ͨ��switch�����ʵ�ָ����û���ͬ��������ʵ�־���Ĺ���
		{
			case(1)://����1��ִ�����ͨѶ¼�Ĺ���
			{
				list.print_all();//����addresslist����Ϊ��ӡ������ϵ����Ϣ

				system("pause");
				system("cls");
				break;
			}

			case(2)://����2����ִ�������ϵ�˵Ĺ���
			{
				addcontact(list);//����addcontact������ʵ�־��幦��

				system("pause");
				system("cls");
				break;
			}

			case(3)://����3����ִ���޸���ϵ�˵Ĺ���
			{
				modifycontact(list);//����modifycontact������ʵ�־��幦��

				system("pause");
				system("cls");
				break;
			}

			case(4)://����4����ִ��ɾ����ϵ�˵Ĺ���
			{
				deletecontact(list);//����deletecontact������ʵ�־��幦��

				system("pause");
				system("cls");
				break;
			}
			case(5)://����5����ִ�в�ѯ��ϵ�˵Ĺ���
			{
				cout<<"�����������ѯ����ϵ�˵�������绰��";//��ʾ��
				int y=searchcontact(list);//����searchcontact������ʵ�־��幦��
				if(y!=-1)
				{
					list.con[y].print_single();//����contact����Ϊ����ӡ������ϵ����Ϣ
				}

				system("pause");
				system("cls");
				break;
			}

			case(6)://����6����ִ�����ͨѶ¼�Ĺ���
			{
				emptycontacts(list);//����emptycontacts������ʵ�־��幦��

				system("pause");
				system("cls");
				break;
			}

			case(0)://����0���˳�����
			{
				cout<<"��ȷ��Ҫ�˳���[ ]"<<endl;
				cout<<"Y:ȷ��  N��ȡ��"<<endl;
				string z;
				cin>>z;
				if(z=="Y"||z=="y")
				{
					//�˳�֮ǰ��������
					// ���ļ�д���� 
					//ofstream out("��������.txt");	// ��Դ�����ļ���ͬһ·����д��ְ��������Ϣ����
					ofstream out("Data.txt");	// ��Դ�����ļ���ͬһ·����д��ְ��������Ϣ����
 					if(!out)
 					{
 						cout<<"\nд���ļ�ʧ�ܣ����ȼ����ļ��Ƿ���ڣ�\n�����˳�ϵͳ\n"<<endl;
 						exit(0);
 					}
 					// ����ļ�˳���򿪣���ʼһ���е�д����
 					// ÿ������������ְ������������˾�����ʡ��绰����
 					for(int i=0; i<list.n; i++)
 					{
 						out<<list.con[i].m_name<<"\t"<<list.con[i].m_company<<"\t"<<list.con[i].m_email<<"\t"<<list.con[i].m_phonenumber<<endl;
 					}
					out.close();	// ��Դ�����ļ���ͬһ·����д��ְ��������Ϣ����

					cout<<"��л����ʹ�ã��ڴ��´��ټ���"<<endl;
					system("cls");
					return 0;//�˳�����
				}
				else
				{
					cout<<"��ȡ���˳�����л���Ĵ���֧��!\n"<<endl;
					system("pause");
					system("cls");
					break;
				}
			}

			default://����������������������ʾ"���๦�����ڿ����С����������ڴ���"
			{
				cout<<"���๦�����ڿ����С����������ڴ���"<<endl;
				system("pause");
				system("cls");
				break;
			}
	    }
	}
}
