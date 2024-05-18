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
	string a,temp_a, b;
	cin >> temp_a >> b;
	int temp = b.size() > temp_a.size();
	if (temp)
	{
		for (int i = 0; i < temp; i++)
			a.push_back('0');
	}
	for (int i = 0; i < temp_a.size(); i++)
		a.push_back(temp_a[i]);
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{
		
		if (a[i]==b[i])
		{
			if (a[i] == '8' && b[i] == '8')
				cnt++;
		}
		else break;
	}
	cout << cnt;
}