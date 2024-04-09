#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;

int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
int n, m;
vector<vector<int>> arr;
vector<vector<int>> visit;

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty())
	{
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		int around_zero = 0;
		for (int i = 0; i < 4; i++)
		{
			int yyy = yy + dir1[i];
			int xxx = xx + dir2[i];
			if (0 <= yyy && yyy < n && 0 <= xxx && xxx < m)
			{
				if (arr[yyy][xxx] == 0)around_zero++;
				if (arr[yyy][xxx] > 0 && visit[yyy][xxx]==-1 )
				{
					q.push(make_pair(yyy, xxx));
					visit[yyy][xxx] = 0;
				}
			}
		}
		visit[yy][xx] = around_zero;
	}
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j] > 0)
			{
				arr[i][j] = max(0, arr[i][j] - visit[i][j]);
			}
		}
}
int main()
{
	cin >> n >> m;
	arr.resize(n, vector<int>(m));
	visit.resize(n, vector<int>(m));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}

	int ans = 0;
	while (true)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] != 0)
					visit[i][j] = -1;
				else visit[i][j] = 0;
			}
		int component = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (visit[i][j] == -1)
				{
					component++;
					bfs(i, j);
				}
			}
		if (component == 1)
		{
			ans++;
		}
		else
		{
			if (component == 0)
			{
				cout << 0;
				return 0;
			}
			else
			{
				cout << ans;
				return 0;
			}
			
		}
	}
}