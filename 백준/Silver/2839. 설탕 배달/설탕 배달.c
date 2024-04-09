#include<stdio.h>
int main()
{
	int x, y=-1, n;
	scanf("%d", &n);
	x = n / 5;
	while (x>=0)
	{
		if ((n - 5 * x) % 3 == 0)
		{
			y = (n - 5 * x) / 3;
			break;
		}
		else
			x--;
	}
	if (y == -1)
		printf("-1");
	else
		printf("%d",x+y);
	
}