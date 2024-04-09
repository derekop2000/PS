#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;

int dir1[] = {-1,0,1,0};
int dir2[] = {0,1,0,-1};

vector<vector<char>> v;
vector<pair<int, int>> students;
int n;
bool f(pair<int, int> t1, pair<int, int> t2, pair<int, int> t3)
{
	for (int i = 0; i < students.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			pair<int, int> c_p = make_pair(students[i].first, students[i].second);
			while (true)
			{
				c_p.first += dir1[j];
				c_p.second += dir2[j];
				if (0 <= c_p.first && c_p.first < n && 0 <= c_p.second && c_p.second < n)
				{
					if (c_p == t1 || c_p == t2 || c_p == t3)break;
					if (v[c_p.first][c_p.second] == 'T')return false;
				}
				else break;
			}
		}
	}
	return true;
}
int main()
{
	cin >> n;
	bool ans = false;
	v.resize(n, vector<char>(n));
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			char temp;
			cin >> temp;
			v[i][j] = temp;
			if (temp == 'S')students.push_back(make_pair(i, j));
		}
	for(int i=0;i<n*n;i++)
		for (int j = i+1; j < n * n; j++)
			for (int q = j+1; q < n * n; q++)
			{
				if (v[i / n][i % n] == 'X' && v[j / n][j % n] == 'X' && v[q / n][q % n] == 'X')
				{
					if (f(make_pair(i / n, i % n), make_pair(j / n, j % n), make_pair(q / n, q % n)))
					{
						ans = true;
					}
				}
			}
	if (ans)cout << "YES";
	else cout << "NO";
}