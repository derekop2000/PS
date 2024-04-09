#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<memory>
using namespace std;
int n,k;
vector<int> v;
int main()
{
    std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n>>k;
    v.resize(n);
    int sum=0;
    for(int i=0;i<n;i++)
        {
            cin >> v[i];
            sum+=v[i];
        }
    if(sum<k)
    {
        cout<<"0";return 0;
    }
    int ans =n;
    int cnt=v[0];
    int length=1;
    int left=0,right=0;
    while(1)
    {
        if(cnt<k)
        {
            right++;
            if(right>=n)
                break;
            length++;
            cnt+=v[right];
        }
        else
        {
            if(length<ans)
                ans=length;
            cnt-=v[left];
            left++;
            if(left>right)
            {
                ans=1;
                break;
            }
            length--;
        }

    }
    cout<<ans;
}
