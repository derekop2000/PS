#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dir1[4] = {-1,0,1,0};
int dir2[4] = {0,1,0,-1};

int n, m;
vector<vector<int>> map;
vector<vector<pair<int,int>>> cnts;
void bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int yy = y + dir1[i];
			int xx = x + dir2[i];
			if (0 <= yy && yy < n && 0 <= xx && xx < m)
			{
				bool push_ = false;
				if (map[yy][xx] == 0)
				{
					if (cnts[y][x].first>-1)
					{
						if (cnts[yy][xx].first == -1)
						{
							cnts[yy][xx].first = cnts[y][x].first + 1;
							push_ = true;
						}
						else
						{
							if(cnts[yy][xx].first > cnts[y][x].first + 1)
							{
								cnts[yy][xx].first = cnts[y][x].first + 1;
								push_ = true;
							}
						}
					}
					if (cnts[y][x].second > -1)
					{
						if (cnts[yy][xx].second == -1)
						{
							cnts[yy][xx].second = cnts[y][x].second + 1;
							push_ = true;
						}
						else
						{
							if(cnts[yy][xx].second > cnts[y][x].second + 1)
							{
								cnts[yy][xx].second = cnts[y][x].second + 1;
								push_ = true;
							}
						}
					}
				}
				else
				{
					if (cnts[y][x].first > -1)
					{
						if (cnts[yy][xx].second == -1)
						{
							cnts[yy][xx].second = cnts[y][x].first + 1;
							push_ = true;
						}
						else
						{
							if(cnts[yy][xx].second > cnts[y][x].first + 1)
							{
								cnts[yy][xx].second = cnts[y][x].first + 1;
								push_ = true;
							}
						}
						
					}
				}
				if (push_)
				{
					q.push(make_pair(yy, xx));
				}
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	map.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char temp;
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}
	cnts.resize(n, vector<pair<int, int>>(m, make_pair(-1,-1)));
	cnts[0][0].first = 1;
	cnts[0][0].second = 1;
	bfs();
	int ans = cnts[n - 1][m - 1].second;
	if (cnts[n - 1][m - 1].first != -1 && cnts[n - 1][m - 1].first < ans)
		ans = cnts[n - 1][m - 1].first;
	cout << ans;
}