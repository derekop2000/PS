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
	vector<int64_t> arr(n);
	vector<int64_t> arr2(n);
	auto f = [](int idx1, int idx2)
		{
			int cnt = 0;
			if (idx1 <= idx2)
			{
				cnt = 1;
				while (idx1 <= idx2)
				{
					cnt--;
					idx1 <<= 1;
				}
			}
			else
			{
				cnt = 0;
				while (idx1 > idx2)
				{
					cnt++;
					idx2 <<= 1;
				}
			}
			return cnt;
		};
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (i != 0)
		{
			arr2[i] = f(arr[i - 1], arr[i]);
		}
	}
	int64_t ans = 0;
	int64_t last = 0;
	for (auto temp : arr2)
	{
		int64_t temp2 = last + temp;
		if (temp2 > 0)
			ans += temp2;
		last = temp2;
		if (last < 0)
			last = 0;
	}
	cout << ans;
}