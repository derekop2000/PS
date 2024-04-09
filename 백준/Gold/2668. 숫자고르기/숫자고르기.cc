#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<memory>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<int> check(n+1);
    for(int i=1;i<=n;i++)
    {
        check[i]=0;
        cin >> v[i];
    }
    for(int i=1;i<=n;i++)
        check[v[i]]++;
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(check[i]==0)q.push(i);
    while(!q.empty())
    {
        int temp = q.front();q.pop();
        check[ v[temp] ]--;
        if(check[ v[temp] ]==0)q.push(v[temp]);
    }
    int cnt=0;
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(check[i])
        {
            cnt++;
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end());
    cout << cnt<<'\n';
    for(int i=0;i<cnt;i++)
        cout<<ans[i]<<'\n';
}

