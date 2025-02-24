/******************************************************************************
** 计算机高级语言课程设计 
**
** Example: 工资信息管理系统 
**
** 作者: 张飞
**
** 时间: Dec., 2024.
**
** All rights reserved. Copyright (c) 2024-2025.  
**
** 思路: 用一个向量容器s存放所有职工的工资信息，除了在main启动时从原始的工资数据
         文件中读取数据填入s，以及在退出程序前将s的数据写入工资数据文件以外，其
		 他的操作都不直接操作文件，仅需操作向量s即可。比如浏览、查询、修改、增加、
		 删除、排序等操作，都是对向量s进行运算。
******************************************************************************/

#include <iostream>		// 输入输出流 
#include <iomanip>		// 流格式 
#include <fstream>		// 文件流 
#include <string>		// 字符串 
#include <vector>		// 标准模板库-向量容器 
#include <algorithm>	// 标准模板库-算法库 

using namespace std;

// 职工工资信息类以及职工工资信息管理类的定义 ---------------------------------------------- 
class CManager;	// 前向引用声明（因CWorker类中用到了后面定义的CManager类） 

// 职工工资信息类 
class CWorker
{
protected:
	int gh;			// 工号
	string name;	// 姓名
	float jbgz;		// 基本工资
	float jj;		// 奖金
	float kk;		// 扣款
	float yfgz;		// 应发工资(=基本工资+奖金-扣款)
	float sk;		// 税款(根据应发工资进行阶梯缴税)
	float sfgz;		// 实发工资(=应发工资-税款)
	
	friend class CManager;	// CManager作为 CWorker的友元，可直接操纵CWorker的数据成员 
};

// 职工工资信息管理类
class CManager
{
public:
	CManager(string szFileName);	// 构造函数(需传入工资信息文件名) 
	~CManager();	// 析构函数(将s写入工资信息文件) 
	
	void ShowMainMenu();	// 显示主界面（提供各功能模块的入口） 
	
	void Read_File(string szFileName);	// 从工资信息文件中读入职工的工资信息数据
	void Write_File(string szFileName);	// 将职工的工资信息数据保存到工资信息数据文件里
	
public: // 各功能模块的实现函数 
	int Quit();		// 退出程序 
	void Caculate();// 计算模块(计算每个职工的应发工资、税款、实发工资)
	void Append();	// 增加模块	
	void Display();	// 浏览模块	
	void Modify();	// 修改模块	
	int Query();	// 查询模块
	void Delete();	// 删除模块
	void Sort();	// 排序模块(按实发工资进行降序排列)
	
protected:
	vector<CWorker> s;	// 存放职工的工资信息数据
	string m_szFileName;// 职工工资信息文件名（读和写文件的目标文件） 
};

// 构造函数(需传入工资信息文件名) 
CManager::CManager(string szFileName)
{
	m_szFileName = szFileName;
	Read_File(szFileName);	// 从工资信息文件中读入职工的工资信息数据 
}

// 析构函数(将s写入工资信息文件) 
CManager::~CManager()
{
	// 退出系统前，先保存好数据
	Write_File(m_szFileName);
}

// 功能模块函数的定义  ---------------------------------------------------

// 从工资信息文件中读入职工的工资信息数据
void CManager::Read_File(string szFileName)
{
	// 打开文件读数据 
	//std::ifstream in("工资数据.txt");	// 注意: 如果不用全路径，则要求该文件和源程序文件在同一路径下
	std::ifstream in(szFileName.c_str());
	
 	if(!in)
 	{
 		cout<<"\n打开文件失败，请先检查该文件是否存在！\n即将退出系统\n"<<endl;
 		exit(0);
 	}
 	
 	s.clear();	// 清空向量 	
 	// 如果文件顺利打开，则开始一行行地读数据
 	// 每行数据依次是职工的工号、姓名、基本工资、奖金、扣款、应发工资、税款、实发工资
 	// 例如某行数据为:     1	张三	600	85	80	0	0	0
	while(!in.eof())
	{
		CWorker a;
		if(in>>a.gh>>a.name>>a.jbgz>>a.jj>>a.kk>>a.yfgz>>a.sk>>a.sfgz)// 如读入成功(true)，则添加到向量容器中 
			s.push_back(a);
		else
		{
			in.clear();	// 如果状态为无效时，则使其恢复为有效状态 ，并停止读文件 
			break;
		}
	}
	in.close();
}

