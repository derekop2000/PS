#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct info
{
    string info1;
    int info2,info3,info4;
};
bool good(info &a,info &b)
{
    if(a.info4!=b.info4)
        return a.info4<b.info4;
    if(a.info3 != b.info3)
        return a.info3 < b.info3;
    return a.info2 < b.info2;
}
int main()
{
    int n;
    cin >> n;
    vector<info> v;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i].info1;
        cin >> v[i].info2;
        cin >> v[i].info3;
        cin >> v[i].info4;
    }
    sort(v.begin(),v.end(),good);
    cout << v.back().info1<<'\n'<<v.front().info1;

}
