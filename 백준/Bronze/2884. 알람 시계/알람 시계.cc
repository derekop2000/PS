#include <stdio.h>
int main()
{
	int H, M;
	scanf("%d %d", &H, &M);
	if (M < 45)
		H = (H + 23) % 24;
	printf("%d %d", H, (M + 15) % 60);
}