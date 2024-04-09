#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include<tuple>
using namespace std;
int k,w,h;

vector<vector<int>> arr;
vector<vector<vector<int>>> dp;
int dir1[] = {-1,0,1,0,-2,-1,1,2,2,1,-1,-2};
int dir2[] = { 0,1,0,-1,1,2,2,1,-1,-2,-2,-1 };
void bfs()
{
	queue<tuple<int,int,int>> q;
	q.push({0,0,0});
	while (!q.empty())
	{
		int i = get<0>(q.front());
		int j = get<1>(q.front());
		int cnt = get<2>(q.front());
		q.pop();
		for (int t = 0; t < 4; t++)
		{
			int ii = i + dir1[t];
			int jj = j + dir2[t];
			if (0 <= ii && ii < h && 0 <= jj && jj < w && arr[ii][jj] == 0)
			{
				if (dp[i][j][cnt]+1 < dp[ii][jj][cnt])
				{
					dp[ii][jj][cnt] = dp[i][j][cnt] + 1;
					q.push({ii,jj,cnt});
				}
			}
		}
		if (cnt < k)
		{
			for (int t = 4; t < 12; t++)
			{
				int ii = i + dir1[t];
				int jj = j + dir2[t];
				if (0 <= ii && ii < h && 0 <= jj && jj < w && arr[ii][jj] == 0)
				{
					if (dp[i][j][cnt]+1 < dp[ii][jj][cnt +1])
					{
						dp[ii][jj][cnt + 1] = dp[i][j][cnt] + 1;
						q.push({ ii,jj,cnt +1 });
					}
				}
			}
		}
	}
}
int main()
{
	cin >> k >> w >> h;
	arr.resize(h, vector<int>(w));
	dp.resize(h, vector<vector<int>>(w,vector<int>(k+1, 2147483647)));
	for(int i=0;i<h;i++)
		for (int j = 0; j < w; j++)
		{
			cin >> arr[i][j];
		}
	dp[0][0][0]=0;
	bfs();
	int ans = 2147483647;
	for (int i = 0; i <= k; i++)
	{
		if (dp[h - 1][w - 1][i] < ans)
		{
			ans = dp[h - 1][w - 1][i];
		}
	}
	if (ans == 2147483647)
	{
		cout << "-1";
	}
	else cout << ans;
	
}
