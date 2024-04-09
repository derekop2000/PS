#include <iostream>
#include<string.h>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,l,r;
int ans=0;
int main()
{
    cin >>n>>l>>r;
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int temp;
            cin >> temp;
            v[i].push_back(temp);
        }

    while(1)
    {

        bool isChange = false;

        vector<vector<bool>> visit(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                visit[i].push_back(false);
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(visit[i][j])continue;
                queue<pair<int,int>> q;
                queue<pair<int,int>> q2;
                q.push(make_pair(i,j));
                q2.push(make_pair(i,j));
                visit[i][j]=true;
                int sum=v[i][j];
                while(!q.empty())
                {

                    pair<int,int> temp = q.front();q.pop();

                    if(temp.first>0&&!visit[temp.first-1][temp.second]&& abs(v[temp.first-1][temp.second]-v[temp.first][temp.second]) >=l&&abs(v[temp.first-1][temp.second]-v[temp.first][temp.second])<=r)
                    {
                        q2.push(make_pair(temp.first-1,temp.second));
                        q.push(make_pair(temp.first-1,temp.second));
                        sum+=v[temp.first-1][temp.second];
                        visit[temp.first-1][temp.second]=true;
                    }
                    if(temp.second<n-1&&!visit[temp.first][temp.second+1]&& abs(v[temp.first][temp.second+1]-v[temp.first][temp.second]) >=l&&abs(v[temp.first][temp.second+1]-v[temp.first][temp.second])<=r)
                    {
                        q2.push(make_pair(temp.first,temp.second+1));
                        q.push(make_pair(temp.first,temp.second+1));
                        sum+=v[temp.first][temp.second+1];
                        visit[temp.first][temp.second+1]=true;
                    }
                    if(temp.first<n-1&&!visit[temp.first+1][temp.second]&& abs(v[temp.first+1][temp.second]-v[temp.first][temp.second]) >=l&&abs(v[temp.first+1][temp.second]-v[temp.first][temp.second])<=r)
                    {
                        q2.push(make_pair(temp.first+1,temp.second));
                        q.push(make_pair(temp.first+1,temp.second));
                        sum+=v[temp.first+1][temp.second];
                        visit[temp.first+1][temp.second]=true;
                    }
                    if(temp.second>0&&!visit[temp.first][temp.second-1]&& abs(v[temp.first][temp.second-1]-v[temp.first][temp.second]) >=l&&abs(v[temp.first][temp.second-1]-v[temp.first][temp.second])<=r)
                    {
                        q2.push(make_pair(temp.first,temp.second-1));
                        q.push(make_pair(temp.first,temp.second-1));
                        sum+=v[temp.first][temp.second-1];
                        visit[temp.first][temp.second-1]=true;
                    }
                }
                if(q2.size()>1)
                {
                    isChange=true;
                    //cout<<q2.size()<<"\n";
                    sum/=q2.size();
                    while(!q2.empty())
                    {
                        pair<int,int> temp = q2.front();q2.pop();
                        v[temp.first][temp.second] = sum;
                    }
                }
            }
        if(isChange)ans++;
        else break;


/*
        cout<<'\n';
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout <<v[i][j]<<' ';
            cout<<'\n';
        }
        cout <<'\n';*/
    }
    cout << ans;
}
