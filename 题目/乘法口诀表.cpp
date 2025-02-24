#include<iostream>
using namespace std;

int main()
{
	for (int a = 1; a < 10; a++)
	{
		for (int b = 1; b <= a; b++)
		{
			int c = 0;
			c = a * b;
			cout << a <<"¡Á"<< b << "="<<c<<'\t';
		}
		cout << endl;
	}
	return 0;
}