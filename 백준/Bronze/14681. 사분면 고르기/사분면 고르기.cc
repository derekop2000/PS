#include <stdio.h>
int main()
{
	int x, y,a;
	scanf("%d\n%d", &x, &y);
	if (x > 0 && y > 0)
		a = 1;
	else if (x > 0 && y < 0)
		a = 4;
	else if (x < 0 && y>0)
		a = 2;
	else a = 3;
	printf("%d", a);
}