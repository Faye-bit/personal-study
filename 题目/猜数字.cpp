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
	cout << "��ӭ�����������Ϸ����������£�" << endl;
	cout << "ϵͳ���������һ��1~100֮�����������������С��ϵͳ����ʾ���²�Ľ���ȴ𰸴��С��ֱ�����Ŷ�Ϊֹ" << endl;
	cout << "��ע����ֻ��10�λ���" << endl;
	cout << "������Ϸ��ʼ��" << endl;
	
	cout << "���������²������";
	cin >> x;
	n--;
	
	while (n > 0)
	{
		
		if (x < answer)
		{
			cout << "С��һ�㣬����û��ϵ��СС��Ҳ�ܿɰ�" << endl;
			cout << "����һ�Σ����������²������";
			cin >> x;
			n--;
		}
		else if (x > answer)
		{
			cout << "��΢����һ�㣬�������ԣ��𰸺ܽӽ���" << endl;
			cout << "����һ�Σ����������²������";
			cin >> x;
			n--;
		}
		else
		{
			cout << "��ϲ��������ˣ�" << endl;
			break;
		}


	}

	switch (n)
	{
	case 0:
		{
		cout << "���ź������㣬��ʧ���ˣ�����ȥ��ԭ�񣡣���" << endl;
		break;
		}
	default:
		{
		cout << "̫���ˣ�������ȥ������㣡����" << endl;
		break;
		}
	}

	system("pause");
	return 0;
	
}