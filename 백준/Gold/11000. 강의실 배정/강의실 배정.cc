#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

    vector<pair<long long int,long long int>> v;
    int n;
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++)
        {
            cin >> v[i].first;
            cin >> v[i].second;
        }
    sort(v.begin(),v.end());
    priority_queue<long long int,vector<long long int>,greater<long long int> >q;
    q.push(v[0].second);
    for(int i=1;i<n;i++)
    {
        if(q.top() <= v[i].first)
        {
            q.pop();q.push(v[i].second);
        }
        else q.push(v[i].second);
    }
    cout <<q.size();
}
