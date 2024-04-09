#include <iostream>
#include<string.h>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
bool f(int &a,int &b)
{
    if(a<b)return true;
    else return false;
}
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    while(n--)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),f);
    for(int i=0;i<v.size();i++)
    {
        cout << v[i]<<'\n';
    }
}
