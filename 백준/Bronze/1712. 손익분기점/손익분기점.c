#include<stdio.h>
int main()
{
	int a, b, c,d;
	scanf("%d%d%d", &a, &b, &c);
	if(c<=b)
	{
		printf("%d",-1);
		return 0;
	}
	a = a / (c - b);
	b = 1;
	while (1)
	{
		if (a < b)
			break;
		b++;
	}
	printf("%d", b);
}