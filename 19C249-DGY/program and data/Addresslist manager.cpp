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
int searchcontact();
void deletecontact();
void modifycontact();
void emptycontacts();
class contact;
class addresslist;

// 类等结构及全局变量/数组等的定义 ---------------------------------------------
class contact//定义联系人类（contact）
{
public:
	string m_name;//联系人姓名
	string m_company;//联系人工作单位
	string m_email;//联系人电子邮箱
	string m_phonenumber;//联系人电话号码

public:
	void print_single()//类行为————打印单个联系人的信息
	{
		cout<<"\n\t姓名："<<m_name<<endl;//打印姓名
		cout<<"\n\t公司："<<m_company<<endl;//打印公司
		cout<<"\n\t电邮："<<m_email<<endl;//打印电邮
		cout<<"\n\t电话："<<m_phonenumber<<endl;//打印电话
		cout<<endl;
	}
};

class addresslist//定义通讯录类（addresslist）
{
public:
	contact con[max];//联系人类的数组
	int n=0;//联系人个数

	void print_all()//类行为————打印所有联系人的信息
	{
		for(int i=0;i<n;i++)
		{
			con[i].print_single();
		}

		if(n==0)//没有联系人的话，打印提示语————目前您的通讯录里空空如也......
		{
			cout<<"目前您的通讯录里空空如也......"<<endl;
		}
	}
};

// 各函数的定义 ----------------------------------------------------------------
void showmenu()//函数实现展示主菜单功能
{
	cout<<"\n\t******************************************************************\n";
	cout<<"\n\t*********************    通讯里管理系统    ************************\n";
	cout<<"\n\t***     1: 浏览                                    2：新建     ***\n";
	cout<<"\n\t***     3: 修改                                    4: 删除     ***\n";
	cout<<"\n\t***     5: 查询                                    6: 清空     ***\n";
	cout<<"\n\t*********************    如要退出请按0     ************************\n";
	cout<<"\n\t------------------------------------------------------------------\n";
	cout<<"\n\t请选择功能序号(1-6): [ ]\b\b";
}

void addcontact(addresslist &list)//函数实现新建联系人功能
{
	cout<<"新建联系人"<<endl;//提示语
	cout<<"请输入联系人的姓名：";//提示用户输入联系人姓名
	cin>>list.con[list.n].m_name;
	cout<<"请输入联系人的公司：";//提示用户输入联系人公司
	cin>>list.con[list.n].m_company;
	cout<<"请输入联系人的电邮：";//提示用户输入联系人电邮
	cin>>list.con[list.n].m_email;
	cout<<"请输入联系人的电话：";//提示用户输入联系人电话
	cin>>list.con[list.n].m_phonenumber;
	list.n++;
	cout<<"新建联系人完成！"<<endl;//提示语
}

int searchcontact(addresslist &list)//函数实现查找联系人功能
{
	string find;
	cin>>find;
	int y=-1;//声明变量来存储联系人的编号
	for(int i=0;i<list.n;i++)//通过用户输入的字符来匹配对应的联系人
	{
		if(find==list.con[i].m_name||find==list.con[i].m_phonenumber)
		{
			y=i;
		}
	}

	if(y!=-1)//找到了对应的联系人则返回联系人编号
	{
		return y;
	}
	else//若没有找到与用户输入的字符对应的联系人姓名或电话这提示用户“未找到相关联系人，请检查是否输入正确...”
	{
		cout<<"未找到相关联系人，请检查是否输入正确..."<<endl;
		return y;
	}
	
}

void modifycontact(addresslist &list)//函数实现修改联系人功能
{
	cout<<"请输入您想要修改的联系人的姓名或者电话：";//提示语
	
	int y=searchcontact(list);//先调用查找联系人函数来检索用户想要修改的联系人
	if(y!=-1)
	{
		
		cout<<"修改联系人"<<endl;//提示语
		cout<<"请输入联系人的姓名：";//提示用户输入联系人姓名
		cin>>list.con[y].m_name;
		cout<<"请输入联系人的公司：";//提示用户输入联系人公司
		cin>>list.con[y].m_company;
		cout<<"请输入联系人的电邮：";//提示用户输入联系人电邮
		cin>>list.con[y].m_email;
		cout<<"请输入联系人的电话：";//提示用户输入联系人电话
		cin>>list.con[y].m_phonenumber;
		cout<<"修改联系人完成！"<<endl;//提示语
	}
}

void deletecontact(addresslist &list)//函数实现删除联系人功能
{
	cout<<"请输入您想要删除的联系人的姓名或者电话：";//提示语
	
	int y=searchcontact(list);//先调用查找联系人函数来检索用户想要删除的联系人
	if(y!=-1)
	{	
		//通过将指定联系人后面的联系人都向前覆盖的方式来实现删除联系人的功能
		for(int j=y;j<list.n;j++)
		{
			list.con[j]=list.con[j+1];
		}
		list.n--;//最后也得将联系人的个数减一
		cout<<"删除联系人成功！"<<endl;//提示语
	}
}

