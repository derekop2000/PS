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
#include<stack>
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


#include<limits>
int main()
{
	int n;
	cin >> n;
	vector<int> preArr(31);
	preArr[0] = 1;
	for (int i = 1; i <= 30; i++)
		preArr[i] = preArr[i - 1] * 2;
	auto f = [&preArr](int temp)
		{
			int l = 0;
			int r = 30;
			int re = -1;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (preArr[mid] <= temp)
				{
					re = mid;
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
			return re;
		};
	int minIdx = 0;
	int preValue = 1;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		int idx = f(temp);
		if (idx > minIdx)
		{
			minIdx = idx;
			preValue = temp;
		}
		else
		{
			int dis = minIdx - idx;
			ans += dis;
			temp *= preArr[dis];
			if (temp < preValue)
			{
				++ans;
				temp *= 2;
				preValue = temp;
			}
		}
	}
	cout << ans;
}