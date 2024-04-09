#include <stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		for (int j = t-i; j>0; j--)
			putchar(' ');
		for (int u = 1; u <= i; u++)
			putchar('*');
		putchar('\n');
	}
	
		
}