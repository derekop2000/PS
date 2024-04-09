#include<stdio.h>
int selfnum(int a);
int num[10000];
int main()
{
	for (int i = 1; i < 10000; i++)
		num[selfnum(i)] = 1;
	for (int i = 1; i < 10000; i++)
		if (num[i] == 0)
			printf("%d\n", i);
	return 0;
}
int selfnum(int a)
{
	int b = a;
	while (b)
	{
		a += b % 10;
		b /= 10;
	}
	return a;
}