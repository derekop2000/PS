#include <iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<map>
#include<algorithm>
using namespace std;

int n, k;
string str;
map<string, bool> visited;
int ans = -1;
void bfs()
{
	queue<pair<string, int>> q;
	string temp = str;
	sort(str.begin(), str.end());
	q.push({ temp,0 });
	visited.insert({ temp,true });
	while (!q.empty())
	{
		auto now = q.front(); q.pop();
		if (now.first == str)
		{
			ans = now.second;
			return;
		}
		for (int i = 0; i <= n - k; i++)
		{
			temp = now.first;
			reverse(temp.begin() + i, temp.begin() + i + k);
			if (visited.count(temp)==0)
			{
				visited.insert({ temp,true });
				q.push({ temp,now.second + 1 });
			}
		}
	}


}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		str += c;
	}
	bfs();
	if (ans != -1)cout << ans;
	else cout << "-1";
}