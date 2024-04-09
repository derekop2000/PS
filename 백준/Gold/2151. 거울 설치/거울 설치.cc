#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};

int n;
pair<int, int> pos1;
pair<int, int> pos2;
vector<vector<vector<int>>> visit;
vector<vector<char>> arr;
struct info
{
	int x;
	int y;
	int dir;
};
void bfs()
{
	queue<info> q;
	for (int i = 0; i < 4; i++)
		q.push({ pos1.first,pos1.second,i });
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		q.pop();
		if (arr[x][y] == '.')
		{
			int xx = x + dir1[dir];
			int yy = y + dir2[dir];
			if (0 <= xx &&  xx < n && 0 <= yy && yy < n && arr[xx][yy] != '*' && visit[xx][yy][dir] > visit[x][y][dir])
			{
				visit[xx][yy][dir] = visit[x][y][dir];
				q.push({ xx,yy,dir });
			}
		}
		else if (arr[x][y] == '!')
		{
			for (int i = 0; i < 4; i++)
			{
				if ((dir + 2) % 4 == i)continue;
				int xx = x + dir1[i];
				int yy = y + dir2[i];
				if (0 <= xx && xx < n && 0 <= yy && yy < n && arr[xx][yy] != '*')
				{
					if (dir == i && visit[xx][yy][i] > visit[x][y][i])
					{
						visit[xx][yy][i] = visit[x][y][i];
						q.push({ xx,yy,i });
					}
					else
					{
						if (visit[xx][yy][i] > visit[x][y][dir] + 1)
						{
							visit[xx][yy][i] = visit[x][y][dir] + 1;
							q.push({ xx,yy,i });
						}
					}
				}
			}
		}
		
	}
}
int main()
{
	cin >> n;
	pos1.first = -1;
	visit.resize(n, vector<vector<int>>(n,vector<int>(4,2500)));
	arr.resize(n, vector<char>(n));
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '#' && pos1.first == -1)
			{
				pos1.first = i;
				pos1.second = j;
			}
			else if (arr[i][j] == '#')
			{
				pos2.first = i;
				pos2.second = j;
			}
		}
	for(int i=0;i<4;i++)
		visit[pos1.first][pos1.second][i] = 0;
	arr[pos1.first][pos1.second] = '.';
	bfs();
	int ans = 2500;
	for (int i = 0; i < 4; i++)
	{
		if (visit[pos2.first][pos2.second][i] < ans)ans = visit[pos2.first][pos2.second][i];
	}
	cout << ans;
}

