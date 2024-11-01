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
#include <unordered_set>
using namespace std;

int dir[][2] = { {-1,0}, {0,1}, {1,0} ,{0,-1},{-1,1},{1,1},{1,-1},{-1,-1} };

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

struct Node
{
	vector<int> arr;
};
int root;
vector<Node*> arr;
int stop,n;
int f(int current)
{
	int size = arr[current]->arr.size();
	int sum = 0;
	bool stoped = false;
	for (int i = 0; i < size; i++)
	{
		int next = arr[current]->arr[i];
		if (next == stop)
		{
			stoped = true;
			continue;
		}
		sum += f(next);
	}
	if (stoped)
		size--;
	if (size == 0)
		sum = 1;
	return sum;
}
int main()
{
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		arr[i] = new Node{};
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp == -1)
			root = i;
		else
		{
			arr[temp]->arr.push_back(i);
		}
	}
	cin >> stop;
	stop;
	if (stop == root)
		cout << "0";
	else
		cout << f(root);
}
