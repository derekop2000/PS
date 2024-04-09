#include <stdio.h>

int main()
{
	int temp,max,count=1;
	scanf("%d", &max);
	for (int i = 0; i < 8; i++)
	{
		scanf(" %d", &temp);
		if (temp > max)
		{
			max = temp;
			count = i + 2;
		}
	}
	printf("%d\n%d", max, count);
}