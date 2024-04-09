#include<iostream>
#include<vector>
#include<queue>
#include<memory>
using namespace std;
int n,w,l,temp;
queue<int> q;
vector<pair<int,int>> seconds;
int f()
{
    int cnt=1;
    for(;;cnt++)
    {

        if(seconds[cnt].first<w && seconds[cnt].second+q.front() <= l)
        {
            for(int i=cnt;i<cnt+w;i++)
            {
                seconds[i].first +=1;
                seconds[i].second += q.front();
            }
            q.pop();
            if(q.empty())
            {
                cnt+=w;
                break;
            }
        }
    }
    return cnt;
}
int main()
{
    cin >> n >>w >>l;
    for(int i=0;i<n;i++)
        {cin >> temp;q.push(temp);}
    seconds.resize(n*w+2);
    seconds.push_back(make_pair(0,0));
    cout << f();
}
