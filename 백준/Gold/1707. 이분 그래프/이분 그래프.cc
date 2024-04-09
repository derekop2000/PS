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
vector<int> visit;
bool ans;
void f(int now)
{
	for (int i = 0; i<arr[now].size(); i++)
	{
		int next = arr[now][i];
		if (visit[next])
		{
			if (visit[now] == visit[next])
			{
				ans = false;
				return;
			}
		}
		else
		{
			visit[next] = visit[now] == 1 ? 2 : 1;
			f(next);
			if (ans == false)return;
		}
	}
}
int main()
{
    ios::sync_with_stdio(0);
  cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> v >> e;
		visit.clear();
		visit.resize(v, 0);
		arr.clear();
		arr.resize(v);
		ans = true;
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			a--; b--;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		for(int i=0;i<v;i++)
			if (!visit[i])
			{
				visit[i] = 1;
				f(i);
			}
		if (ans)
			cout << "YES\n";
		else cout << "NO\n";
	}
}