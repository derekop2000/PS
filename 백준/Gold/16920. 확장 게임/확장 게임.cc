#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};

int n, m,p;
vector<vector<char>> _arr;
vector<int> _distance;
vector<queue<pair<int, int>>> q;

int main()
{
	cin >> n >> m >> p;
	_arr.resize(n, vector<char>(m));
	_distance.resize(p+1);
	q.resize(p + 1);
	for (int i = 1; i <= p; i++)
		cin >> _distance[i];
	vector<tuple<int, int, int>> temp;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> _arr[i][j];
			if ('0' <= _arr[i][j] && _arr[i][j] <= '9')
			{
				q[_arr[i][j] - '0'].push({i,j});
			}
		}
	while (true)
	{
		bool isChange = false;
		for (int i = 1; i <= p; i++)
		{
			int tryCnt = _distance[i];
			while (tryCnt && q[i].empty() == false)
			{
				int prevCnt = q[i].size();
				for (int j = 0; j < prevCnt; j++)
				{
					auto now = q[i].front(); q[i].pop();
					for (int k = 0; k < 4; k++)
					{
						int nextR = now.first + dir1[k];
						int nextC = now.second + dir2[k];
						if (0 <= nextR && nextR < n && 0 <= nextC && nextC < m && _arr[nextR][nextC] == '.')
						{
							isChange = true;
							_arr[nextR][nextC] = i + '0';
							q[i].push({ nextR,nextC });
						}
					}
				}
				tryCnt--;
			}
		}

		if (isChange==false)
			break;
	}
	vector<int> ans(p+1,0);
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if ('0' <= _arr[i][j] && _arr[i][j] <= '9')
			{
				ans[_arr[i][j] - '0']++;
			}
		}
	for (int i = 1; i <= p; i++)
		cout << ans[i] << " ";
}