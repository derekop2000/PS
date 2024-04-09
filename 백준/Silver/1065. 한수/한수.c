#include<stdio.h>
int is_hansu(int num);
int main()
{
	int x,count=0;
	scanf("%d", &x);
	if (x < 100)
	{
		printf("%d", x);
		return 0;
	}
	else for (int i = 111; i <= x; i++)
		if (is_hansu(i) == 1)
			count++;
	printf("%d", count + 99);
	return 0;
}
int is_hansu(int num)
{
	int sub, a, b,first_sub;
	a = num / 10 % 10;
	b = num % 10;
	first_sub = b - a;
	while (num > 9)
	{
		a = num / 10 % 10;
		b = num % 10;
		sub = b-a;
		if (first_sub != sub)
			return 0;
		num /= 10;
	}
	return 1;
}
