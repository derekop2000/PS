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
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		if(c=='A')
			v.push_back(0);
		else if (c == 'C')
			v.push_back(1);
		else if (c == 'G')
			v.push_back(2);
		else
			v.push_back(3);
	}
	int arr[4]= { 0,0,0,0 };
	int cnt = 0;
	vector<int> needs(4);
	for (int i = 0; i < 4; i++)
		cin >> needs[i];
	for (int i = 0; i < m; i++)
	{
		arr[v[i]]++;
	}

	{
		if (arr[0] >= needs[0] && arr[1] >= needs[1] && arr[2] >= needs[2] && arr[3] >= needs[3])
			cnt++;
	}
	for (int i = m; i < n; i++)
	{
		arr[v[i]]++;
		arr[v[i - m]]--;
		if (arr[0] >= needs[0] && arr[1] >= needs[1] && arr[2] >= needs[2] && arr[3] >= needs[3])
			cnt++;
	}
	cout << cnt;
}



