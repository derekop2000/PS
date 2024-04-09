#include<iostream>
#include<vector>
#include<memory>
#include<math.h>
using namespace std;

vector<vector<int>> arr;
vector<vector<int>> home;
vector<vector<int>> chicken;
vector<int> survey;
int n, m;
int ans = 200000000;
int calc(int a,int b)
{
	int aa = home[a][0] - chicken[survey[b]][0];
	int bb = home[a][1] - chicken[survey[b]][1];
	if (aa < 0)aa *= -1;
	if (bb < 0)bb *= -1;
	return aa + bb;
}
void f2()
{
	int temp_ans = 0;
	for (int i = 0; i < home.size(); i++)
	{
		int chicken_street = 200000000;
		for (int j = 0; j < m; j++)
		{
			int temp = calc(i, j);
			if (chicken_street > temp)
			chicken_street = temp;
		}
		temp_ans += chicken_street;
	}
	if (temp_ans < ans)ans = temp_ans;
}
void f(int floor)
{
	if (survey.size() == m)
	{
		f2();
		return;
	}
	for (int i = floor; i < chicken.size(); i++)
	{
		survey.push_back(i);
		f(i + 1);
		survey.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	arr.resize(n, vector<int>(n));
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				home.push_back(vector<int>());
				home[home.size() - 1].push_back(i);
				home[home.size() - 1].push_back(j);
			}
			else if (arr[i][j] == 2)
			{
				chicken.push_back(vector<int>());
				chicken[chicken.size() - 1].push_back(i);
				chicken[chicken.size() - 1].push_back(j);
			}
		}
	f(0);
	cout << ans;
}
