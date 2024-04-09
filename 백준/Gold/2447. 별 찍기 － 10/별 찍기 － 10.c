#include <stdio.h>
char arr[2187][2187];
void star(int x, int y, int n);
int main()
{
	int n, x, y;
	scanf("%d", &n);
	star(0, 0, n);
	for (y= 0; y < n; y++)
	{
		for (x = 0; x < n; x++)
			arr[x][y] ? putchar(' ') : putchar('*');
		putchar('\n');
	}
}
void star(int x, int y, int n)
{
	int i,j;
	if(n>=3)
	for (i = n / 3; i < n / 3 * 2; i++)
		for (j = n / 3; j < n / 3 * 2; j++)
			arr[x+j][y+i] = 1;
	if (n >= 9)
	{
		for (i = 0; i < n; i += n / 3)
			for (j = 0; j < n; j += n / 3)
				star(j + x, i + y, n / 3);
	}
}