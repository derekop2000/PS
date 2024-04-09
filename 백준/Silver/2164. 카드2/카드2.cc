#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		q.push(i);
	int cnt=n;
	int temp;
	while(cnt!=1)
	{
		q.pop();
		cnt--;
		temp = q.front();
		q.pop();
		q.push(temp);
	}
	cout << q.front();
}