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
#include<stack>
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

struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
};

int main()
{
	vector<int> v;
	int temp;
	while (cin >> temp)
	{
		v.push_back(temp);
	}
	
	Node* root = new Node{};
	Node* p = root;
	root->value = v[0];
	int top = v[0];
	for (int i = 1; i < v.size(); i++) {
		int now = v[i];
		Node* newNode = new Node{};
		newNode->value = now;

		while (true) {
			if (now < p->value)
			{
				if (p->left == nullptr)
				{
					p->left = newNode;
					newNode->parent = p;
					p = root;
					break;
				}
				p = p->left;
			}
			else
			{
				if (p->right == nullptr)
				{
					p->right = newNode;
					newNode->parent = p;
					p = root;
					break;
				}
				p = p->right;
			}
		}
	}
	p = root;
	while (true)
	{
		if (p->left == nullptr)
		{
			if (p->right == nullptr)
			{
				cout << p->value << "\n";
				if (p == root)
					break;
				p = p->parent;
				if (p->left)
				{
					free(p->left);
					p->left = nullptr;
					continue;
				}
				if (p->right)
				{
					free(p->right);
					p->right = nullptr;
				}
			}
			else
				p = p->right;
		}
		else
			p = p->left;
	}
}