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

int dir[][2] = { {-1,0}, {0,1}, {1,0} ,{0,-1} };

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

void f(tuple<int, int, int>& tri)
{
	int a = get<0>(tri);
	int b = get<1>(tri);
	int c = get<2>(tri);
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	tri = { a,b,c };
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b + c;
	vector < vector < bool >> visit(1501, vector<bool>(1501));
	tuple<int, int, int> tri = { a,b,c };
	f(tri);
	if (sum % 3 != 0)
	{
		cout << "0";
		return 0;
	}
	visit[get<0>(tri)][get<1>(tri)] = true;
	queue<tuple<int, int, int>> q;
	q.push(tri);
	bool ans = false;
	while (q.empty() == false)
	{
		auto now = q.front(); q.pop();
		int a = get<0>(now);
		int b= get<1>(now);
		int c = get<2>(now);
		if (a == b && b == c)
		{
			ans = true;
			break;
		}
		if (a != b)
		{
			tuple<int, int, int> t2 = { a * 2,b - a,c };
			f(t2);
			int a2 = get<0>(t2);
			int b2 = get<1>(t2);
			int c2 = get<2>(t2);
			if (visit[a2][b2] == false)
			{
				visit[a2][b2] = true;
				q.push(t2);
			}
		}
		if (a != c)
		{
			tuple<int, int, int> t2 = { a * 2,b,c-a };
			f(t2);
			int a2 = get<0>(t2);
			int b2 = get<1>(t2);
			int c2 = get<2>(t2);
			if (visit[a2][b2] == false)
			{
				visit[a2][b2] = true;
				q.push(t2);
			}
		}
	}
	if (ans)
		cout << "1";
	else cout << "0";
}