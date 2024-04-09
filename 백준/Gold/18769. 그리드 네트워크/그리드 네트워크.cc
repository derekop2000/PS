#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int find_parent(vector<int>& parent, int a)
{
	int parentA = parent[a];
	if (parentA == a)return parentA;
	return parent[a] = find_parent(parent, parentA);
}
void my_union(vector<int>& parent, int a, int b)
{
	int parentA = find_parent(parent, a);
	int parentB = find_parent(parent, b);
	parent[parentB] = parentA;
}
bool my_is_union(vector<int>& parent, int a, int b)
{
	return find_parent(parent, a) == find_parent(parent, b);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int r, c;
		cin >> r >> c;
		vector<tuple<int, int, int>> v;
		vector<int> parent(r*c);
		for (int i = 0; i < r * c; i++)
			parent[i] = i;
		int now = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c - 1; j++)
			{
				int value;
				cin >> value;
				v.push_back({ value,now,now + 1 });
				now++;
			}
			now++;
		}
		now = 0;
		for (int i = 0; i < r - 1; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int value;
				cin >> value;
				v.push_back({ value,now,now + c });
				now++;
			}
		}
		sort(v.begin(), v.end());
		int ans = 0;
		int cnt = r * c - 1;
		int index = 0;
		while (cnt)
		{
			int value = get<0>(v[index]);
			int v1 = get<1>(v[index]);
			int v2 = get<2>(v[index]);
			index++;
			if (my_is_union(parent, v1, v2) == false)
			{
				my_union(parent, v1, v2);
				ans += value;
				cnt--;
			}
		}
		cout << ans << "\n";
	}
}