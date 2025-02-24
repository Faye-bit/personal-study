#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const float PI=3.14;

int main()
{
    vector<int>v;
    int num=0,t=0;
    int* p=nullptr;

    cout<<v.capacity()<<endl;
    
    for(int i=0;i<100000;i++)
    {
        ///v.push_back(i);

        if(t!=v.capacity())
        {
            //p=&v[0];
            cout<<v.capacity()<<"  ";
            t=v.capacity();
            num++;
        }

        v.push_back(i);
    }

    cout<<endl<<"num="<<num;

    // int* p=new int[10];
    // cout<<p[0]<<endl;

    return 0;
}

/*int main()
{
    char a[100]="Together For A Shared Future";
    int i=0,in_word=0,word_num=0;

    for(i=0;i<100;i++)
    {
        if(a[i]==32)
        {
            in_word=0;
        }
        else if(in_word==0)
        {
            word_num++;
            in_word=1;
        }
    }

    cout<<"Total num ="<<word_num<<endl;

    system("pause");
    return 0;
}*/


// class A
// {
// public:
//     A()
//     {
//         cout<<"A";
//     }
//     A(const A &a)
//     {
//         cout<<"B";
//     }
//     ~A()
//     {
//         cout<<"C";
//     }
//     void fun(A a)
//     {
//         cout<<"D";
//     }

// };

// int main()
// {
//    A a,b(a);
//    a.fun(b);
//    cout<<"E";
//    return 0;
// }
/*
int x=10,y=20;
void fun(int x,int &y)
{
    x+=y;
    y+=x;
}


int main()
{
    int x=5,y=10;
    fun(x,y);
    fun(y,x);
    cout<<x<<" "<<y<<endl;

    system("pause");
    return 0;
}
*/

// class Circle
// {
// public:
//     float m_r;

//     Circle (float r)
//     {
//         m_r=r;
//     }

//     float getArea()
//     {
//         return PI*m_r*m_r;
//     }

//     float getGirth()
//     {
//         return 2*PI*m_r;
//     }
// };


// int main()
// {
//      float  r;
//         cout  <<  "请输入圆的半径：";
//         cin  >>  r;                                                                          //从键盘接受半径的值
//         Circle  c1(r);                                                        //将值赋值给半径并调用定义好的函数
//         cout<<"圆的面积为："<<c1.getArea()<<endl;
//         Circle  c2(r);
//         cout<<"圆的周长为："<<c2.getGirth()<<endl;

//     return 0;
// }

/*int main()
{
    int a,b,c;

    

    system("pause");
    return 0;
}*/

//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//int main()

    //double e;
    //cin>>e;

    // double n = 2;
    // int i = 1;
    // double m = (2.00 * i / (2 * i - 1) * 2 * i / (2 * i + 1));

    // n *= (2.00 * i / (2 * i - 1) * 2 * i / (2 * i + 1));


    // cout << fixed << setprecision(7) << n << "  ";
    // cout << i << endl;

    /*int a=10;
    int b=100;

    int* p=&a;
    cout<<*p<<endl;

    *p=b;
    cout<<*p<<endl;
    cout<<a<<endl;

    system("pause");
    return 0;
}*/
/*#include<iostream>
using namespace std;

int main()
{
    int y, m, d;
    cin >> y >> m >> d;

    int n = 0;
    for (int i = 1900; i < y; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
        {
            n += 366;
        }
        else
        {
            n += 365;
        }

    }

    int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    for (int i = 0; i < m - 1; i++)
    {
        n += month[i];
    }
    if (((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) && m > 2)
    {
        n++;
    }

    n += d;

    int x = n % 7;
    if (x == 0)
    {
        x = 7;
    }
    cout << x << endl;

    system("pause");
    return 0;
}*/

