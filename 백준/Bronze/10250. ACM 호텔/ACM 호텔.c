#include<stdio.h>
int main()
{
	int t, h, w, n, a, b;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &h, &w, &n);
		a = (n % h)*100;
		if (a == 0)
			a = h*100;
		b = n / h+1;
		if (n % h == 0)
			b--;
		printf("%d\n",a+b);
	}
}