#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<bool> visit(100001,false);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int l = 0;
	int r = 0;
	visit[v[r]] = true;
	unsigned long long int ans = 0;
	while (true)
	{
		if (r < n - 1)
		{
			if (visit[v[r + 1]])
			{
				if (r == l)
				{
					ans++;
					l++;
					r++;
				}
				else
				{
					ans += r - l + 1;
					visit[v[l]] = false;
					l++;
				}
			}
			else
			{
				r++;
				visit[v[r]] = true;
			}
		}
		else
		{
			if (l < n)
			{
				ans += r - l + 1;
				l++;
			}
			else break;
		}
	}
	cout << ans;
}