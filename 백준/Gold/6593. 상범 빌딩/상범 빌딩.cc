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
	while (true)
	{
		int l, r, c;
		tuple<int, int, int> s, e;
		cin >> l >> r >> c;
		if (l == 0)
			break;
		vector<vector<vector<int>>> arr(l, vector<vector<int>>(r, vector<int>(c)));
		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++)
				for (int q = 0; q < c; q++)
				{
					char c;
					cin >> c;
					if (c == '#')
						arr[i][j][q] = 0;
					else arr[i][j][q] = 27000;
					if (c == 'S')
						s = { i,j,q };
					if (c == 'E')
						e = { i,j,q };

				}
		queue<tuple<int, int, int>> q;
		q.push(s);
		vector<vector<int>> temp = { {-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} };
		arr[get<0>(s)][get<1>(s)][get<2>(s)] = 0;
		while (q.empty()==false)
		{
			auto now = q.front(); q.pop();
			for (int i = 0; i < 6; i++)
			{
				int t0 = get<0>(now) + temp[i][0];
				int t1 = get<1>(now) + temp[i][1];
				int t2 = get<2>(now) + temp[i][2];
				tuple<int, int, int> next = { t0,t1,t2 };
				if (0 <= t0 && t0 < l && 0 <= t1 && t1 < r && 0 <= t2 && t2 < c && arr[t0][t1][t2])
				{
					if (arr[t0][t1][t2] > arr[get<0>(now)][get<1>(now)][get<2>(now)] + 1)
					{
						arr[t0][t1][t2] = arr[get<0>(now)][get<1>(now)][get<2>(now)] + 1;
						q.push({ t0,t1,t2 });
					}
				}
				
			}
		}
		if (arr[get<0>(e)][get<1>(e)][get<2>(e)] != 27000)
			cout << "Escaped in " << arr[get<0>(e)][get<1>(e)][get<2>(e)] << " minute(s).\n";
		else cout << "Trapped!\n";
	}
	
}

