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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n+1, vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++)
		{
			int temp;
			cin >> temp;
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + temp;
		}
	int ans = -10000;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for(int q = 1;i+q-1<=n;q++)
				for (int k = 1; k + j - 1 <= m; k++)
				{
					int temp = arr[i + q - 1][j + k - 1] - arr[i - 1][j + k - 1] - arr[i + q - 1][j - 1] + arr[i - 1][j - 1];
					ans = max(ans, temp);
				}
		}
	}
	cout << ans;
}