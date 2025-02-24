/****************************************************************
* 计算机高级语言课程设计
*
* 题 目: 通讯录管理系统
* 作 者: 杜光阳
* 时 间: 2024.12.05
* All right reserved.
****************************************************************/

#include <iostream>		// 输入输出流 
#include <iomanip>		// 流格式 
#include <fstream>		// 文件流 
#include <string>		// 字符串 
#include <vector>		// 标准模板库-向量容器 
#include <algorithm>	// 标准模板库-算法库 
#include <cmath>		// C语言数学函数库 
using namespace std;
#define max 1000

// 各函数和类的前向声明 ------------------------------------------------------------------
void showmenu();
void addcontact();
void showcontacts();
int searchcontact();
void deletecontact();
void modifycontact();
void emptycontacts();
class contact;
class addresslist;

// 类等结构及全局变量/数组等的定义 ---------------------------------------------
class contact
{
public:
	string m_name;
	string m_company;
	string m_email;
	string m_phonenumber;

	void print_single()
	{
		cout << "\n\t姓名：" << m_name << endl;
		cout << "\n\t公司：" << m_company << endl;
		cout << "\n\t电邮：" << m_email << endl;
		cout << "\n\t电话：" << m_phonenumber << endl;
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
			cout << "目前您的通讯录里空空如也......" << endl;
		}
	}
};

// 各函数的定义 ----------------------------------------------------------------
void showmenu()//函数实现展示主菜单功能
{
	cout << "\n\t******************************************************************\n";
	cout << "\n\t*********************    通讯里管理系统    *********************\n";
	cout << "\n\t***     1: 浏览                                    2：新建     ***\n";
	cout << "\n\t***     3: 修改                                    4: 删除     ***\n";
	cout << "\n\t***     5: 查询                                    6: 清空     ***\n";
	cout << "\n\t*********************    如要退出请按0     *********************\n";
	cout << "\n\t------------------------------------------------------------------\n";
	cout << "\n\t请选择功能序号(1-6): [ ]\b\b";
}

void addcontact(addresslist& list)
{
	cout << "新建联系人" << endl;
	cout << "请输入联系人的姓名：";
	cin >> list.con[list.n].m_name;
	cout << "请输入联系人的公司：";
	cin >> list.con[list.n].m_company;
	cout << "请输入联系人的电邮：";
	cin >> list.con[list.n].m_email;
	cout << "请输入联系人的电话：";
	cin >> list.con[list.n].m_phonenumber;
	list.n++;
	cout << "新建联系人完成！" << endl;
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
		cout << "未找到相关联系人，请检查是否输入正确..." << endl;
		return y;
	}

}

void modifycontact(addresslist& list)
{
	cout << "请输入您想要修改的联系人的姓名或者电话：";

	int y = searchcontact(list);
	if (y != -1)
	{
		cout << "修改联系人" << endl;
		cout << "请输入联系人的姓名：";
		cin >> list.con[y].m_name;
		cout << "请输入联系人的公司：";
		cin >> list.con[y].m_company;
		cout << "请输入联系人的电邮：";
		cin >> list.con[y].m_email;
		cout << "请输入联系人的电话：";
		cin >> list.con[y].m_phonenumber;
		cout << "修改联系人完成！" << endl;
	}
}

void deletecontact(addresslist& list)
{
	cout << "请输入您想要删除的联系人的姓名或者电话：";

	int y = searchcontact(list);
	if (y != -1)
	{
		for (int j = y; j < list.n; j++)
		{
			list.con[j] = list.con[j + 1];
		}
		list.n--;
		cout << "删除联系人成功！" << endl;
	}
}

void emptycontacts(addresslist& list)
{
	cout << "您确定要清空您的通讯录吗？[ ]" << endl;
	cout << "Y:确定  N：取消" << endl;
	string z;
	cin >> z;
	if (z == "Y" || z == "y")
	{
		list.n = 0;
		cout << "您的通讯录已清空！" << endl;
	}
	else
	{
		cout << "已取消清空操作！" << endl;
	}
}

// 主函数 ---------------------------------------------------------------------- 
int main()
{
	addresslist list;//建立一个通讯录列表，来储存各个联系人
	// 打开文件读数据
	std::ifstream in("Data.txt");
	if (!in)
	{
		cout << "\n打开文件失败，请先检查该文件是否存在！\n即将退出系统\n" << endl;
		exit(0);
	}

	// 如果文件顺利打开，则开始一行行地读数据
	// 每行数据依次是职工的姓名、工作单位、电邮和电话号码
	while (in >> list.con[list.n].m_name >> list.con[list.n].m_company >> list.con[list.n].m_email >> list.con[list.n].m_phonenumber)
	{
		list.n++;
	}
	in.close();

	//showcontacts(list);

	cout << "欢迎使用通讯录管理系统！" << endl;

	while (1)
	{
		showmenu();//调用函数showmenu来展示主菜单
		cout << endl;
		//使用类、函数等实现功能
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
			cout << "请输入您想查询的联系人的姓名或电话：";
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
			cout << "您确定要退出吗？[ ]" << endl;
			cout << "Y:确定  N：取消" << endl;
			string z;
			cin >> z;
			if (z == "Y" || z == "y")
			{
				//退出之前保存数据
				// 打开文件写数据 
				//ofstream out("工资数据.txt");	// 在源程序文件的同一路径下写入职工工资信息数据
				ofstream out("Data.txt");	// 在源程序文件的同一路径下写入职工工资信息数据
				if (!out)
				{
					cout << "\n打开文件失败，请先检查该文件是否存在！\n即将退出系统\n" << endl;
					exit(0);
				}
				// 如果文件顺利打开，则开始一行行地写数据
				// 每行数据依次是职工的姓名、公司、电邮、电话号码
				for (int i = 0; i < list.n; i++)
				{
					out << list.con[i].m_name << "\t" << list.con[i].m_company << "\t" << list.con[i].m_email << "\t" << list.con[i].m_phonenumber << endl;
				}
				out.close();	// 在源程序文件的同一路径下写入职工工资信息数据

				cout << "感谢您的使用！期待下次再见！" << endl;
				system("cls");
				return 0;//退出程序
			}
			else
			{
				cout << "感谢您的大力支持!\n" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		}
	}
}