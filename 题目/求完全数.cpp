#include<iostream>
using namespace std;

int main()
{
    for(int i=6;i<1000;i++)
    {
        int a=0;
        int ans=0;
        int arr[1000];

        for(int j=1;j<i;j++)
        {
            if(i%j==0)
            {
                ans+=j;
                arr[a]=j;
                a++;
            }
        }

        if(ans==i)
        {
            cout<<i<<"=";
            for(int i=0;i<a-1;i++)
            {
                cout<<arr[i];
                cout<<"+";
            }
            cout<<arr[a-1];
            cout<<endl;
        }
    }

    system("pause");
    return 0;
}