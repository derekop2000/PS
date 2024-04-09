#include <stdio.h>
int main()
{
	int a, b;
	scanf("%d%d",&a,&b);
	int v, s, e;
	v = (int)(b / 100);
	s = (int)((b - v*100) / 10);
	e = b - v*100 - s*10;
	printf("%d\n", a*e);
	printf("%d\n", a*s);
	printf("%d\n", a*v);
	printf("%d", a * b);
}