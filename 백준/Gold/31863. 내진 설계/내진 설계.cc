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
#include<iomanip>
#include<climits>
#include <functional>

using namespace std;

int dir[][2] = { {-1,0}, {0,1}, {1,0} ,{0,-1},{-1,1},{1,1},{1,-1},{-1,-1} };

vector<int> parent;
int findParent(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = findParent(parent[a]);
}
void Union(int a, int b)
{
	parent[findParent(b)] = findParent(a);
}
bool IsUnion(int a, int b)
{
	return findParent(a) == findParent(b);
}


int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	pair<int, int> s;
	pair<int, int> cnt;

	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			char c; 
			cin >> c;
			switch (c)
			{
				case '@':
				{
					s = { i,j };
					arr[i][j] = 0;
					break;
				}
				case '.':
				{
					arr[i][j] = 0;
					break;
				}
				case '*':
				{
					cnt.first++;
					arr[i][j] = 1;
					break;
				}
				case '#':
				{
					cnt.first++;
					arr[i][j] = 2;
					break;
				}
				default:
				{
					arr[i][j] = -1;
					break;
				}
			}
		}
	{
		queue<pair<int, int>> q;
		q.push(s);
		while (q.empty() == false)
		{
			auto now = q.front(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int r = now.first + dir[i][0];
				int c = now.second + dir[i][1];
				if (0 <= r && r < n && 0 <= c && c < m && arr[r][c]>0)
				{
					int pre = arr[r][c]--;
					if (pre == 1)
					{
						q.push({ r,c });
						cnt.first--;
						cnt.second++;

					}
				}
				if (now == s)
				{
					int rr = now.first + dir[i][0]*2;
					int cc = now.second + dir[i][1]*2;
					if (0 <= rr && rr < n && 0 <= cc && cc < m && arr[rr][cc]>0 && arr[r][c]>=0)
					{
						int pre = arr[rr][cc]--;
						if (pre == 1)
						{
							q.push({ rr,cc });
							cnt.first--;
							cnt.second++;
						}
					}
				}
			}
		}
	}
	cout << cnt.second << " " << cnt.first;
}

