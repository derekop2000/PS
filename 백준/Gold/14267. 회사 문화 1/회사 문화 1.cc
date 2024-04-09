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

using namespace std;

vector<vector<int>> arr;
vector<int> point;
int n, m;
void f(int a, int b)
{
	point[a] += b;
	for (int i = 0; i<arr[a].size(); i++)
	{
		f(arr[a][i], point[a]);
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	arr.resize(n+1);
	point.resize(n + 1, 0);
	int temp;
	cin >> temp;
	for (int i = 2; i <= n ;i++)
	{
		cin >> temp;
		arr[temp].push_back(i);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		point[a] += b;
	}
	f(1, 0);
	for (int i = 1; i <= n; i++)
		cout << point[i] << " ";
}