#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<memory>
using namespace std;
int directCol[] = {-1,0,1,0};
int directRow[] = {0,1,0,-1};
vector<vector<char>> arr;
queue<pair<int,int>> man,fire;

int n,m;

int f()
{
    int cnt=0;
    bool isOK=false;
    while(!isOK)
    {
        cnt++;
        int ms=man.size(),fs=fire.size();
        if(ms==0){return 0;}
        while(fs)
        {
            pair<int,int> temp = fire.front();fire.pop();fs--;
            for(int i=0;i<4;i++)
            {
                int col = temp.first+directCol[i];
                int row = temp.second+directRow[i];
                if(0<=col&&col<n&&0<=row&&row<m&& (arr[col][row]=='J'||arr[col][row]=='.' ))
                   {
                       arr[col][row] = 'F';
                       fire.push(make_pair(col,row) );
                   }
            }
        }
        while(ms)
        {
            pair<int,int> temp = man.front();man.pop();ms--;
            for(int i=0;i<4;i++)
            {
                int col = temp.first+directCol[i];
                int row = temp.second+directRow[i];
                if(0<=col&&col<n&&0<=row&&row<m)
                {
                   if(arr[col][row]=='.')
                   {
                        arr[col][row] = 'J';
                        man.push(make_pair(col,row) );
                   }

                }
                else
                {
                    isOK=true;
                }
            }
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >>m;
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        arr[i].resize(m);
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]=='J')
                man.push(make_pair(i,j));
            else if(arr[i][j]=='F')
                fire.push(make_pair(i,j));
        }
    }
    int ans = f();
    if(ans)
        cout << ans;
    else cout << "IMPOSSIBLE";

}
