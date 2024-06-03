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
	int ans = 0;
	int n, m, k;
	cin >> n >> m >> k;
	vector<bool> virus(n);
	for (int i = 0; i < k; i++)
	{
		int temp;
		cin >> temp;
		temp--;
		virus[temp] = true;
		ans = temp;
	}
	vector<tuple<int, int, int>> v;
	for (int i = 0; i < m; i++)
	{
		int a;
		int b, c;
		cin >> a >> b >> c;
		b--; c--;
		v.push_back({ a,b,c });
	}
	sort(v.begin(), v.end());  // 로그 기록 정렬
	for (int i = 0; i < n; i++)
	{
		if (virus[i] == false)continue; // 바이러스 대상만 검사
		vector<int> visit(n);
		visit[i] = true;
		int cnt = 1; // 감염 수
		for (int j = 0; j < m; j++)
		{
			int a = get<1>(v[j]);
			int b = get<2>(v[j]);
			if (visit[a] && !visit[b]) // 감염 컴퓨터가 비감염 컴퓨터를 감염 시켰을 경우만
			{
				if (virus[b] == false)
					break;
				visit[b] = true;
				cnt++;
			}
		}
		if (cnt == k)
		{
			ans = i;
			break;
		}
	}
	cout << ans + 1;
}