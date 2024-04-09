#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    int a,b;
    while(n--)
    {
        cin >> a >> b;
        v.push_back(make_pair(b,a));
    }
    int time =0;
    int cnt=0;
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++)
    {
        if(v[i].second >= time)
        {
            cnt++;
            time = v[i].first;
        }
    }
    cout << cnt;
}
