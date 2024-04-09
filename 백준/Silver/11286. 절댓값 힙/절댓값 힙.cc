#include <iostream>
#include <queue>
using namespace std;
struct kkk
{
    bool operator()(int &a,int &b)
    {
        if(abs(a)!=abs(b))
            return abs(a)>abs(b);
        return a>b;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    priority_queue<int,vector<int>,kkk> q;
    int n;
    cin >>n;
    int temp;
    for(int i=0;i<n;i++)
        {
            cin >> temp;
            if(temp)
            q.push(temp);
            else
            {
                if(q.empty())
                    cout <<"0\n";
                else
                {
                    cout <<q.top()<<'\n';
                    q.pop();
                }
            }
        }

}
