#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include<tuple>
using namespace std;

map<int, int> ratio;
int n;
vector<vector<char>>arr;
void draw(int i,int j)
{
	arr[i-1][j] = '*';
	arr[i][j-1] = '*';
	arr[i][j + 1] = '*';
	arr[i+1][j - 2] = '*';
	arr[i + 1][j - 1] = '*';
	arr[i + 1][j] = '*';
	arr[i + 1][j +1] = '*';
	arr[i + 1][j + 2] = '*';
}
void f(int _size,int i,int j)
{
	if (_size % 2 == 0)
	{
		f(_size / 2, i -(_size/2+1)/2, j);
		f(_size / 2, i +_size/2/2, j + (ratio[_size / 2] + 1) / 2);
		f(_size / 2, i + _size/2/2, j - (ratio[_size / 2] + 1) / 2);
	}
	else
	{
		draw(i, j);
	}
}
int main()
{
    ios_base::sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);
	cin >> n;
	ratio.insert({ 3,5 });
	int last_vertical = 3;
	int last_horizontal = 5;
	for (int i = 1; i < 11; i++)
	{
		last_vertical *= 2;
		last_horizontal = last_horizontal * 2 + 1;
		ratio.insert({ last_vertical, last_horizontal });
	}
	arr.resize(n, vector<char>(ratio[n],' '));
	f(n, n / 2, ratio[n] / 2);
	int j_max = ratio[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < j_max; j++)
		{
			cout << arr[i][j];
		}cout << "\n";
	}
}
