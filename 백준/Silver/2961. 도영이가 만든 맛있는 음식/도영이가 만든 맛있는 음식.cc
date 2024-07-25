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

int n, m;
int cnt = 0;
vector<vector<int>> arr;
void f(int r, int c, int num1, int num2,int now)
{
	int rr = r + dir[1][0];
	int cc = c + dir[1][1];
	if (cc < m && arr[rr][cc] > 0)
	{
		if (arr[rr][cc] == 1 && arr[rr][cc] != now)
		{
			arr[rr][cc] = 0;
			f(rr, cc, num1 + 1, num2, 1);
		}
		else if(arr[rr][cc] == 2 && arr[rr][cc] != now)
		{
			arr[rr][cc] = 0;
			f(rr, cc, num1, num2+1,2);
		}
		else
		{
		arr[rr][cc] = 0;
		f(rr, cc, num1, num2,now);

		}
	}
	else
	{
		cnt += min(num1, num2);
		cnt++;
	}
}
int main()
{
	int n;
	cin >> n;
	set<pair<long long int, long long int>> v;
	long long int ans = 1000000000;
	for (int i = 0; i < n; i++)
	{
		set<pair<long long int, long long int>> tempV;
		int a, b;
		cin >> a >> b;
		for (auto mem : v)
		{
			pair<long long int, long long int> temp;
			temp.first = a * mem.first;
			temp.second = b + mem.second;
			tempV.insert(temp);
			ans = min(ans, abs(temp.first - temp.second));
		}
		pair<long long int, long long int> temp;
		temp.first = a;
		temp.second = b;
		tempV.insert(temp);
		ans = min(ans, abs(temp.first - temp.second));
		for (auto temp : tempV)
			v.insert(temp);
	}
	cout << ans;
}

