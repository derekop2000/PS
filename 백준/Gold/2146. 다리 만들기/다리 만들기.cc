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

int n;
vector<vector<int>> arr;
vector<vector<bool>> visit;
int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
int ans;
int ans_cnt;
void f(int r,int c)
{
	queue<tuple<int, int, int>> q;
	q.push({ r,c,0 });
	int temp = n * 2;
	int my_color = arr[r][c];
	while (q.empty() == false)
	{
		auto now = q.front(); q.pop();
		if (get<2>(now) > ans)return;
		if (arr[get<0>(now)][get<1>(now)]&& get<2>(now)>1)
		{
			if (get<2>(now) == ans)
				ans_cnt++;
			else
			{
				ans = get<2>(now);
				ans_cnt = 1;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int rr = get<0>(now) + dir1[i];
			int cc = get<1>(now) + dir2[i];
			
			if (!(0 <= rr && rr < n && 0 <= cc && cc < n))continue;
			if (visit[rr][cc] == true || arr[rr][cc]==my_color)continue;
			
			visit[rr][cc] = true;
			q.push({ rr,cc,get<2>(now) + 1 });
		}
	}
}
void f2(int r,int c,int z)
{
	queue<pair<int,int>> q;
	q.push({ r,c });
	while (q.empty() == false)
	{
		auto now = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int rr = now.first + dir1[i];
			int cc = now.second + dir2[i];

			if (!(0 <= rr && rr < n && 0 <= cc && cc < n))continue;
			if (arr[rr][cc] == 1)
			{
				q.push({ rr,cc });
				arr[rr][cc] = z;
			}
		}
	}
}
int main()
{
	cin >> n;
	ans = n * 2;
	arr.resize(n, vector<int>(n));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	int cnt = 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] == 1)
			{
				arr[i][j] = cnt;
				f2(i, j, cnt++);
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j])
			{
				visit.clear();
				visit.resize(n, vector<bool>(n));
				f(i, j);
			}
	cout << ans-1;
}