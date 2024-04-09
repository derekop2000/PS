#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
using namespace std;

int n;
vector<vector<int>> arr;
vector<vector<int>> visit;
int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
void bfs()
{
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ii = now.first + dir1[i];
            int jj = now.second + dir2[i];
            if (0 <= ii && ii < n && 0 <= jj && jj < n)
            {
                if (arr[ii][jj] == 1 && visit[now.first][now.second] < visit[ii][jj])
                {
                    visit[ii][jj] = visit[now.first][now.second];
                    q.push(make_pair(ii, jj));
                }
                else if (arr[ii][jj] == 0 && visit[now.first][now.second] + 1 < visit[ii][jj])
                {
                    visit[ii][jj] = visit[now.first][now.second] + 1;
                    q.push(make_pair(ii, jj));
                }
            }
        }
    }
}
int main()
{
    cin >> n;
    arr.resize(n, vector<int>(n));
    visit.resize(n, vector<int>(n, 2147483647));
    for(int i=0;i<n;i++)
        for (int j = 0; j < n; j++)
        {
            char temp;
            cin >> temp;
            arr[i][j] = temp - '0';
        }
    visit[0][0] = 0;
    bfs();
    cout << visit[n - 1][n - 1];
}
