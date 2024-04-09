#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,h,t;
    cin >> n>>h>>t;
    int cnt=0;
    priority_queue<int,vector<int>> q;
    int temp;
    for(int i=0;i<n;i++)
        {cin>>temp;q.push(temp);}
    while(cnt<t)
    {
        if(q.top()<h)
            break;
        temp = q.top();q.pop();
        temp/=2;
        if(!temp)temp++;
        q.push(temp);
        cnt++;
    }
    if(q.top()<h )
        cout<<"YES\n"<<cnt;
    else cout <<"NO\n"<<q.top();

}
