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
	int num;
	Node* next;
	Node* previous;
};

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
	vector<Node*> arr(1000001,nullptr);
	int n, m;
	cin >> n >> m;
	Node* first=nullptr;
	Node* now=nullptr;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		Node* node = new Node();
		node->num = num;
		arr[num] = node;
		if (first == nullptr)
			first = node;
		if (now != nullptr)
		{
			node->previous = now;
			now->next = node;
		}
		if (i == n - 1)
		{
			node->next = first;
			first->previous = node;
		}
		now = node;
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		int a;
		cin >> a;
		Node* p = arr[a];
		if (s == "BN")
		{
			int b;
			cin >> b;
			cout << p->next->num << "\n";
			Node* temp = new Node();
			arr[b] = temp;
			temp->num = b;
			temp->next = p->next;
			p->next->previous = temp;
			p->next = temp;
			temp->previous = p;
		}
		else if (s == "BP")
		{
			int b;
			cin >> b;
			cout << p->previous->num << "\n";
			Node* temp = new Node();
			arr[b] = temp;
			temp->num = b;
			p->previous->next = temp;
			temp->previous = p->previous;
			temp->next = p;
			p->previous = temp;
		}
		else if (s == "CN")
		{
			Node* temp = p->next;
			cout << temp->num << "\n";
			p->next = temp->next;
			temp->next-> previous = p;
			arr[temp->num] = nullptr;
			free(temp);
		}
		else
		{
			Node* temp = p->previous;
			cout << temp->num << "\n";
			p->previous = temp->previous;
			temp->previous->next = p;
			arr[temp->num] = nullptr;
			free(temp);
		}
		
	}
}
