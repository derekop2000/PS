#include<stdio.h>
int main()
{
	int m, n,sum=0,min,TF=1;
	scanf("%d %d", &m, &n);
	if (m == 1)
		m++;
	for (int i = n; i >= m; i--)
	{
		for (int j = 2; j <= i / 2; j++)
			if (i % j == 0)
			{
				TF = 0;
				break;
			}
		if (TF == 1)
		{
			sum += i;
			min = i;
		}
		TF = 1;
	}
	if (sum == 0)
		printf("-1");
	else printf("%d\n%d", sum, min);

}