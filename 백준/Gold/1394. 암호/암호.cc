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
	string s1;
	string s2;
	cin >> s1 >> s2;
	int stringSize = s2.size();
	int s1Size = s1.size();
	vector<int> v(stringSize,1);
	map<char, int> index;
	for (int i = 0; i < s1Size; i++)
	{
		index.insert({ s1[i],i });
	}
	int digit = stringSize - 1;
	for (int i = 0; i < stringSize - 1; i++)
	{
		char c = s2[i];
		v[digit] += index[c];
		digit--;
	}
	long long ans = index[s2[stringSize - 1]]+1;
	
	long long int temp = 1;
	for (int i = 1; i < stringSize; i++)
	{
		temp *= s1Size;
		temp %= 900528;
		
		ans += temp*v[i];
		ans%= 900528;
	}
	cout << ans;
}