#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dir1[4] = {-1,0,1,0};
int dir2[4] = {0,1,0,-1};
int n, m;
vector<vector<int>> arr;
vector<vector<bool>> used;
int ans = 0;
void dfs(int y, int x,int sum)
{
	if (x == m)
	{
		x=0;
		y++;
	}
	if (y == n)
	{
		ans = max(ans, sum);
		return;
	}

	if (!used[y][x])
	{
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> first_pos;
			pair<int, int> second_pos;
			first_pos.first = y + dir1[i];
			first_pos.second = x + dir2[i];
			second_pos.first = y + dir1[(i + 1) % 4];
			second_pos.second = x + dir2[(i + 1) % 4];
			if (0 <= first_pos.first && first_pos.first < n && 0 <= first_pos.second && first_pos.second < m && 0 <= second_pos.first && second_pos.first < n && 0 <= second_pos.second && second_pos.second < m)
			{
				if (!used[first_pos.first][first_pos.second] && !used[second_pos.first][second_pos.second])
				{
					used[first_pos.first][first_pos.second] = true;
					used[second_pos.first][second_pos.second] = true;
					used[y][x] = true;
					dfs(y, x + 1, (sum + arr[first_pos.first][first_pos.second] + arr[second_pos.first][second_pos.second] + arr[y][x] * 2));
					used[first_pos.first][first_pos.second] = false;
					used[second_pos.first][second_pos.second] = false;
					used[y][x] = false;
				}
			}
		}
	}
	dfs(y, x + 1, sum);
}
int main()
{
	cin >> n >> m;
	arr.resize(n, vector<int>(m));
	used.resize(n, vector<bool>(m,false));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	dfs(0, 0,0);
	cout << ans;
}