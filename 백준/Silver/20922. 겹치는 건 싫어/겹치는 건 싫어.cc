#include<iostream>
#include<vector>
using namespace std;
int index[100001];
int main()
{
    int n,k;
    cin >>n>>k;
    int ans=0;
    int now=0;
    int left=0, right=-1;
    vector<int> v;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }
    while(1)
    {
        right++;
        if(right==n)break;
        index[v[right]]++;
        if(index[v[right]]>k)
        {
            int cnt=0;
            while(1)
            {
                index[v[left]]--;
                left++;
                cnt++;
                if( v[left-1]==v[right] )
                {
                    break;
                }
            }
            now-=cnt-1;
        }
        else
        {
            now++;
            if(ans<now)
                ans=now;
        }
    }
    cout << ans;
}
