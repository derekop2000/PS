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
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		b.push_back(temp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long int ans1 = 0,  ans2 = 0, ans3 = 0;
	for (int i = 0; i < n; i++)
	{
		int temp = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		ans1 += temp;
		if (temp == b.size())
			continue;
		int temp2 = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
		ans2 += temp2 - temp;
		if (temp2 == b.size())
			continue;
		ans3 += b.size() - temp2;
	}
	cout << ans1 << " " << ans3 << " " << ans2;
}
