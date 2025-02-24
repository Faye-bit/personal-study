#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    int n=0;

    for(a=0;a<=10;a++)
    {
        for(b=0;b<=20;b++)
        {
            c=100-10*a-5*b;
            if(c>=0)
            {
                n++;
                cout<<"10元："<<a<<" "<<"5元："<<b<<"  "<<"1元："<<c<<endl;
            }
        }
    }

   /*int a,b; 
   int n=0;

   for(a=0;a<=10;a++)
   {
    for(b=0;b<=20;b++)
    {
        int c=100-10*a-5*b;
        if(c>=0)
        {
            n++;
            cout<<"10元："<<a<<" "<<"5元："<<b<<"  "<<"1元："<<c<<endl;
        }
    }
   }*/

    cout<<"一共"<<n<<"种方法。"<<endl;

    system("pause");
    return 0;
}