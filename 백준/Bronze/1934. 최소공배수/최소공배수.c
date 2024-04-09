#include<stdio.h>
int min(a, b)
{
	if (b > a)
	{
		b = b ^ a;
		a = b ^ a;
		b = b ^ a;
	}
	while (b!=0)
	{
		a = a - (a / b * b);
		b = b ^ a;
		a = b ^ a;
		b = b ^ a;
	}
	return a;
}
int main()
{
	int t, a, b;
	scanf(" %d", &t);
	while (t--)
	{
		scanf(" %d %d", &a, &b);
		printf("%d\n", a / min(a, b) * b);
	}
}