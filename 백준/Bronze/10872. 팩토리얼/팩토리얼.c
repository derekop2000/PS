#include <stdio.h>
int fac(int n)
{
	if (n == 1)
		return 1;
	else
		return n * fac(n - 1);
}
int main()
{
	int n;
	scanf("%d", &n);
	if (n == 0)
		putchar('1');
	else
	printf("%d", fac(n));
}
