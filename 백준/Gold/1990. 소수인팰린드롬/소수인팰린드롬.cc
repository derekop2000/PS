#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
#include<string>
using namespace std;

bool f(int num)
{
	string str = to_string(num);
	int str_size = str.size();
	for (int i = 0; i < str_size / 2; i++)
	{
		if (str[i] != str[str_size - 1 - i])return false;
	}
	return true;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	vector<bool> arr(b+1,true);
	arr[0] = false;
	arr[1] = false;
	for (int i = 0; i * i <= b; i++)
	{
		if(arr[i])
			for (int j = i * 2; j <= b; j += i)
			{
				arr[j] = false;
			}
	}
	for (int i = a; i <=b; i++)
	{
		if (arr[i] && f(i))
			cout << i << "\n";
	}
	cout << "-1";
}
  
