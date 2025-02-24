#include<iostream>
using namespace std;

int main()
{
    int que[8]={0};
    int i=0;
    /*for(int i=0;i<8;i++)
    {
        cout<<que[i]<<" ";
        cout<<endl;
    }*/

   while(i>=0)
   {
        int k=0;
        while(k<i)
        {
            if(que[k]!=que[i]&&abs(que[k]-que[i])!=abs(k-i))
            {
                k++;
            }
            else
            {
                break;
            }
        }
        if(k<i)
        {
            que[i]++;
            if(que[i]==8)
            {
                que[i]=0;
                i--;
                if(i<0)
                {
                    break;
                }
                ++que[i];
            }
            continue;
        }
        else
        {
            i++;
            if(i<8)
            {
                continue;
            }
            else
            {
                break;
            }
        }
   }
    for(int i=0;i<8;i++)
    {
        cout<<que[i]<<" ";
        cout<<endl;
    }

    system("pause");
    return 0;
}