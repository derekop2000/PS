#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include<tuple>
using namespace std;

int n,m;
vector<int> parent;
vector<tuple<int, int, int>>arr;
int find_parent(int a)
{
	if (parent[a] == a)
		return a;
	else return parent[a] = find_parent(parent[a]);
}
bool is_union_f(int a, int b)
{
	return find_parent(a) == find_parent(b);
}
void union_f(int a, int b)
{
	int best_parent_a = find_parent(a);
	int best_parent_b = find_parent(b);
	if (best_parent_a == best_parent_b)return;
	if (best_parent_b < best_parent_a)
		swap(best_parent_b, best_parent_a);
	parent[best_parent_b] = best_parent_a;
}

int main()
{
    ios_base::sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);
	cin >> n >> m;
	parent.resize(n);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		arr.push_back({ t3,t1-1,t2-1 });
	}
	sort(arr.begin(), arr.end());
	int line_cnt = 0;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int a = get<1>(arr[i]);
		int b = get<2>(arr[i]);
		if (find_parent(a) == find_parent(b))
			continue;
		union_f(a, b);
		line_cnt++;
		ans += get<0>(arr[i]);
		if (line_cnt == n - 1)break;
	}
	cout << ans;
}
