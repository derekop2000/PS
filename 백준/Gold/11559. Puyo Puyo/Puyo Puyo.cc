#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;

int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};

vector<vector<char>> arr;
vector<vector<bool>> visit;
queue<pair<int,int>> _q;
int ans = 0;
int combo;
void dfs(int i, int j)
{
	for (int q = 0; q < 4; q++)
	{
		int ii = i + dir1[q];
		int jj = j + dir2[q];
		if (0 <= ii && ii < 12 && 0 <= jj && jj < 6&&!visit[ii][jj] && arr[i][j] == arr[ii][jj])
		{
			_q.push(make_pair(ii,jj));
			visit[ii][jj] = true;
			combo++;
			dfs(ii, jj);
		}
	}
	
}
int main()
{
	arr.resize(12, vector<char>(6));
	
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> arr[i][j];

	while (true)
	{
		bool different = false;
		visit.clear();
		visit.resize(12, vector<bool>(6, false));
		for (int i = 11; i >= 0; i--)
			for (int j = 0; j < 6; j++)
			{
				if (!visit[i][j] && arr[i][j] != '.')
				{
					visit[i][j] = true;
					combo = 1;
					while (!_q.empty())_q.pop();
					_q.push(make_pair(i, j));
					dfs(i, j);
					if (combo >= 4)
					{
						different = true;
						while (!_q.empty())
						{
							arr[_q.front().first][_q.front().second] = '.';
							_q.pop();
						}
					}
				}
			}

		for (int i = 0; i < 6; i++)
		{
			int height = 11;
			for (int j = 11; j >= 0; j--)
			{
				if (arr[j][i] != '.')
				{
					arr[height][i] = arr[j][i];
					if(height != j)arr[j][i] = '.';
					height--;
				}
			}
		}

		if (different)ans++;
		else break;

	}

	cout << ans;
}