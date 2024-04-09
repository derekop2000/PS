#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<memory>
using namespace std;
vector<long long int> v;
int n;
bool findd(long long int x,int i,int j)
{
    int a=0,b=n-1;
    int mid;
    while(a<=b)
    {
        mid = (a+b)/2;
        if(v[mid]==x&&mid!=i&&mid!=j)
            return true;
        
        else if(v[mid]>x)
        {
            b=mid-1;
        }
        else
        {
            a=mid+1;
        }
    }
    return false;
}
int main()
{
    int ans=0;
    cin >>n;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    sort(v.begin(),v.end() );

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==i)continue;
            long long int x = v[i]-v[j];

            if(findd(x,i,j)){ans++;break;}
        }
    }
    cout << ans;
}
