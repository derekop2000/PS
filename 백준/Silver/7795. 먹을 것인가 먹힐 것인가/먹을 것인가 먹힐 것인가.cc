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
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		vector<int> aGroup(a);
		vector<int> bGroup(b);
		for (int i = 0; i < a; i++)
			cin >> aGroup[i];
		for (int i = 0; i < b; i++)
			cin >> bGroup[i];
		sort(aGroup.begin(), aGroup.end());
		sort(bGroup.begin(), bGroup.end());
		int cnt=0;
		int bIndex = 0;
		for (int i = 0; i < a; i++)
		{
			while (bIndex < b && bGroup[bIndex] < aGroup[i])
			{
				bIndex++;
			}
			cnt+=bIndex;
		}
		cout << cnt << "\n";
	}
}

