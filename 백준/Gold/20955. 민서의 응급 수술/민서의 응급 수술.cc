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

vector<int> parent;
int find_parent(int a)
{
	if (parent[a] == a)return a;
	return parent[a] = find_parent(parent[a]);
}
void my_union(int a, int b)
{
	int aa = find_parent(a);
	int bb = find_parent(b);
	if (aa == bb)return;
	parent[aa] = bb;
}
bool my_is_union(int a, int b)
{
	return find_parent(a) == find_parent(b);
}
int main()
{
	int n,m;
	cin >> n >> m;
	parent.resize(n+1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	int component = n;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int a,  b;
		cin >> a >> b;
		if (my_is_union(a, b))
		{
			ans++;
		}
		else
		{
			my_union(a, b);
			component--;
		}
	}
	if (component > 1)
	{
		ans += component;
		ans--;
	}
	cout << ans;
}
