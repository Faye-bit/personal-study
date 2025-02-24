#include<iostream>
using  namespace  std;
const  double  PI  =  3.1415926;    //  π

class Sphere
{
public:
    Sphere(double R)
    {
        m_R=R;
    }

    Sphere(const Sphere &obj)
    {
        m_R= obj.m_R;
    }

    ~Sphere()
    {

    }

    double getArea()
    {
        return 4*PI*m_R*m_R;
    }

    double getVolume()
    {
        return (4.0/3)*PI*m_R*m_R*m_R;
    }

protected:
    double m_R;
};


int  main()
{
    double  R;
    cin>>R;
    Sphere  obj1(R);  //  半径为R的球体
    cout<<obj1.getArea()<<endl;
    cout<<obj1.getVolume()<<endl;
    
    Sphere  obj2(obj1);  //  另一个与obj1同等大小的球体
    cout<<obj2.getArea()<<endl;
    cout<<obj2.getVolume()<<endl;
    
    return  0;
}