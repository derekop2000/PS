#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end(),greater<int>());
	priority_queue<int,vector<int>,greater<int>> q;
	int index = 0;
	int time = 0;
	while (true)
	{
		while (q.size() < m)
		{
			if (index == n)
				break;
			q.push(arr[index]);
			++index;
		}
		if (q.size() == 0)
			break;
		int top = q.top(); q.pop();
		vector<int> temp(q.size());
		while (q.empty() == false)
		{
			temp.push_back(q.top()); q.pop();
		}
		for (auto& current : temp)
		{
			current -= top;
			if (current > 0)
				q.push(current);
		}
		time += top;
	}
	cout << time;
}