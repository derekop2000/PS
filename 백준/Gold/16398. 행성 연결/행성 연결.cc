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

vector<int> parent;
int FindParent(int a)
{
	if (a == parent[a])return a;
	return parent[a] = FindParent(parent[a]);
}
void myUnion(int a, int b)
{
	int aa = FindParent(a);
	int bb = FindParent(b);
	parent[bb] = aa;
}
bool myIsUnion(int a, int b)
{
	return FindParent(a) == FindParent(b);
}
int main()
{
	int n;
	cin >> n;
	vector<tuple<int,int,int>> arr;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			if (j > i)
			{
				arr.push_back({ temp,i,j });
			}
		}
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < n; i++)
		parent.push_back(i);
	int cnt = 0;
	long long int ans = 0;
	for(int i=0;i<arr.size();i++)
	{
		auto now = arr[i];
		int value = get<0>(now);
		int a = get<1>(now);
		int b = get<2>(now);
		if (myIsUnion(a, b))continue;
		myUnion(a, b);
		ans += value;
		cnt++;
		if (cnt == n - 1)break;
	}
	cout << ans;
}