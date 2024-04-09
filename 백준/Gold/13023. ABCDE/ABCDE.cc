#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
using namespace std;

int n, m;
bool ans = false;
vector<vector<int>> arr;
vector<bool> visit;
void dfs(int _friend, int _depth)
{
    if (_depth == 5)ans = true;
    if (ans)return;
    for (int i = 0; i < arr[_friend].size(); i++)
    {
        int temp = arr[_friend][i];
        if (!visit[temp])
        {
            visit[temp] = true;
            dfs(temp, _depth + 1);
            visit[temp] = false;
        } 
    }
}
int main()
{
    cin >> n >> m;
    arr.resize(n, vector<int>());
    visit.resize(n, false);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        visit[i] = true;
        dfs(i, 1);
        visit[i] = false;
    }
    if (ans)cout << "1";
    else cout << "0";
      
}
