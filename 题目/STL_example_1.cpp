#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class participant 
{
private:
    deque<int> score;

public:

    string name;
    int a_score;

    participant(string t_name,int t_score[10])
    {
        name=t_name;

        for(int i=0;i<10;i++)
        {
            score.push_back(t_score[i]);
        }

        a_score=average();
    }
    
    int average()
    {
        sort(score.begin(),score.end());

        score.pop_back();
        score.pop_front();

        int sum=0;
        for(deque<int>::iterator it=score.begin();it<score.end();it++)
        {
            sum += *it;
        }

        sum/=score.size();
        return sum;
    }
};

void p_sort(vector<participant> &p)
{
    for(int i=0;i<p.size()-1;i++)
    {
        for(int j=0;j<p.size()-i-1;j++)
        {
            if(p[j].a_score<p[j+1].a_score)
            {
                swap(p[j],p[j+1]);
            }
        }
    }
}

void test()
{
    vector<participant> p;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        string name;
        cin>>name;
        int t_score[10];
        for(int j=0;j<10;j++)
        {
            cin>>t_score[j];
        }

        p.push_back(participant(name,t_score));
    }

    p_sort(p);

    for(int i=0;i<p.size();i++)
    {
        cout<<p[i].name<<" "<<p[i].a_score<<endl;
    }

}

int main()
{
    test();

    return 0;
}
