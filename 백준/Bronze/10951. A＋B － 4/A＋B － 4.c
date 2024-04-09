#include <stdio.h>
int main()
{
	int a, b;
	while(1)
	{
		
		if (EOF == scanf("%d %d", &a, &b))
			break;
		printf("%d\n", a + b);
	}
}