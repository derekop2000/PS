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
	int t;
	cin >> t;
	while (t--)
	{
		int n, money;
		cin >> n >> money;
		map<string, priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> m;
		unordered_set<string> component;
		for (int i = 0; i < n; i++)
		{
			string s1, s2;
			int a, b;
			cin >> s1 >> s2 >> a >> b;
			component.insert(s1);
			m[s1].push({ a,b });
		}
		int ans = 0;
		int cnt = 0;
		
		priority_queue<tuple<int, int, string>,vector<tuple<int, int, string>>,greater<tuple<int, int, string>>> q;
		for (auto& temp : component)
		{
			cnt += m[temp].top().first;
			q.push(tuple<int, int, string>{ m[temp].top().second, m[temp].top().first , temp });
			m[temp].pop();
		}
		while (true)
		{
			auto current = q.top(); q.pop();
			int quality = get<0>(current);
			int price = get<1>(current);
			string name = get<2>(current);
			ans = quality;
			auto& pq = m[name];

			while (pq.size() != 0 && pq.top().second <= quality)
			{
				pq.pop();
			}
			if (pq.size() == 0)
				break;
			q.push(tuple<int, int, string>{pq.top().second, pq.top().first, name});
			cnt -= price;
			cnt += pq.top().first;
			if (cnt > money)
				break;
		}
		cout << ans << "\n";
	}

}