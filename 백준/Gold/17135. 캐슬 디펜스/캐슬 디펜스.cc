#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include <iomanip>
#include<climits>

using namespace std;

int n, m, d;
vector<pair<int, int>> arr;
queue<pair<int, int>> temp;
vector<vector<bool>> simulate;
vector<vector<bool>> visit;
int temp_ans;
int ans = 0;
int enemy_cnt = 0;
int dir1[] = {0,-1,0};
int dir2[] = {-1,0,1};
void bfs(int r, int c)
{
	int i = r;
	int j = c;
	queue<pair<int, int>> q;
	q.push({ i,j });
	while (!q.empty())
	{
		i = q.front().first;
		j = q.front().second;
		q.pop();
		visit[i][j] = true;
		if (simulate[i][j])
		{
			//simulate[i][j] = false;
			temp.push({ i,j });
			//temp_ans++;
			return;
		}
		for (int t = 0; t < 3; t++)
		{
			int ii = i + dir1[t];
			int jj = j + dir2[t];
			int distance = abs(r - ii) + abs(c - jj);
			if (distance > d-1)
				break;
			if (0 <= ii && ii < n && 0 <= jj && jj < m&&!visit[ii][jj])
			{
				q.push({ ii,jj });
			}
		}
	}
}
void f(int p1, int p2, int p3)
{
	// init
	int cnt = enemy_cnt;
	temp_ans = 0;
	int arrows[3] = { p1,p2,p3 };
	simulate.resize(n, vector<bool>(m,false));
	visit.resize(n, vector<bool>(m, false));
	for (int i = 0; i < arr.size(); i++)
	{
		simulate[arr[i].first][arr[i].second] = true;
	}
	//

	while (true)
	{

		// shoot
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < n; j++)
				for (int k = 0; k < m; k++)
					visit[j][k] = false;
			bfs(n - 1, arrows[i]);
		}
		while (!temp.empty())
		{
			int i = temp.front().first;
			int j = temp.front().second;
			temp.pop();
			if (simulate[i][j])
			{
				temp_ans++;
				simulate[i][j] = false;
			}
		}
		//


		// move down
		for (int j = 0; j < m; j++)
		{
			if (simulate[n - 1][j])
			{
				cnt--;
				simulate[n - 1][j] = false;
			}
		}
		for (int i = n-2; i >=0; i--)
			for (int j = 0; j < m; j++)
			{
				if (simulate[i][j])
				{
					simulate[i][j] = false;
					simulate[i + 1][j] = true;
				}
			}
		
		if ((cnt - temp_ans) == 0)
			break;
		//
	}
	ans = max(temp_ans, ans);
}
int main()
{
	cin >> n >> m >> d;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 1)
			{
				arr.push_back({ i,j });
				enemy_cnt++;
			}
		}
	for(int i=0;i<m;i++)
		for(int j=i+1;j<m;j++)
			for (int k = j + 1; k<m; k++)
			{
				f(i, j, k);
			}
	cout << ans;
}