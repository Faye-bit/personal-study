#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int ar[10001]={0};
    int br[10001]={0};
    int a,b;

    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>ar[i];
    }
    for(int i=0;i<a-1;i++)
    {
        for(int j=0;j<a-i-1;j++)
        {
            if(ar[j]>ar[j+1])
            {
                int temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
    cin>>b;
    for(int j=0;j<b;j++)
    {
        cin>>br[j];
    }

    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(ar[i]==br[j])
            {
                i++;
                j=0;
            }
        }
        cout<<ar[i]<<" ";
    }

    system("pause");
    return 0;
}


/*int main()
{
    int a;
    cin>>a;
    vector<int> v1;
    for(int i=0;i<a;i++)
    {
        int temp;
        cin>>temp;
        v1.push_back(temp);
    }

    //for(size_t i=0;i<v1.size();i++)
    //{
    //    cout<<v1[i]<<" ";
    //}

    vector<int> v2;
    int b;
    cin>>b;
    for(int j=0;j<b;j++)
    {
        int temp;
        cin>>temp;
        v1.push_back(temp);
    }

    for(size_t i=0;i<v1.size();i++)
    {
        for(size_t j=0;j<v2.size();j++)
        {
            if(v1[i]==v2[j])
            {
                i++;
                j=0;
            }
        }
        cout<<v1[i]<<" ";
    }

    system("pause");
    return 0;
}*/