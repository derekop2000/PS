#include<iostream>
#include<vector>
#include<memory>
#include<math.h>
#include<algorithm>
#include<deque>
#include<queue>
using namespace std;
int dir1[] = { -1,0,0,1 };
int dir2[] = { 0,-1,1,0 };
int n, size_ = 2, ans = 0, expp = 0;
pair<int, int> pos;
int arr[20][20];
bool visit[20][20];
deque<int> fish;

int cnt = 1;

void visit_init()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			visit[i][j] = false;
		}
}
bool find_(int i, int j)
{
	queue<pair<pair<int, int>, int>> temp_pos;
	temp_pos.push(make_pair(make_pair(i, j), 0));
	pair<int, int> des;
	des = make_pair(n, n);
	bool canEat = false;
	int min_dis = n * n;
	while (!temp_pos.empty())
	{
		int x = temp_pos.front().first.first;
		int y = temp_pos.front().first.second;
		int dis = temp_pos.front().second;

		if (dis > min_dis)break;
		if (arr[x][y] && arr[x][y] < size_)
		{
			canEat = true;
			min_dis = dis;
			if (x < des.first)
			{
				des.first = x; des.second = y;
			}
			else if (x == des.first && y < des.second)
			{
				des.first = x; des.second = y;
			}
			else;
		}
		temp_pos.pop();
		visit[x][y] = true;
		for (int q = 0; q < 4; q++)
		{
			int xx = x + dir1[q];
			int yy = y + dir2[q];
			if (0 <= xx && xx < n && 0 <= yy && yy < n && !visit[xx][yy] && arr[xx][yy] <= size_&&dis<min_dis)
			{
				temp_pos.push(make_pair(make_pair(xx, yy), dis + 1));
			}
		}

	}
	if (!canEat)return false;
	arr[des.first][des.second] = 0;
	ans += min_dis;
	pos.first = des.first;
	pos.second = des.second;
	return true;
}
void f()
{
	while (!fish.empty() && fish.front() < size_)
	{
		visit_init();
		if (!find_(pos.first, pos.second))return;
		fish.pop_front();
		expp++;
		if (expp >= size_)
		{
			size_++;
			expp = 0;
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				pos.first = i;
				pos.second = j;
				arr[i][j] = 0;
			}
			else if (1 <= arr[i][j] && arr[i][j] <= 6)
			{
				fish.push_back(arr[i][j]);
			}
		}
	}
	sort(fish.begin(), fish.end());
	f();
	cout << ans;
}
