#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
using namespace std;

int n;
vector<vector<int>> arr;

int ans_range = 100;
queue<int> ans_q;
void bfs(int start)
{
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    int cnt = n;
    vector<bool> visit(n);
    visit[start] = true;
    while (!q.empty())
    {
        int who = q.front().first;
        int range = q.front().second;
        q.pop();
        if (range > ans_range)return;
        cnt--;
        if (cnt == 0)
        {
            if (range < ans_range)
            {
                while (!ans_q.empty())
                {
                    ans_q.pop();
                }
                ans_q.push(start);
                ans_range = range;
            }
            else
            {
                ans_q.push(start);
            }
            return;
        }
        for (int i = 0; i < arr[who].size(); i++)
        {
            int who2 = arr[who][i];
            if (!visit[who2])
            {
                visit[who2] = true;
                q.push(make_pair(who2, range + 1));
            }
        }
    }
}
int main()
{
    cin >> n;
    arr.resize(n);
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == -1)break;
        a--; b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        bfs(i);
    }
    cout << ans_range <<" " << ans_q.size() << "\n";
    while (!ans_q.empty())
    {
        int temp = ans_q.front();
        ans_q.pop();
        cout << temp+1 << " ";
    }

}
