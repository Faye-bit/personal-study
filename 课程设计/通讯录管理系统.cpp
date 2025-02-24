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
void showcontacts();
int searchcontact();
void deletecontact();
void modifycontact();
void emptycontacts();
class contact;
class addresslist;

// ��Ƚṹ��ȫ�ֱ���/����ȵĶ��� ---------------------------------------------
class contact
{
public:
	string m_name;
	string m_company;
	string m_email;
	string m_phonenumber;

	void print_single()
	{
		cout << "\n\t������" << m_name << endl;
		cout << "\n\t��˾��" << m_company << endl;
		cout << "\n\t���ʣ�" << m_email << endl;
		cout << "\n\t�绰��" << m_phonenumber << endl;
		cout << endl;
	}
};

class addresslist
{
public:
	contact con[max];
	int n = 0;

	void print_all()
	{
		for (int i = 0; i < n; i++)
		{
			con[i].print_single();
		}

		if (n == 0)
		{
			cout << "Ŀǰ����ͨѶ¼��տ���Ҳ......" << endl;
		}
	}
};

// �������Ķ��� ----------------------------------------------------------------
void showmenu()//����ʵ��չʾ���˵�����
{
	cout << "\n\t******************************************************************\n";
	cout << "\n\t*********************    ͨѶ�����ϵͳ    *********************\n";
	cout << "\n\t***     1: ���                                    2���½�     ***\n";
	cout << "\n\t***     3: �޸�                                    4: ɾ��     ***\n";
	cout << "\n\t***     5: ��ѯ                                    6: ���     ***\n";
	cout << "\n\t*********************    ��Ҫ�˳��밴0     *********************\n";
	cout << "\n\t------------------------------------------------------------------\n";
	cout << "\n\t��ѡ�������(1-6): [ ]\b\b";
}

void addcontact(addresslist& list)
{
	cout << "�½���ϵ��" << endl;
	cout << "��������ϵ�˵�������";
	cin >> list.con[list.n].m_name;
	cout << "��������ϵ�˵Ĺ�˾��";
	cin >> list.con[list.n].m_company;
	cout << "��������ϵ�˵ĵ��ʣ�";
	cin >> list.con[list.n].m_email;
	cout << "��������ϵ�˵ĵ绰��";
	cin >> list.con[list.n].m_phonenumber;
	list.n++;
	cout << "�½���ϵ����ɣ�" << endl;
}

int searchcontact(addresslist& list)
{
	string find;
	cin >> find;
	int y = -1;
	for (int i = 0; i < list.n; i++)
	{
		if (find == list.con[i].m_name || find == list.con[i].m_phonenumber)
		{
			y = i;
		}
	}

	if (y != -1)
	{
		return y;
	}
	else
	{
		cout << "δ�ҵ������ϵ�ˣ������Ƿ�������ȷ..." << endl;
		return y;
	}

}

void modifycontact(addresslist& list)
{
	cout << "����������Ҫ�޸ĵ���ϵ�˵��������ߵ绰��";

	int y = searchcontact(list);
	if (y != -1)
	{
		cout << "�޸���ϵ��" << endl;
		cout << "��������ϵ�˵�������";
		cin >> list.con[y].m_name;
		cout << "��������ϵ�˵Ĺ�˾��";
		cin >> list.con[y].m_company;
		cout << "��������ϵ�˵ĵ��ʣ�";
		cin >> list.con[y].m_email;
		cout << "��������ϵ�˵ĵ绰��";
		cin >> list.con[y].m_phonenumber;
		cout << "�޸���ϵ����ɣ�" << endl;
	}
}

void deletecontact(addresslist& list)
{
	cout << "����������Ҫɾ������ϵ�˵��������ߵ绰��";

	int y = searchcontact(list);
	if (y != -1)
	{
		for (int j = y; j < list.n; j++)
		{
			list.con[j] = list.con[j + 1];
		}
		list.n--;
		cout << "ɾ����ϵ�˳ɹ���" << endl;
	}
}

