#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

#define INF 10000000
map<string, int> Map;
int parent[INF];
int parent_cnt[INF];
int findParent(int a)
{
	if (parent[a] == a)return a;
	else return parent[a] = findParent(parent[a]);
}
void union_(int a, int b)
{
	int aa = findParent(a);
	int bb = findParent(b);
	if (aa == bb) { return; }
	else
	{
		if (aa < bb) { parent[bb] = aa; parent_cnt[aa] += parent_cnt[bb]; }
		else { parent[aa] = bb; parent_cnt[bb] += parent_cnt[aa]; }
	}
}
bool isUnion(int a, int b)
{
	return findParent(a) == findParent(b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int index_ = 0;
		Map.clear();
		for (int i = 0; i < n; i++)
		{
			string a;
			string b;
			int a_index;
			int b_index;
			cin >> a >> b;
			map<string, int>::iterator it;
			it = Map.find(a);
			if (it == Map.end())
			{
				Map.insert(make_pair(a, index_));
				a_index = index_;
				parent[index_] = index_;
				parent_cnt[index_] = 1;
				index_++;
			}
			else a_index = (*it).second;

			it = Map.find(b);
			if (it == Map.end())
			{
				Map.insert(make_pair(b, index_));
				b_index = index_;
				parent[index_] = index_;
				parent_cnt[index_] = 1;
				index_++;
			}
			else b_index = (*it).second;

			union_(a_index, b_index);
			cout << parent_cnt[findParent(a_index)] << "\n";
		}
	}
}

