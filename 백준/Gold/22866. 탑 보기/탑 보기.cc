#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<climits>
#include <functional>

using namespace std;

vector<int> parent;
int findParent(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = findParent(parent[a]);
}
void Union(int a, int b)
{
	parent[findParent(b)] = findParent(a);
}
bool IsUnion(int a, int b)
{
	return findParent(a) == findParent(b);
}

int f(vector<int>& buildTime, vector<vector<int>>& arr, vector<int>& dp, int v)
{
	if (dp[v] != -1)return dp[v];
	int reValue = buildTime[v];
	int bigValue = 0;
	for (int i = 0; i < arr[v].size(); i++)
	{
		bigValue = max(bigValue, f(buildTime, arr, dp, arr[v][i]));
	}
	dp[v] = reValue + bigValue;
	return reValue+bigValue;
}
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<pair<int, int>> info(n, {0,1000000});
	vector<pair<int,int>> stack;
	for (int i = 0; i < n; i++)
	{
		while (true)
		{
			if (stack.empty())
			{
				stack.push_back({ arr[i] ,i});
				break;
			}
			else
			{
				if (stack.back().first > arr[i])
				{
					info[i].first += stack.size();
					info[i].second = stack.back().second;
					
					stack.push_back({ arr[i],i });
					break;
				}
				else
				{
					stack.pop_back();
				}
			}
		}
	}
	stack.clear();
	for (int i = n-1; i >= 0; i--)
	{
		while (true)
		{
			if (stack.empty())
			{
				stack.push_back({ arr[i] ,i});
				break;
			}
			else
			{
				if (stack.back().first > arr[i])
				{
					info[i].first += stack.size();
					{
						int temp = abs(stack.back().second - i);
						if (temp < abs(info[i].second-i))
							info[i].second = stack.back().second;
					}
					stack.push_back({ arr[i] ,i});
					break;
				}
				else
				{
					stack.pop_back();
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (info[i].first == 0)
		{
			cout << "0\n";
		}
		else cout << info[i].first << " " << info[i].second+1 << "\n";
	}
}