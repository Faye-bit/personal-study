#include<iostream>
#include<string>
using namespace std;

struct hero 
{
    string name;
    int power;
    string gender;
};

int main()
{
    struct hero H[5];
    for(int i=0;i<5;i++)
    {
       cin>>H[i].name>>H[i].power>>H[i].gender;
    }

    /*for(int i=0;i<5;i++)
    {
        cout<<H[i].name<<H[i].power<<H[i].gender;
        cout<<endl;
    }*/

   for(int i=0;i<4;i++)
    {for(int j=0;j<4-i;j++)
        {if(H[i].power<H[i].power)
            {
                struct hero temp =H[j];
                H[j]=H[j+1];
                H[j+1]=temp;
            }

        }
    }
    cout<<endl;
    
    for(int i=0;i<5;i++)
    {
        cout<<H[i].name<<H[i].gender<<H[i].power;
        cout<<endl;
    }


    system("pause");
    return 0;
}