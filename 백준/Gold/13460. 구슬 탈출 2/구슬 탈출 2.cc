#include<iostream>
#include<vector>
using namespace std;
int dir1[] = { -1,0,1,0 };
int dir2[] = { 0,1,0,-1 };
vector<vector<char>> arr;
int n, m;
pair<int, int> initPos[2];
int ans = 11;
pair<int,int> move(int direct, pair<int, int> move, pair<int, int> NoneMove)
{
	pair<int, int> temp = move;
	while (1)
	{
		move.first += dir1[direct];
		move.second += dir2[direct];
		
		if (move.first==NoneMove.first && move.second == NoneMove.second)
		{
			move.first -= dir1[direct];
			move.second -= dir2[direct];
			break;
		}
		else
		{
			if (0 < move.first && move.first < n - 1 && 0 < move.second && move.second < m - 1 && arr[move.first][move.second] != '#')
			{
				if (arr[move.first][move.second] == '.')
					continue;
				else
				{
					return make_pair(-1, -1);
				}
			}
			else
			{
				move.first -= dir1[direct];
				move.second -= dir2[direct];
				break;
			}
		}
	}
	return move;

}

void dfs(int cnt, pair<int, int>red, pair<int, int>blue)
{
	if (cnt > 9) return;
	pair<int, int> temp_red;
	pair<int, int> temp_blue;
	if (red.first < blue.first)
	{
		temp_red = move(0, red, blue);
		temp_blue = move(0, blue, temp_red);
	}
	else
	{
		temp_blue = move(0, blue, red);
		temp_red = move(0, red, temp_blue);
	}
	if (temp_red.first == -1&&temp_blue.first!=-1) { if(ans > cnt+1)ans = cnt + 1; return; }
	else if (red !=temp_red || blue != temp_blue) { dfs(cnt + 1, temp_red, temp_blue); }

	if (red.second > blue.second)
	{
		temp_red = move(1, red, blue);
		temp_blue = move(1, blue, temp_red);
	}
	else
	{
		temp_blue = move(1, blue, red);
		temp_red = move(1, red, temp_blue);
	}
	if (temp_blue.first == -1);
	else if (temp_red.first == -1) { if (ans > cnt + 1)ans = cnt + 1; return; }
	else if (red != temp_red || blue != temp_blue) { dfs(cnt + 1, temp_red, temp_blue); }
	else;

	if (red.first > blue.first)
	{
		temp_red = move(2, red, blue);
		temp_blue = move(2, blue, temp_red);
	}
	else
	{
		temp_blue = move(2, blue, red);
		temp_red = move(2, red, temp_blue);
	}
	if (temp_blue.first == -1);
	else if (temp_red.first == -1) { if (ans > cnt + 1)ans = cnt + 1; return; }
	else if (red != temp_red || blue != temp_blue) { dfs(cnt + 1, temp_red, temp_blue); }
	else;


	if (red.second < blue.second)
	{
		temp_red = move(3, red, blue);
		temp_blue = move(3, blue, temp_red);
	}
	else
	{
		temp_blue = move(3, blue, red);
		temp_red = move(3, red, temp_blue);
	}
	if (temp_blue.first == -1);
	else if (temp_red.first == -1) { if (ans > cnt + 1)ans = cnt + 1; return; }
	else if (red != temp_red || blue != temp_blue) { dfs(cnt + 1, temp_red, temp_blue); }
	else;
}
int main()
{
	cin >> n >> m;
	arr.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
			{
				initPos[0].first = i; initPos[0].second = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B')
			{
				initPos[1].first = i; initPos[1].second = j;
				arr[i][j] = '.';
			}
		}
	dfs(0, initPos[0],initPos[1]);
	if (ans > 10) cout << "-1";
	else cout << ans;
}
