#include<iostream>
using namespace std;

int main()
{
    int year,n;
    string month[12]={"Jan.","Feb.","Mar.","Apr.","May.","Jun.","Jul.","Aug.","Set.","Oct.","Nov.","Dec."};
    int month1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int month2[12]={31,29,31,30,31,30,31,31,30,31,30,31};

    cin>>year;
    cin>>n;

    if((year%4==0&&year%100!=0)||year%400==0)
    {
        int i=0;
        while(n>month2[i])
        {
            n-=month2[i];
            i++;
        }
        cout<<month[i]<<n<<" "<<year<<endl;
    }
    else
    {
        int i=0;
        while(n>month1[i])
        {
            n-=month1[i];
            i++;
        }
        cout<<month[i]<<n<<" "<<year<<endl;
    }

    system("pause");
    return 0;
}