#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int ans = 0;
		int a, b, c;
		cin >> a >> b >> c;
		c--;
		vector<vector<pair<int, int>>> arr(a);
		vector<int> visit(a,10000000);
		visit[c] = 0;
		for (int i = 0; i < b; i++)
		{
			int q,w,e;
			cin >> q >> w >> e;
			q--; w--;
			arr[w].push_back(make_pair(q, e));
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
		q.push(make_pair(0, c));
		while (!q.empty())
		{
			int about_time = q.top().first;
			int who = q.top().second;
			q.pop();
			if (visit[who] < about_time)continue;
			for (int i = 0; i < arr[who].size(); i++)
			{
				int about_time2 = about_time + arr[who][i].second;
				int who2 = arr[who][i].first;
				if (visit[who2] > about_time2)
				{
					visit[who2] = about_time2;
					q.push(make_pair(about_time2, who2));
				}
			}
		}
		int cnt = 0;
		
		for (int i = 0; i < a; i++)
		{
			if (visit[i] < 10000000)
			{
				cnt++;
				if (visit[i]>0 && ans < visit[i])ans = visit[i];
			}
		}
		cout << cnt << " "<<ans << "\n";
	}
}

