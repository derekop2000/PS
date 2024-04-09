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
vector<vector<int>> arr;
vector<bool> visit;
vector<int> partner;
int ans = 0;
bool f2(int now)
{
	if (visit[now])
	{
		return false;
	}
	visit[now] = true;
	for (int i = 0; i < arr[now].size(); i++)
	{
		int next = arr[now][i];
		if (partner[next] == -1)
		{
			partner[next] = now;
			return true;
		}
		if (partner[next] == now)continue;
		if (f2(partner[next]))
		{
			partner[next] = now;
			return true;
		}
	}
	return false;
}
void f()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			visit[j] = false;
		if (f2(i))
			ans++;
		for (int j = 0; j < n; j++)
			visit[j] = false;
		if (f2(i))
			ans++;
	}
}
int main()
{
	cin >> n >> m;
	arr.resize(n);
	visit.resize(n);
	partner.resize(m, -1);
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		for (int j = 0; j < t; j++)
		{
			int work;
			cin >> work;
			work--;
			arr[i].push_back(work);
		}
	}
	f();
	cout << ans;
}