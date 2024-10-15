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


int dp[21][21][21] = { 0 };
int f(int a,int b,int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return dp[20][20][20] = f(20, 20, 20);
	if (dp[a][b][c] != 0)
		return dp[a][b][c];
	if (a < b && b < c)
	{
		int temp1 =  f(a, b, c - 1);
		int temp2 =  f(a, b-1, c - 1);
		int temp3 =  f(a, b-1, c);
		return  dp[a][b][c] = (temp1 + temp2 - temp3);
	}
	int temp1 =  f(a-1, b, c);
	int temp2 =  f(a-1, b - 1, c);
	int temp3 =  f(a-1, b , c-1);
	int temp4 =  f(a-1, b - 1, c-1);
	return dp[a][b][c] = ( temp1 + temp2 + temp3 - temp4);

}
int main()
{
	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << f(a, b, c)<<"\n";
	}
}

