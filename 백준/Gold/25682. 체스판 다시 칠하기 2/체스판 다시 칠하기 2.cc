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
#include <unordered_set>
#include<stack>
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
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> white(n+1, vector<int>(m+1,0));
	vector<vector<int>> black(n+1, vector<int>(m+1,0));
	char bb = 'B';
	char ww = 'W';
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			bb = 'B';
			ww = 'W';
		}
		else
		{
			bb = 'W';
			ww = 'B';
		}
		for (int j = 1; j <= m; j++)
		{
			char c;
			cin >> c;
			{
				if (bb == c)
				{
					black[i][j] = black[i - 1][j] + black[i][j - 1] - black[i - 1][j - 1];
				}
				else
				{
					black[i][j] = black[i - 1][j] + black[i][j - 1] - black[i - 1][j - 1] +1 ;
				}
			}
			{
				if (ww == c)
				{
					white[i][j] = white[i - 1][j] + white[i][j - 1] - white[i - 1][j - 1];
				}
				else
				{
					white[i][j] = white[i - 1][j] + white[i][j - 1] - white[i - 1][j - 1] + 1;
				}
			}
			if (bb == 'W')
				bb = 'B';
			else bb = 'W';
			if (ww == 'W')
				ww = 'B';
			else ww = 'W';
		}
	}
	int ans = k * k;
	for(int i=1;i+k-1<=n;i++)
		for (int j = 1; j+k-1 <= m; j++)
		{
			ans = min(ans,black[i + k - 1][j + k - 1] - black[i - 1][j + k - 1] - black[i + k - 1][j - 1] + black[i - 1][j - 1]);
			ans = min(ans, white[i + k - 1][j + k - 1] - white[i - 1][j + k - 1] - white[i + k - 1][j - 1] + white[i - 1][j - 1]);
		}
	cout << ans;
}