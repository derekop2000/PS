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
#include <cmath>
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
	int n, r, c;
	cin >> n >> r >> c;
	n = pow(2, n);
	int sR = 0, sC = 0;
	int ans = 0;
	while (!(sR == r && sC == c))
	{
		int pos = 0;
		if (sR + n / 2 <= r)
		{
			pos += 2;
		}
		if(sC + n/2 <= c)
		{
			pos++;
		}

		int total = n * n;
		if (pos == 0)
		{

		}
		else if (pos == 1)
		{
			ans += total / 4;
			sC += n / 2;
		}
		else if (pos == 2)
		{
			ans += total / 2;
			sR += n / 2;
		}
		else
		{
			ans += (total / 4) * 3;
			sR += n / 2;
			sC += n / 2;
		}
		n /= 2;
	}
	cout << ans;
}