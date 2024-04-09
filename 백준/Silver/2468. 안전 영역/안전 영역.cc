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

vector<vector<int>> arr;
vector<vector<bool>> visit;
int n;
int ans = 1;
int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
void dfs(int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		int ii = i + dir1[k];
		int jj = j + dir2[k];
		if (0 <= ii && ii < n && 0 <= jj && jj < n && !visit[ii][jj])
		{
			visit[ii][jj] = true;
			dfs(ii, jj);
		}
	}
}
void f(int level)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] < level)
				visit[i][j] = true;
			else visit[i][j] = false;
		}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] == false)
			{
				visit[i][j] = true;
				cnt++;
				dfs(i, j);
			}
		}
	ans = max(ans, cnt);
}

int main()
{
	cin >> n;

	arr.resize(n, vector<int>(n));
	visit.resize(n, vector<bool>(n,false));

	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	for (int i = 1; i < 100; i++)
	{
		f(i);
	}
	cout << ans;
}