void emptycontacts(addresslist &list)//函数实现清空通讯录的功能
{
	//提示语防止用户误操作
	cout<<"您确定要清空您的通讯录吗？[ ]"<<endl;
	cout<<"Y:确定  N：取消"<<endl;
	string z;
	cin>>z;
	if(z=="Y"||z=="y")
	{
		list.n=0;
		cout<<"您的通讯录已清空！"<<endl;
	}
	else
	{
		cout<<"已取消清空操作！"<<endl;
	}
}

// 主函数 ---------------------------------------------------------------------- 
int main( )
{
	addresslist list;//建立一个通讯录列表，来储存各个联系人
	// 打开文件读数据
	std::ifstream in("Data.txt");
 	if(!in)//如果文件读取未成功
 	{
 		cout<<"\n打开文件失败，请先检查该文件是否存在！\n即将退出系统\n"<<endl;
 		exit(0);
 	}
 	
 	// 如果文件顺利打开，则开始一行行地读数据
 	// 每行数据依次是职工的姓名、工作单位、电邮和电话号码
	while (in >> list.con[list.n].m_name >> list.con[list.n].m_company >> list.con[list.n].m_email >> list.con[list.n].m_phonenumber)
	{
    	list.n++;
	}
	in.close(); 

	cout<<"欢迎使用通讯录管理系统！"<<endl;//提示语

	while(1)//通过while无限循环让程序多次运行而不退出
	{
		showmenu();//调用函数showmenu来展示主菜单
		cout<<endl;
		//使用类、函数等实现功能
		int x;
		cin>>x;
		switch(x)//通过switch语句来实现根据用户不同的输入来实现具体的功能
		{
			case(1)://按“1”执行浏览通讯录的功能
			{
				list.print_all();//调用addresslist类行为打印所有联系人信息

				system("pause");
				system("cls");
				break;
			}

			case(2)://按“2”来执行添加联系人的功能
			{
				addcontact(list);//调用addcontact函数来实现具体功能

				system("pause");
				system("cls");
				break;
			}

			case(3)://按“3”来执行修改联系人的功能
			{
				modifycontact(list);//调用modifycontact函数来实现具体功能

				system("pause");
				system("cls");
				break;
			}

			case(4)://按“4”来执行删除联系人的功能
			{
				deletecontact(list);//调用deletecontact函数来实现具体功能

				system("pause");
				system("cls");
				break;
			}
			case(5)://按“5”来执行查询联系人的功能
			{
				cout<<"请输入您想查询的联系人的姓名或电话：";//提示语
				int y=searchcontact(list);//调用searchcontact函数来实现具体功能
				if(y!=-1)
				{
					list.con[y].print_single();//调用contact类行为来打印单个联系人信息
				}

				system("pause");
				system("cls");
				break;
			}

			case(6)://按“6”来执行清空通讯录的功能
			{
				emptycontacts(list);//调用emptycontacts函数来实现具体功能

				system("pause");
				system("cls");
				break;
			}

			case(0)://按“0”退出程序
			{
				cout<<"您确定要退出吗？[ ]"<<endl;
				cout<<"Y:确定  N：取消"<<endl;
				string z;
				cin>>z;
				if(z=="Y"||z=="y")
				{
					//退出之前保存数据
					// 打开文件写数据 
					//ofstream out("工资数据.txt");	// 在源程序文件的同一路径下写入职工工资信息数据
					ofstream out("Data.txt");	// 在源程序文件的同一路径下写入职工工资信息数据
 					if(!out)
 					{
 						cout<<"\n写入文件失败，请先检查该文件是否存在！\n即将退出系统\n"<<endl;
 						exit(0);
 					}
 					// 如果文件顺利打开，则开始一行行地写数据
 					// 每行数据依次是职工的姓名、公司、电邮、电话号码
 					for(int i=0; i<list.n; i++)
 					{
 						out<<list.con[i].m_name<<"\t"<<list.con[i].m_company<<"\t"<<list.con[i].m_email<<"\t"<<list.con[i].m_phonenumber<<endl;
 					}
					out.close();	// 在源程序文件的同一路径下写入职工工资信息数据

					cout<<"感谢您的使用！期待下次再见！"<<endl;
					system("cls");
					return 0;//退出程序
				}
				else
				{
					cout<<"已取消退出，感谢您的大力支持!\n"<<endl;
					system("pause");
					system("cls");
					break;
				}
			}

			default://若输入了其他的数字则提示"更多功能正在开发中。。。敬请期待！"
			{
				cout<<"更多功能正在开发中。。。敬请期待！"<<endl;
				system("pause");
				system("cls");
				break;
			}
	    }
	}
}
