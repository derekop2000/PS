#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
using namespace std;

int r, c;
vector<vector<char>> arr;
int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
int ans = -1;
void bfs()
{
	queue<pair<int, int>> q;
	int t = 1;
	while (true)
	{
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] == 'S')
					q.push({ i,j });
			}
		if (q.size() == 0)return;
		bool is_change = false;
		while (!q.empty())
		{
			auto temp = q.front(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ii = temp.first + dir1[i];
				int jj = temp.second + dir2[i];
				if (0 <= ii && ii < r && 0 <= jj && jj < c)
				{
					if (arr[ii][jj] == '.')
					{
						arr[ii][jj] = 'S';
						is_change = true;
					}
					if (arr[ii][jj] == 'D')
					{
						ans = t;
						return;
					}
				}

			}
		}
		if (is_change == false)return;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] == '*')
					q.push({ i,j });
			}
		while (!q.empty())
		{
			auto temp = q.front(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ii = temp.first + dir1[i];
				int jj = temp.second + dir2[i];
				if (0 <= ii && ii < r && 0 <= jj && jj < c && (arr[ii][jj] == '.' || arr[ii][jj]=='S'))
					arr[ii][jj] = '*';
			}
		}
		t++;
	}

}
int main()
{
	cin >> r >> c;
	arr.resize(r, vector<char>(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
		}
	bfs();
	if (ans == -1)cout << "KAKTUS";
	else cout << ans;
}