#include<iostream>
using  namespace  std;
const  double  PI = 3.1415926;    //  ��

class Sphere
{
public:
    Sphere(double R)
    {
        m_R = R;
    }

    Sphere(const Sphere& obj)
    {
        m_R = obj.getR;
    }

    ~Sphere()
    {

    }

    double getR()
    {
        return m_R;
    }

    double getArea()
    {
        return 4 * PI * m_R * m_R;
    }

    double getVolume()
    {
        return (4 / 3) * PI * m_R * m_R * m_R;
    }

protected:
    double m_R;
};


int  main()
{
    double  R;
    cin >> R;
    Sphere  obj1(R);  //  �뾶ΪR������
    cout << obj1.getArea() << endl;
    cout << obj1.getVolume() << endl;

    Sphere  obj2(obj1);  //  ��һ����obj1ͬ�ȴ�С������
    cout << obj2.getArea() << endl;
    cout << obj2.getVolume() << endl;

    return  0;
}