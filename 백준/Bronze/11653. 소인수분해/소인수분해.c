#include<stdio.h>
int main()
{
	int n,div=2;
	scanf("%d", &n);
	for(div;div*div<=n;div++)
	{
		if (n % div == 0)
		{
			n /= div;
			printf("%d\n", div);
			div--;
		}
	}
	if (n > 1)
		printf("%d",n);
}