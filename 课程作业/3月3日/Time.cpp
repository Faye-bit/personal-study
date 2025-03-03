#include<iostream>
#include<iomanip>
using namespace std;

class time
{
public:
    friend ostream& operator<<(ostream& out,const class time& t);
    friend istream& operator>>(istream& in,time& t);

    int h,m,s;

    time& operator++()
    {
        s++;
        return *this;
    }

    time operator++(int)
    {
        time temp(*this);

        ++this->s;
        return temp;
    }

    time& operator--()
    {
        s--;
        return *this;
    }

    time operator--(int)
    {
        time temp(*this);

        s--;
        return temp;
    }

    time& operator+=(const time t)
    {
        this->s+=t.s;
        if(this->s>=60)
        {
            this->s-=60;
            this->m++;
        }

        this->m+=t.m;
        if(this->m>=60)
        {
            this->m-=60;
            this->h++;
        }

        this->h+=t.h;
        if(this->h>=24)
        {
            this->h-=24;
        }

        return *this;
    }

    time& operator-=(const time t)
    {
        if(this->s<t.s)
        {
            this->m--;
            this->s+=60;
        }
        this->s-=t.s;

        if(this->m<t.m)
        {
            this->h--;
            this->m+=60;
        }
        this->m-=t.m;

        if(this->h<t.h)
        {
            this->h+=24;
        }
        this->h-=t.h;

        return *this;
    }
};

ostream& operator<<(ostream& out,const class time& t)
{
    cout<<setfill('0')<<setw(2)<<t.h<<":"<<setfill('0')<<setw(2)<<t.m<<":"<<setfill('0')<<setw(2)<<t.s<<endl;
    return out;
}

istream& operator>>(istream& in,class time& t)
{
    in>>t.h>>t.m>>t.s;
    return in;
}

int main()
{
    class time t1{},t2{};
    cin>>t1>>t2;
    cout<<endl;

    t1+=(t2++);
    cout<<t1;

    t1-=t2;
    cout<<t1;

    ++t2;
    cout<<t2;

    t2+=(t1--);
    cout<<t2;

    --t1;
    cout<<t1;

    t2-=t1;
    cout<<t2;

    system("pause");
    return 0;
}