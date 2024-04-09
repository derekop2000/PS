#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string sum(string a,string b)
{
    string v;
    int temp,c=0;
    int a_index = a.size()-1;
    int b_index = b.size()-1;
    while(a_index>-1&&b_index>-1)
    {
        temp = (a[a_index]-'0')+(b[b_index]-'0')+c;
        if(temp>9)
        {
            v.push_back(temp-10+'0');
            c=1;
        }
        else
        {
            v.push_back(temp+'0');
            c=0;
        }
        a_index--;
        b_index--;
    }
    while(a_index>-1)
    {
        temp = (a[a_index]-'0')+c;
        if(temp>9)
        {
            v.push_back(temp-10+'0');
            c=1;
        }
        else
        {
            v.push_back(temp+'0');
            c=0;
        }
        a_index--;
    }
    while(b_index>-1)
    {
        temp = (b[b_index]-'0')+c;
        if(temp>9)
        {
            v.push_back(temp-10+'0');
            c=1;
        }
        else
        {
            v.push_back(temp+'0');
            c=0;
        }
        b_index--;
    }
    if(c)v.push_back('1');
    reverse(v.begin(),v.end());
    return v;
}
int main()
{
    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    int n;
    cin >>n;
    for(int i=2;i<=n;i++)
    {
        v.push_back( sum(v[i-2],v[i-1]) );
    }
    cout << v[n];
}
