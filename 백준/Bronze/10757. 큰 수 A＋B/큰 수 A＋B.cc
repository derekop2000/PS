#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string a,b;
    vector<int> v;
    cin >> a >>b;
    int c = 0;
    int temp;
    int a_index = a.size()-1;
    int b_index = b.size()-1;
    while(a_index>-1&&b_index>-1)
    {
        temp = (a[a_index]-'0')+(b[b_index]-'0')+c;
        if(temp>9)
        {
            v.push_back(temp-10);
            c=1;
        }
        else
        {
            v.push_back(temp);
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
            v.push_back(temp-10);
            c=1;
        }
        else
        {
            v.push_back(temp);
            c=0;
        }
        a_index--;
    }
    while(b_index>-1)
    {
        temp = (b[b_index]-'0')+c;
        if(temp>9)
        {
            v.push_back(temp-10);
            c=1;
        }
        else
        {
            v.push_back(temp);
            c=0;
        }
        b_index--;
    }
    if(c)v.push_back(1);
    for(int i=v.size()-1;i>-1;i--)
        cout << v[i];
}
