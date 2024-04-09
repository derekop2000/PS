#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int totlaFloor;
string ss;
string tt;
bool goal = false;
void f(int currentFloor, string s)
{
	if (goal)return;
	if (currentFloor == totlaFloor)
	{
		if (s.compare(ss) == 0) { goal = true; return; }
		else return;
	}
	if (s.back() == 'A')
	{
		f(currentFloor + 1, s.substr(0, s.size() - 1));
	}
	if (s.front() == 'B')
	{
		string temp = s.substr(1, s.size());
		reverse(temp.begin(), temp.end());
		f(currentFloor + 1, temp);
	}
}
int main()
{
	cin >> ss >> tt;
	totlaFloor = tt.size() - ss.size();
	f(0, tt);
	if (goal)
		cout << '1';
	else cout << '0';
}