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

bool myCompare(tuple<int, int, int>& a, tuple<int, int, int>& b)
{
	if (get<0>(a) == get<0>(b))
	{
		return get<2>(a) > get<2>(b);
	}
	else return get<0>(a) < get<0>(b);
}
int main()
{
	int n, m;
	cin >> n >> m;
	cin.ignore(100, '\n');
	string s1,s2;
	getline(cin, s1);
	getline(cin, s2);
	int arr[128] = {};
	int arr2[128] = {};
	int Ccnt = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		int temp = s1[i];
		if (++arr[temp] == 1)
			Ccnt++;
	}
	int cnt = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		arr2[(int)s2[i]]++;
		if (arr2[(int)s2[i]] == arr[(int)s2[i]])
			cnt++;
	}
	int l = 0;
	int r = s1.size() - 1;
	int ans = 0;
	if (cnt == Ccnt)
		ans++;
	while (true)
	{
		r++;
		if (r >= s2.size())
			break;
		arr2[(int)s2[l]]--;
		if (arr2[(int)s2[l]] == arr[(int)s2[l]] - 1)
			cnt--;
		l++;
		

		arr2[(int)s2[r]]++;
		if (arr2[(int)s2[r]] == arr[(int)s2[r]])
			cnt++;
		if (cnt == Ccnt)
			ans++;
	}
	cout << ans;
}

