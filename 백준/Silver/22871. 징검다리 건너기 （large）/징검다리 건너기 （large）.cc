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
	int n;
	cin >> n;
	vector<int> arr(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	long long int k = 0;
	long long int l = 0;
	long long int r = (long long int)(5000 - 2) * (1000000 - 1);
	k = r;
	while (l <= r)
	{
		long long int mid = (l + r) / 2;
		vector<bool> visit(n + 1, false);
		queue<int> q;
		q.push(1);
		visit[1] = true;
		while (q.empty() == false)
		{
			int now = q.front();
			q.pop();
			for (int i = now + 1; i <= n; i++)
			{
				if (visit[i] == false)
				{
					if ( ((long long int)abs(i - now) * (abs(arr[i] - arr[now])+1) ) <= mid)
					{
						q.push(i);
						visit[i] = true;
					}
				}
			}
		}
		if (visit[n])
		{
			k = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << k;
}

