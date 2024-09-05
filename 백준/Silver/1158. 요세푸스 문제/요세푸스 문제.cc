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
	int num;
	Node* next;
	Node* pre;
};
int main()
{
	int n, k;
	cin >> n >> k;
	Node first;
	first.num = 1;
	Node* p = &first;
	for (int i = 2; i <= n; i++)
	{
		Node* n = new Node{};
		n->num = i;
		n->pre = p;
		p->next = n;
		p = p->next;
	}
	first.pre = p;
	p->next = &first;
	cout << "<";
	if(n>1)
	while (true)
	{
		for (int i = 0; i < k; i++)
		{
			p = p->next;
		}
		cout << p->num<<", ";
		if (p->pre != p->next)
		{
			p->pre->next = p->next;
			p->next->pre = p->pre;
			p = p->pre;
		}
		else
		{
			break;
		}
	}
	p = p->next;
	cout << p->num<<">";
}