// 将职工的工资信息数据保存到工资信息数据文件里
void CManager::Write_File(string szFileName)
{
	int i=0, N=s.size();
	// 打开文件写数据 
	//ofstream out("工资数据.txt");	// 在源程序文件的同一路径下写入职工工资信息数据
	ofstream out(szFileName.c_str());	// 在源程序文件的同一路径下写入职工工资信息数据
 	if(!out)
 	{
 		cout<<"\n打开文件失败，请先检查该文件是否存在！\n即将退出系统\n"<<endl;
 		exit(0);
 	}
 	
 	// 如果文件顺利打开，则开始一行行地写数据
 	// 每行数据依次是职工的工号、姓名、基本工资、奖金、扣款、应发工资、税款、实发工资
 	// 例如某行数据为:     1	张三	600	85	80	0	0	0
 	for(i=0; i<N; i++)
 	{
 		out<<s[i].gh<<"\t"<<s[i].name<<"\t"<<s[i].jbgz<<"\t"<<s[i].jj<<"\t"<<s[i].kk<<"\t"<<s[i].yfgz<<"\t"<<s[i].sk<<"\t"<<s[i].sfgz<<endl;
 	}
	out.close();
}

// 退出程序 
int CManager::Quit()
{
	char c;
	cout<<("您真的要退出本系统吗?(Y/N) [ ]\b\b");
	cin>>c;
	if(c=='Y'||c=='y')
	{
		cout<<"\n谢谢惠顾，欢迎再来!  :) \n"<<endl;
		system("pause");
		return 0;
	}
	else
	{
		cout<<"感谢您的大力支持!\n"<<endl;
		return -1;
	}
}

// 计算模块(计算每个职工的应发工资、税款、实发工资)
void CManager::Caculate()
{
	int i=0, N=s.size();
	// 计算每个职工的应发工资、税款、实发工资 
	for(i=0; i<N; i++)
	{
		// 计算应发工资 
		s[i].yfgz = s[i].jbgz + s[i].jj - s[i].kk;
		
		// 计算应扣的税款 
		if(s[i].yfgz<2000.0f)
			s[i].sk = 0.0f;
		else if(s[i].yfgz<8000.0f)
			s[i].sk = 0.05f*(s[i].yfgz-2000.0f);
		else
			s[i].sk = 300.0f+0.1f*(s[i].yfgz-8000.0f);
		
		// 计算实发工资
		s[i].sfgz = s[i].yfgz - s[i].sk;
	}
}

// 增加模块
void CManager::Append()
{
	int n, i;
	cout<<"请输入需增加的职工数: ";
	cin>>n;
	
	cout<<"请输入需增加的每位职工工资的详细信息:\n"<<endl;
	for(i=0; i<n; i++)
	{
		cout<<"\n第"<<(i+1)<<"位职工的工资信息 --------------"<<endl;
		CWorker a;
		cout<<"\t工号: ";
		cin>>a.gh;		
		cout<<"\t姓名: ";
		cin>>a.name;		
		cout<<"\t基本工资: ";
		cin>>a.jbgz;		
		cout<<"\t奖金: ";
		cin>>a.jj;		
		cout<<"\t扣款: ";
		cin>>a.kk;
		s.push_back(a);
	}

	// 计算职工的应发工资、税款、实发工资
	Caculate();
} 

// 浏览模块 
void CManager::Display()
{
	int i=0, N=s.size();
	system("cls");	// 清屏
	cout<<"工号\t姓名\t基本\t奖金\t扣款\t应发\t税款\t实发"<<endl; 
	for(i=0; i<N; i++)
 	{
 		cout<<s[i].gh<<"\t"<<s[i].name<<"\t"<<s[i].jbgz<<"\t"<<s[i].jj<<"\t"<<s[i].kk<<"\t"<<s[i].yfgz<<"\t"<<s[i].sk<<"\t"<<s[i].sfgz<<endl;
	 	if(i%10==9)	// 分屏显示 
	 	{
	 		cout<<"\n按任意键继续浏览\n";
	 		system("pause");
	 	}
 	}
}

// 修改模块
void CManager::Modify()
{
	int j = -1, number=0, option=0;
	char c;

	// 在修改之前，进行职工查询
	j = Query();
	if(j>=0)
	{// 针对查找到的职工，对其工资信息进行修改 
		option = 0;
		while(!option)
		{
			cout<<"\n可修改该职工的如下项的信息:\n";
			cout<<"\n\t***     1: 姓名             2: 工号\n";
			cout<<"\n\t***     3: 基本工资         4: 奖金\n";
			cout<<"\n\t***     5: 扣款\n";
			cout<<"\n\t------------------------------------------------------------------\n";
	
			while(!option)
			{
				cout<<"\n\t请选择功能序号: [ ]\b\b";
				cin>>option;
				
				if(option==1)	// 修改姓名 
				{
					cout<<"\n姓名改为: ";
					cin>>s[j].name;
				}
				else if(option==2)	// 修改工号 
				{
					cout<<"\n工号改为: ";
					cin>>s[j].gh;
				}
				else if(option==3)	// 修改基本工资
				{
					cout<<"\n基本工资改为: ";
					cin>>s[j].jbgz;
				} 
				else if(option==4)	// 修改奖金
				{
					cout<<"\n奖金改为: ";
					cin>>s[j].jj;
				} 
				else if(option==5)	// 修改扣款
				{
					cout<<"\n扣款改为: ";
					cin>>s[j].kk;
				} 
				else
				{
					cout<<"\n 您输入了错误的序号，请重新输入!\n";
					option = 0;
					system("pause");
				}
			}
			
			// 修改完后，重新计算应发工资、税款和实发工资 
			Caculate();
			
			// 是否继续修改该职工的工资信息
			cout<<"是否继续修改该职工的工资信息?(Y/N) [ ]\b\b";
			cin>>c;
			if(c=='Y'||c=='y')
			{
				option = 0;
			}
		}	
	}
} 

