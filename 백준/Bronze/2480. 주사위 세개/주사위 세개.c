#include <stdio.h>
int main()
{
	int a[3];
	scanf("%d %d %d", a, a + 1, a + 2);
	if (a[0]==a[1]&&a[1]==a[2]&&a[0]==a[2])
		printf("%d", 10000 + a[0] * 1000);
	else if ((a[0] ^ a[1]) == 0 || (a[1] ^ a[2]) == 0 || (a[0] ^ a[2]) == 0)
		printf("%d", (a[0] + a[1] + a[2] - (a[0] ^ a[1] ^ a[2])) * 50 + 1000);
	else if (a[0] > a[1] && a[0] > a[2])
		printf("%d", a[0] * 100);
	else if (a[1] > a[0] && a[1] > a[2])
		printf("%d", a[1] * 100);
	else
		printf("%d", a[2] * 100);
}

