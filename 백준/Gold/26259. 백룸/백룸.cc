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

#include<limits>
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	vector<vector<pair<bool, bool>>> block(n, vector < pair<bool,bool>> (m, make_pair<bool,bool>(true,true)));
	
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == c)
	{
		a--;
		for (int i = min(b, d); i < max(b, d); i++)
			block[a][i].first = false;
	}
	else
	{
		b--;
		for (int i = min(a, c); i < max(a, c); i++)
			block[i][b].second = false;
	}
	vector<vector<int>> dp(n, vector<int>(m, numeric_limits<int>::min()));
	dp[0][0] = arr[0][0];
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (i > 0 && block[i-1][j].first && dp[i-1][j] != numeric_limits<int>::min())
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
			}
			if (j > 0 && block[i][j-1].second && dp[i][j-1] != numeric_limits<int>::min())
			{
				dp[i][j] = max(dp[i][j], dp[i][j-1] + arr[i][j]);
			}
		}
	if (dp[n - 1][m - 1] != numeric_limits<int>::min())
		cout << dp[n - 1][m - 1];
	else cout << "Entity";
}