// 查询模块
int CManager::Query()
{
	int i=0, j=-1, number=0, option=0, N=s.size();
	string name;
	
	// 先显示所有职工工资信息 
	Display();

	// 再通过按姓名或者工号，查找到要修改的职工
	cout<<"\n\n";
	cout<<"\n\t请按以下方式查询职工的工资信息\n";
	cout<<"\n\t***     1: 姓名\n";
	cout<<"\n\t***     2: 工号\n";
	cout<<"\n\t------------------------------------------------------------------\n";
	while(!option)
	{
		cout<<"\n\t请选择功能序号: [ ]\b\b";
		cin>>option;
		
		if(option==1)	// 按姓名查询 
		{
			cout<<"\n请输入姓名: ";
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
		else if(option==2)	// 按工号查询 
		{
			cout<<"\n请输入工号: ";
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
			cout<<"\n 您输入了错误的序号，请重新输入!\n";
			option = 0;
			system("pause");
		}
	}
	
	if(j<0)
	{
		cout<<"查无此人!\n";
		system("pause");
	}
	else
	{
		// 在修改前，查看该职工的工资信息 
		cout<<"该职工的工资信息如下:\n";
		cout<<"工号    姓名      基本工资  奖金      扣款      应发工资  税款      实发工资\n";
		cout<<s[j].gh<<"\t"<<s[j].name<<"\t"<<s[j].jbgz<<"\t"<<s[j].jj<<"\t"<<s[j].kk<<"\t"<<s[j].yfgz<<"\t"<<s[j].sk<<"\t"<<s[j].sfgz<<endl;
	}
	return j;
}

// 删除模块
void CManager::Delete()
{
	int i, j = -1;

	// 在删除前，进行职工查询
	j = Query();
	if(j>=0)
	{// // 针对查找到的职工，进行删除
		char c;
		cout<<"\n您确认要删除该职工的工资信息吗?(Y/N) [ ]\b\b";
		cin>>c;
		if(c=='Y'||c=='y')
		{
			s.erase(s.begin()+j);
		}
	}
}

// 排序模块(按实发工资进行降序排列)
void CManager::Sort()
{
	int i, j, N=s.size();
	CWorker t;
	for(i=0; i<N-1; i++)	// 冒泡法降序排序 
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

// 主界面 
void CManager::ShowMainMenu()
{
	int option=-1;	// 选项

	do 
	{
		 
		system("cls");	// 清屏
		system("color 3f");	// 设置屏幕的前景（字）和背景的颜色

		// 主界面
		cout<<"\n\t******************************************************************\n";
		cout<<"\n\t*********************    职工工资信息系统    *********************\n";
		cout<<"\n\t***     1: 浏览                                    2: 计算     ***\n";
		cout<<"\n\t***     3: 增加                                    4: 修改     ***\n";
		cout<<"\n\t***     5: 删除                                    6: 查询     ***\n";
		cout<<"\n\t***     7: 排序                                    8: 退出     ***\n";
		cout<<"\n\t------------------------------------------------------------------\n";
		cout<<"\n\t请选择功能序号(1-8): [ ]\b\b";
		cin>>option;

		switch(option)
		{
		case 1:	// 浏览模块 
			Display();
			break;
		case 2:	// 计算模块
			Caculate();
			break;
		case 3:	// 增加模块
			Append();
			break;
		case 4:	// 修改模块
			Modify();
			break;
		case 5:	// 删除模块
			Delete();
			break;
		case 6:	// 查询模块
			Query();
			break;
		case 7:	// 排序模块
			Sort();
			break;
		case 8:	// 退出程序 
			option = Quit();	// 0: 确实退出 
			break;
		default:
			cout<<"\n 您输入了错误的序号，请重新输入!";
			option = -1;
			break;
		}
		
		if(option)	// 如果不是退出，则返回到主界面 
		{
			cout<<"\n请按任意键返回主菜单界面!\n";
			system("pause"); // 等待按任意键
		}
		
	} while (option);
}

// 主函数 
int main()
{
	// 定义一个工资信息管理对象 
	CManager oMan("工资数据.txt");	
	// 剩下的事情全交给oMan对象去做
	oMan.ShowMainMenu();

	return 0;
}
