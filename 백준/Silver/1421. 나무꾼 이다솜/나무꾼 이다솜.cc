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

int cnt = 0;
vector<int> visit;
void f(int now, vector<vector<int>>& arr)
{
	for (auto next : arr[now])
	{
		if (visit[next])continue;
		cnt++;
		visit[next] = true;
		f(next, arr);
	}
}
int main()
{
	int n, c, w;
	cin >> n >> c >> w;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	long long int ans = 0;
	for(int i=1;i<= 10000;i++)
	{
		long long int sum = 0;
		for (int num : arr)
		{
			int cnt = 0;
			int cnt2 = 0;
			if (num < i)continue;
			cnt += num / i;
			cnt2 += num / i;
			if (num % i==0)cnt2--;
			long long int surve = cnt * i * w - cnt2 * c;
			if (surve < 0)
			{
				surve = 0;
			}
			sum += surve;
		}
		ans = max(ans, sum);
	}
	cout << ans;
}

