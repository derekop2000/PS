#include<iostream>
#include<vector>
#include<memory>
#include<math.h>
using namespace std;
int currentStandard[4] = { 0,0,0,0 }; // 시계 방향 -1 반시계 +1
vector<vector<int>> arr; // standard +6 && +2
vector<pair<int, int>> todo;
bool visit[4];
// visit 초기화 todo초기화 
void f(int index, int IsClock)
{
	todo.push_back(make_pair(index, IsClock));
	visit[index] = true;
	int new_index = index - 1;
	if (0 <= new_index && new_index <= 3 && !visit[new_index] && arr[new_index][(currentStandard[new_index] + 2) % 8] != arr[index][(currentStandard[index] + 6) % 8])
	{
		f(new_index, IsClock * -1);
	}
	new_index = index + 1;
	if (0 <= new_index && new_index <= 3 && !visit[new_index] && arr[index][(currentStandard[index] + 2) % 8] != arr[new_index][(currentStandard[new_index] + 6) % 8])
	{
		f(new_index, IsClock * -1);
	}
	
}
void setDo()
{
	for (int i = 0; i < todo.size(); i++)
	{
		if (todo[i].second == 1)
		{
			currentStandard[todo[i].first] = (currentStandard[todo[i].first] + 7) % 8;
		}
		else
		{
			currentStandard[todo[i].first] = (currentStandard[todo[i].first] + 1) % 8;
		}
	}
}
int main()
{
	arr.resize(4, vector<int>(8,0));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char temp_char;
			cin >> temp_char;
			if (temp_char == '1')
				arr[i][j] = 1;
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		
		for (int i = 0; i < 4; i++)
			visit[i] = false;
		todo.clear();
		f(a-1, b);
		setDo();
	}
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		if (arr[i][currentStandard[i]] == 1)
		{
			ans += pow(2, i);
		}
	}
	cout << ans;
}
