#include<iostream>
using namespace std;

int main()
{
    int arr[100001]={0};
    int a=0;
    int m,n;
    cin>>n>>m;
    int i=0;
    int j=0;

    while(1)
    {
        if(arr[i]==0)
        {
            a++;
            if(a==m)//退出游戏
            {
                arr[i]=1;
                cout<<"drop out of the game: "<<i<<endl;
                a=0;
                j++;
            }
            
            if(j==n-1)//判断游戏是否结束
            {
                for(int k;k<n;k++)
                {
                    if(arr[k]==0)
                    {
                        cout<<"The last one is : "<<k<<endl;
                    }
                }
                break;
            }
        }
        i++;
            if(i==n)//从头开始
            {
                i=0;
            }
    }

system("pause");
return 0;
}
