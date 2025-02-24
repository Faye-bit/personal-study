#include<iostream>
using namespace std;




void bubblesort(int arr[], int len)
{

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

			}
		}

	}
}

int main()
{
	int arr[10];

	cout << "????????????????"<< endl;

	for (int j = 0; j < 10; j++)
	{
		cin >> arr[j];
	}

	cout << "???????????????";

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;

	int len = 0;
	len = sizeof(arr) / sizeof(arr[0]);

	/*cout << len;*/

	bubblesort(arr,len);

	cout << "??????????????";

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;




	system("pause");
	return 0;
}


