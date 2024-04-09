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
int n, m;
int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};
vector<vector<int>> arr;
vector<vector<int>> visit;
int ans = 0;
void f(int a, int b)
{
	int aa = a + dir1[arr[a][b]-1];
	int bb = b + dir2[arr[a][b]-1];
	if (visit[aa][bb] == 2)
	{
		visit[a][b] = 2;
		return;
	}
	else if(visit[aa][bb] ==1)
	{
		visit[a][b] = 2;
		ans++;
		return;
	}
	else
	{
		visit[aa][bb] = 1;
		f(aa, bb);
		visit[a][b] = 2;
	}
}
int main()
{
	cin >> n >> m;
	arr.resize(n, vector<int>(m));
	visit.resize(n, vector<int>(m,0));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			char temp;
			cin >> temp;
			if (temp == 'U')
				arr[i][j] = 1;
			else if(temp == 'R')
				arr[i][j] = 2;
			else if (temp == 'D')
				arr[i][j] = 3;
			else
				arr[i][j] = 4;
		}
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j] == 2)
			{
				continue;
			}
			visit[i][j] = 1;
			f(i, j);
		}
	cout << ans;
}