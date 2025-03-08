#include<iostream>
using namespace std;
#define PI 3.1415926

class Shape
{
public:
    virtual double getarea()=0;
};

ostream& operator<<(ostream &out,Shape& s)
{
    cout<<s.getarea()<<endl;
    return out;
}

class Circle: public Shape
{
protected:
    double radius;

public:
    double getarea() override
    {
        return PI*radius*radius;
    }

    Circle(const Circle& c)
    {
        this->radius=c.radius;
    }

    Circle(double t_radius)
    {
        this->radius=t_radius;
    }

    ~Circle()
    {
        radius=0;
    }
};

class Rectangle:public Shape
{
protected:
    double length;
    double width;

public:
    double getarea() override
    {
        return length*width;
    }

    Rectangle(const Rectangle& r)
    {
        this->length=r.length;
        this->width=r.width;
    }

    Rectangle(double t_length,double t_width)
    {
        this->length=t_length;
        this->width=t_width;
    }

    ~Rectangle()
    {
        length=0;
        width=0;
    }
};

void  printArea(Shape&  oShape)
    { 
            cout<<oShape; 
    }
    
    int  main() 
    {
        Circle  oC(5.0); 
        Rectangle  oR(3.0,  4.0);
        printArea(oC); 
        printArea(oR); 
    
        return  0; 
    }