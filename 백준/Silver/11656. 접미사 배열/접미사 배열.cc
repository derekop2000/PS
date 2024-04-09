#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    string s;
    vector<string> v;
    cin >> s;
    int temp = s.size();
    for(int i=0;i<temp;i++)
        v.push_back(s.substr(i,temp));
    sort(v.begin(),v.end());
    for(int i=0;i<temp;i++)
        cout <<v[i]<<'\n';
}
