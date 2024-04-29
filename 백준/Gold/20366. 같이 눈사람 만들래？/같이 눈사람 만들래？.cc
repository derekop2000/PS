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
using namespace std;


struct node
{
	int data;
	int index1, index2;
};
bool f(node& n1, node& n2)
{
	return n1.data < n2.data;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	vector<node> vv;
	for(int i=0;i<n;i++)
		for (int j = i + 1; j < n; j++)
		{
			vv.push_back(node{ v[i]+v[j],i,j});
		}
	sort(vv.begin(), vv.end(),f);
	int ans = INT_MAX;
	
	for(int i=0;i<vv.size();i++)
	{
		for (int j = i + 1; j < vv.size(); j++)
		{
			if (vv[i].index1 == vv[j].index1 || vv[i].index1 == vv[j].index2 || vv[i].index2 == vv[j].index1 || vv[i].index2 == vv[j].index2)
			{
				continue;
			}
			else
			{
				ans = min(ans, abs(vv[i].data - vv[j].data));
				break;
			}
		}
	}
	cout << ans;
}