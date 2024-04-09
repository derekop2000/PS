#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a,b,safe=0;
int main()
{
    cin >> a >>b;
    int ans = 0;
    vector<int> v;
    v.resize(a);
    for(int i=0;i<a;i++)
        cin >> v[i];
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++)
    {
        if(v[i]<=safe)
            continue;
        ans++;
        safe = v[i]+b-1;
    }
    cout << ans;
}
