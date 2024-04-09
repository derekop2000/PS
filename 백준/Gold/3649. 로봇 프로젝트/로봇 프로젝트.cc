#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include <iomanip>
#include<climits>
#include<sstream>
#include<deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	while (cin >> n)
	{
		n *= 10000000;
		int m;
		cin >> m;
		vector<int> v(m);
		for (int i = 0; i < m; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int a = -1;
		int b = -1;
		for (int i = 0; i < m-1; i++)
		{
			int idx = lower_bound(v.begin(), v.end(), n-v[i]) - v.begin();
			if (i == idx)
			{
				if (!(idx + 1 < v.size() && v[idx] == v[idx + 1]))continue;
			}
			if (idx < v.size() && v[idx] == n - v[i])
			{
				a = i; b = idx;
				break;
			}
		}
		if (a != -1)
			cout << "yes " << v[a] << " " << v[b] << "\n";
		else cout << "danger\n";
	}
}