#include<iostream>
using namespace std;
#define n 99999

template<class T>
void bubble(T array[n],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(array[j]<array[j+1])
            {
                T temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

int main()
{
    int a1[10]={4,5,7,1,2,8,9,3,6,10};
    double a2[5]={2.98,3.66,7.53,1.44,4.65};


    bubble(a1,10);
    bubble(a2,5);

    for(int i=0;i<10;i++)
    {
        cout<<a1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<a2[i]<<" ";
    }

    return 0;

}