#include<iostream>
#include<time.h>
using namespace std;

int answer = 0;
int x = 0;
int n = 10;

int main()
{
	srand((unsigned)time(NULL));
	int answer = rand() % 100 + 1;
	cout << "欢迎游玩猜数字游戏，其规则如下：" << endl;
	cout << "系统将随机生成一个1~100之间的数，玩家来猜其大小，系统会提示您猜测的结果比答案大或小，直到您才对为止" << endl;
	cout << "请注意您只有10次机会" << endl;
	cout << "下面游戏开始！" << endl;
	
	cout << "请输入您猜测的数：";
	cin >> x;
	n--;
	
	while (n > 0)
	{
		
		if (x < answer)
		{
			cout << "小了一点，但是没关系，小小的也很可爱" << endl;
			cout << "再试一次，请输入您猜测的数：";
			cin >> x;
			n--;
		}
		else if (x > answer)
		{
			cout << "稍微大了一点，请再试试，答案很接近了" << endl;
			cout << "再试一次，请输入您猜测的数：";
			cin >> x;
			n--;
		}
		else
		{
			cout << "恭喜您，答对了！" << endl;
			break;
		}


	}

	switch (n)
	{
	case 0:
		{
		cout << "很遗憾，杂鱼，你失败了，罚你去玩原神！！！" << endl;
		break;
		}
	default:
		{
		cout << "太棒了，奖励你去玩绝区零！！！" << endl;
		break;
		}
	}

	system("pause");
	return 0;
	
}