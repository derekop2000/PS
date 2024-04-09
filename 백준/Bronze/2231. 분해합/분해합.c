#include <stdio.h>
int main()
{
	int n,sum=0,i,tempi;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("0");
		return 0;
	}
	for (i = n / 2; i < n; i++)
	{
		tempi = i;
		sum = tempi;
		while (tempi > 9)
		{
			sum += tempi % 10;
			tempi /= 10;
		}
		sum += tempi;
		if (sum == n)
			break;
	}
	if (i == n)
		printf("0");
	else printf("%d", i);
}
