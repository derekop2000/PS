#include <stdio.h>
#include<math.h>
int main()
{
	int x1, y1, r1, x2, y2, r2,t;
	double a;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
		a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		if (a == 0 && r1 == r2)
			printf("-1\n");
		else if (a > r1 + r2)
			printf("0\n");
		else if (abs(r1 - r2) > a)
			printf("0\n");
		else if (a == r1 + r2)
			printf("1\n");
		else if (abs(r1 - r2) == a)
			printf("1\n");
		else printf("2\n");
	}
}