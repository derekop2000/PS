#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct compare
{
	bool operator()(long long int& a,long long int& b)
	{
		return a > b;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		priority_queue<long long int, vector<long long int>, compare> q;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			q.push(temp);
		}
		long long int ans = 0;
		for (int i = 0; i < n - 1; i++)
		{
			long long int temp;
			temp = q.top();
			q.pop();
			temp += q.top();
			q.pop();
			ans += temp;
			q.push(temp);
		}
		cout << ans << "\n";
	}
}