#include <stdio.h>
int main()
{
	int unit = 1, a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	a = a * b * c;
	int arr[10] = { 0 };
	while (1)
	{
		if (a > unit)
		{
			b = a / unit;
			b = b % 10;
			unit *= 10;
			arr[b]++;
		}
		else break;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
}