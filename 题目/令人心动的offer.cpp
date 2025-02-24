#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int t = 0;
int m = 0;
int n = 0;
int answer = 0;

int a = 0;



int main()
{
	cin >> t;
	
		for (int i = 0; i < t; i++)
		{
			cin >> n >> m;
			int b = min(m, n);

			if (m < n)
			{
				a = n - m;
			}
			else if (m >= n)
			{
				a = m - n;
			}

			if (m == n == 1)
			{
				answer = 0;
				cout << answer << endl;
				cout << a <<"  " << b << endl;
			}

			else if (m > 2 && n == 1)
			{
				answer = -1;
				cout << answer << endl;
				cout << a << "  " << b << endl;
			}
			else if (m == 1&& n > 2)
			{
				answer = -1;
				cout << answer << endl;
				cout << a << "  " << b << endl;
			}
			else if (m == n)
			{
				answer = m=n-2;
				cout << answer << endl;
				cout << a << "  " << b << endl;
			}
			else if (a % 2 == 0)
			{
				answer = b*2+2*a-2;
				cout << answer << endl;
				cout << a << "  " << b << endl;
			}
			else
			{
				answer = b*2+(a/2)*4-1;
				cout << answer << endl;
				cout << a << "  " << b << endl;
			}
		}




	system("pause");
	return 0;
}