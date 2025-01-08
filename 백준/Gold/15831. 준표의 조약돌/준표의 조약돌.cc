#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n, b, w;
	cin >> n >> b >> w;
	bool isBlack[300000];
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		if (c == 'B')
			isBlack[i] = true;
		else isBlack[i] = false;
	}
	int l = 0, r = -1,bCnt=0,wCnt=0,ans=0;
	
	while (true)
	{
		if(r == n-1)
			break;
		r++;
		if (isBlack[r]==true)
		{
			bCnt++;
			if (bCnt > b)
			{
				while (isBlack[l] == false)
				{
					l++;
					wCnt--;
				}
				bCnt--;
				if (l < n - 1)
				{
					l++;
				}
			}
		}
		else
		{
			wCnt++;
		}
		if (wCnt >= w)
		{
			ans = max(ans, bCnt + wCnt);
		}
	}
	cout << ans;
}
