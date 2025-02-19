#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> ans;
void f(queue<int>& q, vector<vector<int>>& arr, vector<int>& ref)
{
	int current = q.front(); q.pop();
	ans.push_back(current);
	for (int i = 0; i < arr[current].size(); i++)
	{
		int next = arr[current][i];
		
		ref[next]--;
		if (ref[next] == 0)
		{
			ref[next] = -1;
			q.push(next);
		}
	}
	
}
int main()
{
	int n, m;
	cin >> n >> m;
	static vector<vector<int>> arr(n);
	static vector<int> ref(n,0);
	for (int i = 0; i < m; i++)
	{
		int cnt;
		cin >> cnt;
		int pre = -1;
		int next;
		for (int j = 0; j < cnt; j++)
		{
			cin >> next;
			next--;
			if (pre == -1)
			{
				pre = next;
				continue;
			}
			arr[pre].push_back(next);
			ref[next]++;
			pre = next;
		}
	}
	static queue<int> q;
	for (int i = 0; i < n; i++)
	{
		if (ref[i] == 0)
		{
			q.push(i);
			ref[i] = -1;
		}
	}
	while (q.empty() == false)
		f(q,arr,ref);
	if (ans.size() != n)
		cout << "0";
	else
	{
		for (auto a : ans)
		{
			cout << a+1<<"\n";
		}
	}
}