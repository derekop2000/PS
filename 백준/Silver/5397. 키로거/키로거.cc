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

int dir[][2] = { {-1,0}, {0,1}, {1,0} ,{0,-1} };

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
	char c;
	Node* next= nullptr;
	Node* pre = nullptr;
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		Node* head = new Node;
		head->c = 18;
		Node* pos=head;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '<')
			{
				if (pos != head)
					pos = pos->pre;
			}
			else if (s[i] == '>')
			{
				if (pos->next)
					pos = pos->next;
			}
			else if (s[i] == '-')
			{
				if (pos != head)
				{
					pos->pre->next = pos->next;
					if (pos->next)
						pos->next->pre = pos->pre;
					Node* ppre = pos->pre;
					delete pos;
					pos = ppre;
				}
			}
			else
			{
				Node* node = new Node;
				node->c = s[i];
				node->next = pos->next;
				node->pre = pos;
				if(node->next)
					node->next->pre = node;
				pos->next = node;

				pos = pos->next;
			}
		}
		pos = head->next;
		while (pos)
		{
			cout << pos->c;
			pos = pos->next;
		}
		cout << "\n";
	}
}

