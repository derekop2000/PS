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

int m, n, h;
vector<vector<vector<int>>> arr;
vector<vector<vector<bool>>> visit;
int cnt = 0;

int dir1[] = {1,-1,0,0,0,0};
int dir2[] = {0,0,-1,0,1,0};
int dir3[] = {0,0,0,1,0,-1};
int ans = 0;

queue<tuple<int, int, int>> _q;
void f()
{
	while (true)
	{
		/*queue<tuple<int, int, int>> q;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < m; k++)
				{
					if (arr[i][j][k] == 1)
					{
						q.push(make_tuple(i, j, k));
					}
				}*/
		
		/*while (!q.empty())
		{
			int temp1 = get<0>(q.front());
			int temp2 = get<1>(q.front());
			int temp3 = get<2>(q.front());
			q.pop();
			for (int i = 0; i < 6; i++)
			{
				int temp4 = temp1 + dir1[i];
				int temp5 = temp2 + dir2[i];
				int temp6 = temp3 + dir3[i];
				if (0 <= temp4 && temp4 < h && 0 <= temp5 && temp5 < n && 0 <= temp6 && temp6 < m)
				{
					if (arr[temp4][temp5][temp6] == 0)
					{
						arr[temp4][temp5][temp6] = 1;
						change = true;
						cnt--;
					}
				}
			}
		}*/
		int pre_size = _q.size();
		bool change = false;
		
		for (int i = 0; i<pre_size; i++)
		{
			int temp1 = get<0>(_q.front());
			int temp2 = get<1>(_q.front());
			int temp3 = get<2>(_q.front());
			_q.pop();
			for (int i = 0; i < 6; i++)
			{
				int temp4 = temp1 + dir1[i];
				int temp5 = temp2 + dir2[i];
				int temp6 = temp3 + dir3[i];
				if (0 <= temp4 && temp4 < h && 0 <= temp5 && temp5 < n && 0 <= temp6 && temp6 < m)
				{
					if (arr[temp4][temp5][temp6] == 0 && !visit[temp4][temp5][temp6])
					{
						arr[temp4][temp5][temp6] = 1;
						change = true;
						cnt--;
						_q.push({ temp4,temp5,temp6 });
						visit[temp4][temp5][temp6];
					}
				}
			}
		}
		if (change == false)break;
		ans++;
	}
	
}
int main()
{
	cin >> m >> n >> h;
	arr.resize(h, vector<vector<int>>(n, vector<int>(m)));
	visit.resize(h, vector<vector<bool>>(n, vector<bool>(m,false)));
	for(int i=0;i<h;i++)
		for(int j=0;j<n;j++)
			for (int k = 0; k < m; k++)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 0)cnt++;
				if (arr[i][j][k] == 1)
				{
					visit[i][j][k] = true;
					_q.push({ i,j,k });
				}
			}
	f();
	if (cnt)cout << "-1";
	else cout << ans;
}
 