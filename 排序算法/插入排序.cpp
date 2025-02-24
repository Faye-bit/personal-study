#include<iostream>
using namespace std;

//使用插入排序把一份数据从小到大排序。

int main()
{
    const int MAXN=10001;
    int n=0;
    int arr[MAXN];
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //算法主体
    for(int i=1;i<n;i++)
    {
       int key=arr[i];
       for(int j=i-1;j>=0;j--)
       {
        if(key<arr[j])
        {
            arr[j+1]=arr[j];
        }
        else
        {
            break;
        }
        arr[j]=key;
       }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    system("pause");
    return 0;
}