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
	int aa = parent[a];
	if (a == aa)return a;
	return parent[a] = find_parent(aa);
}
void my_union(int a, int b)
{
	int aa = find_parent(a);
	int bb = find_parent(b);
	parent[bb] = aa;
}
bool my_is_union(int a, int b)
{
	return find_parent(a) ==find_parent(b);
}
int main()
{
	int n;
	cin >> n;
	parent.resize(n);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	for (int i = 0; i < n - 2; i++)
	{
		int a, b;
		cin >> a >> b;
		my_union(a - 1, b - 1);
	}
	int temp = find_parent(0);
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (temp != find_parent(i))
		{
			ans = i;
			break;
		}
	}
	cout << 1 << " " << ans + 1;
}