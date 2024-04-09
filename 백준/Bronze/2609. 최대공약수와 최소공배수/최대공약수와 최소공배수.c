#include<stdio.h>
int max(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;
	else
	{
		int c = a > b ? a : b;
		b = a ^ b ^ c;
		return max(c-b, b);
	}
}
int main()
{
	int a, b,c;
	scanf(" %d %d", &a, &b);
	c = max(a, b);
	printf("%d\n%d",c,a*b/c);
}