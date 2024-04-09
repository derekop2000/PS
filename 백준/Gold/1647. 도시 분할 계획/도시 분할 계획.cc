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
int ans = 0;
int component;
vector<int> parent;
int find_parent(int a)
{
	if (parent[a] == a)
		return a;
	else return parent[a] = find_parent(parent[a]);
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
	int aa = find_parent(a);
	int bb = find_parent(b);
	return aa == bb;
}
int main()
{
	cin >> n >> m;
	arr.resize(m, vector<int>(3));
	parent.resize(n + 1);
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i][1] >> arr[i][2] >> arr[i][0];
	}
	sort(arr.begin(), arr.end());
	component = n;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
        if(n==2)break;
		bool comp = my_is_union(arr[i][1], arr[i][2]);
		if (comp)continue;

		my_union(arr[i][1], arr[i][2]);
		component--;
		cnt++;
		ans += arr[i][0];
		if (cnt == n - 2)break;
	}
	cout << ans;
}
 