#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int findParent(int a);
int v, e;
vector<int> parent;
vector<vector<int>> arr;
void union_(int a,int b)
{
	int aa = findParent(a);
	int bb = findParent(b);
	if (aa < bb) parent[bb] = aa;
	else parent[aa] = bb;
}
int findParent(int a)
{
	if (parent[a] == a)return a;
	else return parent[a] = findParent(parent[a]);
}
bool isUnion(int a, int b)
{
	if (findParent(a) == findParent(b))return true;
	else return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> v >> e;
	parent.resize(v);
	arr.resize(e, vector<int>(3));
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		arr[i][0] = c;
		arr[i][1] = a;
		arr[i][2] = b;
	}
	sort(arr.begin(), arr.end(), less<vector<int>>());
	int cnt = 0;
	int index = 0;
	int ans = 0;
	for (int i = 0; i < v; i++)
		parent[i] = i;

	while (cnt < v - 1)
	{
		if (isUnion(arr[index][1], arr[index][2]))
		{
			index++;
			//if (index >= v) { cout << "index over!"; break; }
		}
		else
		{
			union_(arr[index][1], arr[index][2]);
			cnt++;
			ans += arr[index][0];
			index++;
			//if (index >= v) { cout << "index over!"; break; }
		}

	}
	cout << ans;
}

