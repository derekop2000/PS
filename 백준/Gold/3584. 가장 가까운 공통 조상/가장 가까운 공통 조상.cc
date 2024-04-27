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
using namespace std;


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> parent(n,-1);
		for (int i = 0; i < n-1; i++)
		{
			int a, b;
			cin >> a >> b;
			a--; b--;

			parent[b] = a;
		}
		int a, b;
		cin >> a >> b;
		a--; b--;
		set<int> storage;
		int now = a;
		storage.insert(now);
		while (parent[now] != -1)
		{
			now = parent[now];
			storage.insert(now);
		}
		now = b;
		while (parent[now] != -1)
		{
			if (storage.find(now) != storage.end())
			{
				break;
			}
			now = parent[now];
		}
		cout << now+1<<"\n";
	}
}