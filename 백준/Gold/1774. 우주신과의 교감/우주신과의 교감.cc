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

double my_magnitude(int a,int b)
{
	return sqrt(pow(a, 2) + pow(b, 2));
}
vector<int> parent;
int find_parent(int a)
{
	if (parent[a] == a)return a;
	else return parent[a] = find_parent(parent[a]);
}
void _union(int a, int b)
{
	int parent_a = find_parent(a);
	int parent_b = find_parent(b);
	if (parent_a == parent_b)return;
	if (parent_a > parent_b)
	{
		parent[parent_a] = parent_b;
	}
	else parent[parent_b] = parent_a;
}
bool my_union(int a, int b)
{
	if (find_parent(a) == find_parent(b))return true;
	else return false;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v1;
	vector<pair<int, int>> v2;
	vector<tuple<double,int,int>> v3;
	parent.resize(n);
	v1.resize(n);
	v2.resize(m);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i].first >> v1[i].second;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		v2[i].first = a;
		v2[i].second = b;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			v3.push_back({ my_magnitude(v1[i].first - v1[j].first,v1[i].second - v1[j].second),i,j });
		}
	}
	sort(v3.begin(), v3.end());
	for (int i = 0; i < m; i++)
	{
		_union(v2[i].first, v2[i].second);
	}
	vector<bool> component(n, false);
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		int temp2 = find_parent(i);
		if (component[temp2] == false)
		{
			temp++;
			component[temp2] = true;
		}
	}
	temp--;
	int _index = 0;
	double ans = 0;
	while (temp)
	{
		if (my_union(get<1>(v3[_index]), get<2>(v3[_index])) == false)
		{
			_union(get<1>(v3[_index]), get<2>(v3[_index]));
			ans += get<0>(v3[_index]);
			temp--;
		}
		_index++;
		
	}

	cout<<setprecision(2)<<fixed <<ans;
	
}
