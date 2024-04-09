#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
using namespace std;
int w,  h;
vector<vector<char>> arr;
queue<int> ans;
queue<pair<pair<int, int>,int>> sang;
queue<pair<pair<int, int>,int>> fire;
int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
void f()
{
    int current_time = 0;
    while (!sang.empty())
    {
        pair<int, int> pos = sang.front().first;
        int time = sang.front().second;
        if (arr[pos.first][pos.second] == '*')
        {
            sang.pop();
            continue;
        }
        if (time <= current_time)
        {
            sang.pop();
            for (int k = 0; k < 4; k++)
            {
                int i = pos.first+dir1[k];
                int j = pos.second+dir2[k];
                if (0 <= i && i < h && 0 <= j && j < w)
                {
                    if (arr[i][j] == '.')
                    {
                        arr[i][j] = '@';
                        sang.push(make_pair(make_pair(i, j), time+1));
                    }
                }
                else
                {
                    ans.push(time + 1);
                    return;
                }
            }
        }
        else
        {
            while (!fire.empty())
            {
                pair<int, int> pos = fire.front().first;
                int time = fire.front().second;
                if (time > current_time)break;
                fire.pop();
                for (int k = 0; k < 4; k++)
                {
                    int i = pos.first+dir1[k];
                    int j = pos.second+dir2[k];
                    if (0 <= i && i < h && 0 <= j && j < w)
                    {
                        if (arr[i][j] == '.' || arr[i][j] == '@')
                        {
                            arr[i][j] = '*';
                            fire.push(make_pair(make_pair(i, j), time + 1));
                        }
                    }
                }
                
            }
            current_time++;

        }
    }
    ans.push(0);
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> w >> h;
        arr.clear();
        while (!sang.empty())sang.pop();
        while (!fire.empty())fire.pop();
        arr.resize(h, vector<char>(w));
        for(int i=0;i<h;i++)
            for (int j = 0; j < w; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == '@')
                    sang.push(make_pair(make_pair(i, j), 0));
                if (arr[i][j] == '*')
                    fire.push(make_pair(make_pair(i, j), 0));
            }
        f();
    }
    while (!ans.empty())
    {
        int temp = ans.front();
        ans.pop();
        if (temp)cout << temp << "\n";
        else cout << "IMPOSSIBLE\n";

    }

}
