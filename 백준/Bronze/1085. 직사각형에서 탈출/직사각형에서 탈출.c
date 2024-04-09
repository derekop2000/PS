#include <stdio.h>
int main()
{
	int x, y, w, h,a;
	scanf("%d%d%d%d", &x, &y, &w, &h);
	a = h - y;
	if (a > w - x)
		a = w - x;
	if (a > y)
		a = y;
	if (a > x)
		a = x;
	printf("%d", a);
}