void emptycontacts(addresslist& list)
{
	cout << "��ȷ��Ҫ�������ͨѶ¼��[ ]" << endl;
	cout << "Y:ȷ��  N��ȡ��" << endl;
	string z;
	cin >> z;
	if (z == "Y" || z == "y")
	{
		list.n = 0;
		cout << "����ͨѶ¼����գ�" << endl;
	}
	else
	{
		cout << "��ȡ����ղ�����" << endl;
	}
}

// ������ ---------------------------------------------------------------------- 
int main()
{
	addresslist list;//����һ��ͨѶ¼�б������������ϵ��
	// ���ļ�������
	std::ifstream in("Data.txt");
	if (!in)
	{
		cout << "\n���ļ�ʧ�ܣ����ȼ����ļ��Ƿ���ڣ�\n�����˳�ϵͳ\n" << endl;
		exit(0);
	}

	// ����ļ�˳���򿪣���ʼһ���еض�����
	// ÿ������������ְ����������������λ�����ʺ͵绰����
	while (in >> list.con[list.n].m_name >> list.con[list.n].m_company >> list.con[list.n].m_email >> list.con[list.n].m_phonenumber)
	{
		list.n++;
	}
	in.close();

	//showcontacts(list);

	cout << "��ӭʹ��ͨѶ¼����ϵͳ��" << endl;

	while (1)
	{
		showmenu();//���ú���showmenu��չʾ���˵�
		cout << endl;
		//ʹ���ࡢ������ʵ�ֹ���
		int x;
		cin >> x;
		switch (x)
		{
		case(1):
		{
			list.print_all();

			system("pause");
			system("cls");
			break;
		}

		case(2):
		{
			addcontact(list);

			system("pause");
			system("cls");
			break;
		}

		case(3):
		{
			modifycontact(list);

			system("pause");
			system("cls");
			break;
		}

		case(4):
		{
			deletecontact(list);

			system("pause");
			system("cls");
			break;
		}
		case(5):
		{
			cout << "�����������ѯ����ϵ�˵�������绰��";
			int y = searchcontact(list);
			if (y != -1)
			{
				list.con[y].print_single();
			}

			system("pause");
			system("cls");
			break;
		}

		case(6):
		{
			emptycontacts(list);

			system("pause");
			system("cls");
			break;
		}

		case(0):
		{
			cout << "��ȷ��Ҫ�˳���[ ]" << endl;
			cout << "Y:ȷ��  N��ȡ��" << endl;
			string z;
			cin >> z;
			if (z == "Y" || z == "y")
			{
				//�˳�֮ǰ��������
				// ���ļ�д���� 
				//ofstream out("��������.txt");	// ��Դ�����ļ���ͬһ·����д��ְ��������Ϣ����
				ofstream out("Data.txt");	// ��Դ�����ļ���ͬһ·����д��ְ��������Ϣ����
				if (!out)
				{
					cout << "\n���ļ�ʧ�ܣ����ȼ����ļ��Ƿ���ڣ�\n�����˳�ϵͳ\n" << endl;
					exit(0);
				}
				// ����ļ�˳���򿪣���ʼһ���е�д����
				// ÿ������������ְ������������˾�����ʡ��绰����
				for (int i = 0; i < list.n; i++)
				{
					out << list.con[i].m_name << "\t" << list.con[i].m_company << "\t" << list.con[i].m_email << "\t" << list.con[i].m_phonenumber << endl;
				}
				out.close();	// ��Դ�����ļ���ͬһ·����д��ְ��������Ϣ����

				cout << "��л����ʹ�ã��ڴ��´��ټ���" << endl;
				system("cls");
				return 0;//�˳�����
			}
			else
			{
				cout << "��л���Ĵ���֧��!\n" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		}
	}
}