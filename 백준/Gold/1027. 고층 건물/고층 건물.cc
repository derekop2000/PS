#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int ans = 0;
vector<int> v;
void f(int center)
{
	int cnt = 0;
	double gi = -1000000001;
	for (int i = center - 1; i >= 0; i--)
	{
		double temp = ((double)v[i] - v[center]) / (center - i);
		if (temp > gi)
		{
			cnt++;
			gi = temp;
		}
	}
	gi = -1000000001;
	for (int i = center + 1; i < n; i++)
	{
		double temp = ((double)v[i] - v[center]) / (i - center);
		if (temp > gi)
		{
			cnt++;
			gi = temp;
		}
	}
	ans = max(ans, cnt);
}
int main()
{
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
		f(i);
	cout << ans;
}