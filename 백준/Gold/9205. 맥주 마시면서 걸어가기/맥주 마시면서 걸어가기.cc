#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;

struct pos
{
	int x;
	int y;
};
int n;
pos home;
pos des;
pos arr[101];
bool ans;
bool visit[101];
bool can_go(int x1,int y1,int x2,int y2)
{
	return (abs(x2 - x1) + abs(y2 - y1) <= 1000);
}
void f(int x,int y)
{
	if (ans)return;
	if (x == des.x && y == des.y)
	{
		ans = true;
		return;
	}
	for (int i = 0; i <= n; i++)
	{
		if (ans)return;
		if (visit[i])continue;
		if (!can_go(x, y, arr[i].x, arr[i].y))continue;
		visit[i] = true;
		f(arr[i].x, arr[i].y);
		//visit[i] = false;
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ans = false;
		cin >> n;
		cin >> home.x >> home.y;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].x >> arr[i].y;
			visit[i] = false;
		}
        visit[n] = false;
		cin >> des.x >> des.y;
		arr[n].x = des.x;
		arr[n].y = des.y;
		f(home.x, home.y);
		if (ans) cout << "happy\n";
		else cout << "sad\n";
	}
}
