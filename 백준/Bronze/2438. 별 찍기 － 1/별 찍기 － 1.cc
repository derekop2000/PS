#include <stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		for (int j = 0; j < i; j++)
			putchar('*');
		putchar('\n');
	}
	
			
}