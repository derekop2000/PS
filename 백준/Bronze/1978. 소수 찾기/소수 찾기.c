#include<stdio.h>
int main()
{
	int count, n, temp;
	scanf("%d", &n);
	count = n;
	while (n--)
	{
		scanf("%d", &temp);
		if (temp == 1)
			count--;
		for (int i = 2; i <= temp / 2; i++)
			if (temp % i == 0)
			{
				count--;
				break;
			}
	}
	printf("%d", count);
}