#include<iostream>
#include<vector>
#include<memory>
#include<math.h>
#include<algorithm>
#include<deque>
using namespace std;

int dir1[] = { -1,-1,-1,0,1,1,1,0 };
int dir2[] = { -1,0,1,1,1,0,-1,-1 };
int n, m, k;

vector<vector<int>> arr;
vector<vector<int>> energy;
vector<vector<deque<int>>> trees;
vector<vector<int>> dead;
void summer(int i, int j, int q);
void spring()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int q = 0; q < trees[i][j].size(); q++)
			{
				if (arr[i][j] >= trees[i][j][q])
				{
					arr[i][j] -= trees[i][j][q];
					trees[i][j][q]++;
				}
				else
				{
					summer(i, j, q);
					break;
				}
			}
		}
	}

}
void summer(int i,int j,int q)
{
	for (int s = trees[i][j].size()-1; s >= q; s--)
	{
		arr[i][j] += trees[i][j][s]/2;
	}
	for (int s = trees[i][j].size() - 1; s >=q; s--)
	{
		trees[i][j].pop_back();
	}
}
void fall()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int q = 0; q < trees[i][j].size(); q++)
			{
				if (trees[i][j][q] % 5 == 0)
				{
					for (int w = 0; w < 8; w++)
					{
						int ii = i + dir1[w];
						int jj = j + dir2[w];
						if (0 <= ii && ii < n && 0 <= jj && jj < n) {
							trees[ii][jj].push_front(1);
						}
					}
				}
			}
		}
	}
}

void winter()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] += energy[i][j];
		}
	}
}
void f()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			sort(trees[i][j].begin(), trees[i][j].end());
		}
	spring();
	fall();
	winter();
	for (int q = 1; q < k; q++)
	{
		spring();
		fall();
		winter();
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	arr.resize(n, vector<int>(n, 5));
	energy.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> energy[i][j];
		}
	trees.resize(n, vector<deque<int>>(n));
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		trees[x - 1][y - 1].push_back(z);
	}
	f();
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer += trees[i][j].size();
		}
	}
	cout << answer;
	return 0;
}
