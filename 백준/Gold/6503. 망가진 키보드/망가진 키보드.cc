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
	while (true)
	{
		int m;
		cin >> m;
		if (m == false)
			break;
		string s;
		cin >> ws;
		getline(cin, s,'\n');
		vector<int> used(128, 0);
		int cnt = 0;
		int last = 0;
		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			if (used[c]>0)
			{
				used[c]++;
				ans = max(ans, i - last + 1);
			}
			else
			{
				if (cnt < m)
				{
					used[c]++;
					cnt++;
					ans = max(ans, i - last + 1);
				}
				else
				{
					while (true)
					{
						used[s[last]]--;
						if (used[s[last]] == 0)
						{
							last++;
							break;
						}
						last++;
					}
					used[c]++;
					ans = max(ans, i - last + 1);
				}
			}
		}
		cout << ans << "\n";
	}
}

