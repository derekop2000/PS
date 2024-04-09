#include <stdio.h>
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (b + c % 60 > 59)
	{
		a++;
		a += c / 60;
		b = (b + c % 60) % 60;
	}
	else
	{
		a += c / 60;
		b += c % 60;
	}
	printf("%d %d", a%24, b);
	
}

