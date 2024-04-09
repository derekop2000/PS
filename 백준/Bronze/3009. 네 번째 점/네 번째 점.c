#include <stdio.h>
int main()
{
	int x1, x2, y1, y2,x,y;
	scanf("%d%d%d%d%d%d", &x1, &y1,&x2,&y2,&x,&y);
	if (x1 != x2)
		if (x2 == x)
			x = x1;
		else if (x1 == x)
			x = x2;
	if (y1 != y2)
		if (y2 == y)
			y = y1;
		else if (y1 == y)
			y = y2;
	printf("%d %d", x, y);
}