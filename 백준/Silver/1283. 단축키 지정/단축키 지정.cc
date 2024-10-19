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
#include <unordered_set>
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
	int n;
	cin >> n;
	bool arr[26] = { false };
	cin.ignore(100, '\n');
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		int index = -1;
		bool capital = true;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == ' ')
			{
				capital = true;
				continue;
			}

			int charNum = s[j] - 'A';
			if (charNum > 25)
			{
				charNum -= ('a' - 'A');
			}

			if (capital)
			{
				capital = false;
				if (arr[charNum] == false)
				{
					index = j;
					break;
				}
			}
			else
			{
				if (arr[charNum] == false && index == -1)
				{
					index = j;
				}
			}
		}
		if (index == -1)
			cout << s<<"\n";
		else
		{
			int charNum = s[index] - 'A';
			if (charNum > 25)
			{
				charNum -= ('a' - 'A');
			}
			arr[charNum] = true;
			string ans;
			ans += s.substr(0, index) + '[' + s[index] + ']' + s.substr(index + 1);
			cout << ans << "\n";
		}
	}
}


