#include<stdio.h>
int main()
{
	int num,a, b=1,circle=1;
	scanf("%d", &num);
	if (num == 1)
	{
		printf("1");
		return 0;
	}
	while (1)
	{
		a = b + 1;
		b = circle * 6 - 1+a;
		if (a <= num && num <= b)
			break;
		circle++;
	}
	printf("%d", circle+1);
}