#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int a,b;
    cin >> a >>b;
    vector<int> v;
    v.resize(a);
    for(int i=0;i<a;i++)
        cin >> v[i];
    sort(v.begin(),v.end() );
    for(int i=0;i<a;i++)
    {
        if(b>=v[i])
            b++;
    }
    cout<< b;
}

