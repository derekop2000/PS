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
int v, e;
vector<vector<int>> arr;
vector<int> dfsTree;
int cnt = 0;
vector<pair<int, int>> ans;
int dfs(int now,int parent)
{
	dfsTree[now] = cnt++;
	int num = dfsTree[now];
	for (int i = 0; i < arr[now].size(); i++)
	{
		int next = arr[now][i];
		if (next == parent)continue;
		if (dfsTree[next] == -1)
		{
			int low = dfs(next,now);
			num = min(num, low);
			if (low > dfsTree[now])
				ans.push_back({ min(now,next),max(now,next) });
		}
		else
		{
			num = min(num, dfsTree[next]);
		}
	}
	return num;
}
int main()
{
	cin >> v >> e;
	arr.resize(v);
	dfsTree.resize(v, -1);
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 0; i < v; i++)
	{
		if(dfsTree[i]==-1)
			dfs(i,-1);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
	}
}