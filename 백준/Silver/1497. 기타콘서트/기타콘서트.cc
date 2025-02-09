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


#include<cmath>
#include<limits>
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int64_t> v(n);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str >> str;
		int64_t result = 0;
		for (char& c : str)
		{
			result <<= 1;
			if (c == 'Y')
			{
				result |= 1;
			}
			else
			{
				result |= 0;
			}
		}
		v[i] = result;
	}
	
	int32_t bitMax = (int32_t)pow(2, n);
	int32_t ans = numeric_limits<int32_t>::max();
	int32_t GmusicCnt = 0;
	for (int32_t i = 1; i < bitMax; i++)
	{
		int32_t bit = i;
		int64_t result = 0;
		int move = n - 1;
		int32_t cnt = 0;
		int musicCnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (((bit >> (move - j)) & 1) == 1)
			{
				++cnt;
				result |= v[j];
			}
		}
		for (int j = 0; j < m; j++)
		{
			if ((result & 1) == 1)
				++musicCnt;
			result >>= 1;
		}
		if (musicCnt > GmusicCnt)
		{
			ans = cnt;
			GmusicCnt = musicCnt;
		}
		else if (musicCnt > 0 && musicCnt == GmusicCnt)
		{
			ans = min(ans, cnt);
		}
	}
	if (ans == numeric_limits<int32_t>::max())
	{
		cout << "-1";
	}
	else cout << ans;
}