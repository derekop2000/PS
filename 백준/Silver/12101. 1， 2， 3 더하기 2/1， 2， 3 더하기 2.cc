#include <iostream>
#include<string.h>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
    int n,k;
    cin >>n>>k;
    vector<vector<string>>v(11);
    v[0].push_back("");
    v[1].push_back("1");
    v[2].push_back("11");
    v[2].push_back("2");
    for(int i=3;i<=n;i++)
    {
        for(int q=0;q<v[i-3].size();q++)
            v[i].push_back(v[i-3][q]+"3");
        for(int q=0;q<v[i-2].size();q++)
            v[i].push_back(v[i-2][q]+"2");
        for(int q=0;q<v[i-1].size();q++)
            v[i].push_back(v[i-1][q]+"1");
    }
    sort(v[n].begin(),v[n].end());
    if(k>v[n].size())
    {
        cout<<"-1";return 0;
    }
    string s = v[n][k-1];
    cout<<s[0];
    for(int i=1;i<s.size();i++)
        {
            cout<<"+";cout<<s[i];
        }

}
