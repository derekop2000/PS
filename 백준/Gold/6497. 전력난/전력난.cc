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
using namespace std;

vector<tuple<int, int, int>> arr;
vector<int> parent;
int find_parent(int a)
{
	if (parent[a] == a)return a;
	else return parent[a] = find_parent(parent[a]);
}
void my_union(int a, int b)
{
	int aa = find_parent(a);
	int bb = find_parent(b);
	if (aa == bb) return;
	parent[aa] = bb;
}
bool my_is_union(int a, int b)
{
	int aa = find_parent(a);
	int bb = find_parent(b);
	return aa == bb;
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while (true)
	{
		int m, n;
		cin >> m >> n;
		if (m == 0 && n == 0)break;
		int a, b, c;
		int ans = 0;
		arr.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> c;
			arr.push_back({ c,a,b });
			ans += c;
		}
		sort(arr.begin(), arr.end());
		int cnt = m - 1;
		parent.resize(m);
		for (int i = 0; i < m; i++)
			parent[i] = i;
		for (int i = 0; i < n; i++)
		{
			int distance = get<0>(arr[i]);
			int x = get<1>(arr[i]);
			int y = get<2>(arr[i]);
			if (my_is_union(x, y))continue;
			ans -= distance;
			my_union(x, y);
			cnt--;
			if (cnt == 0)break;
		}
		cout << ans << "\n";
	}
}
