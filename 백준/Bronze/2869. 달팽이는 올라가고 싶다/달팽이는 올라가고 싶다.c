#include<stdio.h>
int main()
{
	int a, b, v;
	scanf("%d%d%d", &a, &b,&v);
	double x = (double)(v - a) / (a - b);
	if (x - (int)x == 0)
		printf("%d", (int)x+1);
	else printf("%d", (int)x+2);
}