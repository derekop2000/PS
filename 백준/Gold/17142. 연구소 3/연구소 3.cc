#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
int n, m,ans=99999999,goal;
bool haveRoot = false;
vector<vector<int>> arr;
vector<vector<int>> arr2;
vector<pair<int, int>> virus;
vector<int> selected;
queue<pair<pair<int, int>, int>>q;
void f2()
{
	int cnt = 0;
	int temp_ans= 99999999;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		arr2[x][y] = t;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dir1[i];
			int yy = y + dir2[i];
			if (0 <= xx && xx < n && 0 <= yy && yy < n && (arr2[xx][yy] == -1 || arr2[xx][yy] == 0) )
			{
				if (arr2[xx][yy] == -1)
				{
					cnt++;
				}
				temp_ans = t + 1;
				arr2[xx][yy] = t + 1;
				q.push(make_pair(make_pair(xx, yy), t + 1));
			}
			if (cnt == goal)break;
		}
	}
	if (cnt == goal&&temp_ans < ans)
	{
		haveRoot = true;
		ans = temp_ans;
	}
}
void f()
{
	while (!q.empty())
	{
		q.pop();
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr2[i][j] = -2; // -1 빈,  -2 벽
			if (arr[i][j] == 0)
				arr2[i][j] = -1;
			if (arr[i][j] == 2)
				arr2[i][j] = 0;
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		q.push(make_pair(make_pair(virus[selected[i]].first, virus[selected[i]].second), 0));
	}
	f2();
}
void select(int last)
{
	if (selected.size() == m)
	{
		f();
		return;
	}
	for (int i = last + 1; i<virus.size(); i++)
	{
		selected.push_back(i);
		select(i);
		selected.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	goal = n * n;
	arr.resize(n, vector<int>(n));
	arr2.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)virus.push_back(make_pair(i, j));
			if (arr[i][j] == 1)goal--;
		}
	goal -= virus.size();
	if (goal == 0)
	{cout << "0"; return 0;}
	select(-1);
	if (haveRoot)
		cout << ans;
	else cout << "-1";
}