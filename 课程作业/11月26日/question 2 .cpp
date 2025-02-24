#include<iostream>
using namespace std;

int main()
{
    int ar[10][10]={0};
    int m,n;
    cin>>m>>n;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>ar[i][j];
        }
    }

    cout<<n<<" "<<m<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            cout<<ar[j][i]<<" ";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}