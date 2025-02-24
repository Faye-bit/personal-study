#include<iostream>
#include<string>
#include<vector>
using namespace std;

//
//string巩固练习
//

//字符串反转
string p_1(const string str)
{
    int n=str.size();
    string r_str;

    for(int i=1;i<=n;i++)
    {
        r_str.push_back(str[n-i]);
    }

    return r_str;
}

//统计一个字符串中每个字符的个数
void p_2(const string str)
{
    class my
    {
    public:
        char c;
        int t=1;

        my(){}

        my(char t_c):c(t_c){}

        void print()
        {
            cout<<c<<":"<<t<<endl;
        }
    };

    int n=str.size();
    vector<my> v;
    for(int i=0;i<n;i++)
    {
        int j=0;
        for(j=0;j<v.size();j++)
        {
            if(v[j].c==str[i])
            {
                v[j].t++;
                break;
            }
        }
        if(j==v.size())
        {
            v.push_back(my(str[i]));
        }
    }

    for(int i=0;i<v.size();i++)
    {
        v[i].print();
    }
} 

//判断子串
int p_3(const string str,const string s)
{   
    if(s.empty()) return -1;
    if(str.size()<s.size()) return -1;
    for(int i=0;i<=str.size()-s.size();i++)
    {
        bool found=true;
        for(int j=0;j<s.size();j++)
        {
            if(str[i+j]!=s[j])
            {
                found=false;
                break;
            }
        }
        if(found)
        {
            return i+1;
        }
    }
    return -1;
}
    // vector<int> v;
    // v.push_back(0);
    // for(int i=0;i<str.size();i++)
    // {
    //     int f=str.find(s.at(0),v.back());
    //     v.push_back(f);
    // }   


    // for(vector<int>::iterator it=v.begin();it<v.end();it++)
    // {
    //     for(int i=0;i<s.size();i++)
    //     {
    //         if(str[*it+i]==s[i])
    //         {
    //             continue;
    //         }
    //         v.erase(it);
    //     }
    // }


    // return ;

//反转句子



int main()
{
    string str1;
    cin>>str1;
    
    cout<<p_1(str1)<<endl;

    p_2(str1);
    cout<<endl;

    string s1;
    cin>>s1;
    cout<<p_3(str1,s1)<<endl;

    string s2;
    cin>>s2;
    cout<<p_3(str1,s2)<<endl;


    return 0;
}