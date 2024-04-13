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
using namespace std;

vector<int> parent;
int find_parent(int a)
{
	if (parent[a] == a)return a;
	return parent[a] = find_parent(parent[a]);
}
void my_union(int a, int b)
{
	parent[find_parent(b)] = find_parent(a);
}
bool my_is_union(int a, int b)
{
	return find_parent(a) == find_parent(b);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		parent.push_back(i);
	vector<tuple<int,int,int>> v;
 	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a ,b ,i });
	}
	sort(v.begin(), v.end());
	int last = get<1>(v[0]);
	for (int i = 1; i < n; i++)
	{
		if (last >= get<0>(v[i]))
		{
			last = max(last, get<1>(v[i]) );
			my_union(get<2>(v[i - 1]) , get<2>(v[i]) );
		}
		else last = get<1>(v[i]);
	}
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (my_is_union(a, b))
			cout << "1\n";
		else cout << "0\n";
	}
}