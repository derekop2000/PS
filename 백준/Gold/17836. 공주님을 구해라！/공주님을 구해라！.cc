#include <iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int n,m,t;
vector<vector<int>> arr;
vector<vector<int>> visit;
int dir1[] = {-1,0,1,0 };
int dir2[] = {0,1,0,-1};
void bfs()
{
    queue<tuple<int, int>> q;
    q.push({ 0,0});
    visit[0][0] = 0;
    while (!q.empty())
    {
        auto pos = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ii = get<0>(pos)+dir1[i];
            int jj = get<1>(pos)+dir2[i];
            if (0 <= ii && ii < n && 0 <= jj && jj < m)
            {
                if ((arr[ii][jj] == 0|| arr[ii][jj] == 2)&& visit[get<0>(pos)][get<1>(pos)]+1 <visit[ii][jj])
                {
                    visit[ii][jj] = visit[get<0>(pos)][get<1>(pos)] + 1;
                    if (visit[ii][jj] > t)continue;
                    q.push({ ii,jj });
                }
                
                /*else if (arr[ii][jj] == 2 && visit[get<0>(pos)][get<1>(pos)] + 1 < visit[ii][jj])
                {
                    visit[ii][jj] = visit[get<0>(pos)][get<1>(pos)] + 1;
                    int temp = visit[ii][jj] + abs(ii - n + 1) + abs(jj - m + 1);
                    if (temp > t)continue;
                    visit[n - 1][m - 1] = temp;
                }*/
            }
        }
    }
}
int main()
{
    cin >> n >> m >> t;
    arr.resize(n, vector<int>(m));
    visit.resize(n, vector<int>(m, 2147483647));
    pair<int, int> sword;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                sword.first = i;
                sword.second = j;
            }
        }
    bfs();
    int ans = visit[n - 1][m - 1];
    if (visit[sword.first][sword.second] < 2147483647)
    {
        ans = min(ans, (visit[sword.first][sword.second]+ abs(sword.first - n + 1) + abs(sword.second - m + 1)) );
    }

    if (ans >t)
        cout << "Fail";
    else cout << ans;
}