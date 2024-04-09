#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool f(int& a, int& b)
{
	return a < b;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), f);
	int l = 0;
	int r = n - 1;
	int ans = 2000000000;
	int ans_l = 0;
	int ans_r = n - 1;
	while (l!=r)
	{
		if (abs(v[l] + v[r]) == 0) { ans_l = l; ans_r = r; break; }
		if (abs(ans) > abs(v[l] + v[r]))
		{
			ans = v[l] + v[r];
			ans_l = l;
			ans_r = r;
		}
		if (abs(v[l]) < abs(v[r]))
			r--;
		else l++;
	}
	cout << v[ans_l] << " " << v[ans_r];
}