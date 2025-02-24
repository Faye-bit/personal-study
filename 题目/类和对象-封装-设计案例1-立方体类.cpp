#include<iostream>
using namespace std;

class Cube
{
private:
	int m_l;
	int m_w;
	int m_h;

public:
	void Setcube(int l, int w, int h)
    {
        m_l=l;
        m_w=w;
        m_h=h;
    }

    int Getl()
    {
        return m_l;
    }

    int Getw()
    {
        return m_w;
    }

    int Geth()
    {
        return m_h;
    }

    int Getarea()
    {
        return 2*m_l*m_w+2*m_l*m_h+2*m_w*m_h;
    }

    int Getvolume()
    {
        return m_l*m_w*m_h;
    }

    bool isSame2(Cube c2)
    {
        if(m_h==c2.Geth() && m_l==c2.Getl() && m_w==c2.Getw())
        return true;
        else
        return false;
    }    
};

bool isSame1(Cube &c1,Cube &c2)
{
    if(c1.Getl()==c2.Getl() && c1.Getw()==c2.Getw() && c1.Geth()==c2.Geth())
    return true;
    else
    return false;
}

int main()
{
    Cube Cube1;
    Cube Cube2;
    int l1,w1,h1;
    int l2,w2,h2;
    cin>>l1>>w1>>h1;
    Cube1.Setcube(l1,w1,h1);
    cin>>l2>>w2>>h2;
    Cube2.Setcube(l2,w2,h2);

    cout<<Cube1.Getarea()<<" "<<Cube1.Getvolume()<<endl;
    cout<<Cube2.Getarea()<<" "<<Cube2.Getvolume()<<endl;

    if(isSame1(Cube1,Cube2))cout<<"Same"<<endl;
    else cout<<"Not same"<<endl;

    if(Cube1.isSame2(Cube2))cout<<"Same"<<endl;
    else cout<<"Not same"<<endl;

    system("pause");
    return 0;
}