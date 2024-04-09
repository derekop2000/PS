#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

#define INF 100001
int a, b;
int arr[INF];
vector<bool> visit;

int main()
{
	cin >> a >> b;
	if (a == b)
	{
		cout << "0\n" << a; return 0;
	}
	queue<int> q;
	q.push(a);
	
	for (int i = 0; i <= INF - 1; i++)
		arr[i] = INF;
	arr[a] = -1;
	visit.resize(INF, false);
	visit[a] = true;
	
	while (!q.empty())
	{
		int pos = q.front();
		q.pop();
		if (pos == b)break;
		int temp[3] = { pos + 1,pos - 1,pos * 2 };
		for (int i = 0; i < 3; i++)
		{
			if (0 <= temp[i] && temp[i] <= INF - 1 && !visit[temp[i]] )
			{
				visit[temp[i]] = true;
				arr[temp[i]] = pos;
				q.push(temp[i]);
			}
		}
	}
	
	vector<int> ans;
	ans.push_back(b);
	int index_ = b;
	while (1)
	{
		ans.push_back(arr[index_]);
		index_ = arr[index_];
		if (arr[index_] == -1)break;
	}
	cout << ans.size() - 1 << "\n";
	for (int i = ans.size()-1; i >=0 ; i--)
	{
		cout << ans[i] << " ";
	}
}

