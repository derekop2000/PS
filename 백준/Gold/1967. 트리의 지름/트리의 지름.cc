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
vector<vector<pair<int,int>>> arr;
vector<bool> visit;
int ans = 0;
int dfs(int now)
{
	int num;
	int z1 = 0, z2 = 0;
	visit[now] = true;
	for (int i = 0; i < arr[now].size(); i++)
	{
		int next = arr[now][i].first;
		if (visit[next])continue;
		num = arr[now][i].second + dfs(next);
		if (num > min(z1,z2))
		{
			z1 = max(z1, z2);
			z2 = num;
		}
	}
	ans = max(ans, z1 + z2);
	return max(z1, z2);
}
int main()
{
	cin >> n;
	arr.resize(n);
	visit.resize(n,false);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b,c;
		cin >> a >> b>>c;
		a--; b--;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	dfs(0);
	cout << ans;
}