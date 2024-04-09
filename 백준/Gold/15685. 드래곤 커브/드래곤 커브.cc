#include<iostream>
#include<vector>
#include<memory>
#include<math.h>
using namespace std;

int dir1[] = { 0,-1,0,1 };
int dir2[] = { 1,0,-1,0 };
bool arr[101][101];
vector<int> dragon;
int n;
int x, y, d, g;
int ans = 0;
void make_dragon(int genaration)
{
	if (genaration == g)return;
	for (int i = dragon.size() - 1; i >= 0; i--)
	{
		dragon.push_back((dragon[i] + 1) % 4);
	}
	make_dragon(genaration + 1);
}
void check(int i, int j)
{
	arr[i][j] = true;
	for (int q = 0; q < dragon.size(); q++)
	{
		i += dir1[dragon[q]];
		j += dir2[dragon[q]];
		arr[i][j] = true;
	}
}
void f()
{
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
		{
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1])
				ans++;
		}
}
int main()
{
	cin >> n;
	for (int z = 0; z < n; z++)
	{
		cin >> x >> y >> d >> g;
		dragon.clear();
		dragon.push_back(d);
		make_dragon(0);
		check(y, x);
	}
	f();
	cout << ans;
}
