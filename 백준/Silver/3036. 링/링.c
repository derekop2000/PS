#include<stdio.h>
int max(int a, int b)
{

	if (a == 0 || b == 0)
		return a + b;
	else
	{
		if (b > a)
		{
			a = a ^ b;
			b = a ^ b;
			a = b ^ a;
		}
		int temp = a % b;
		return max(b, temp);
	}
}
int main()
{
	int n,first,temp,temp2;
	scanf(" %d", &n);
	scanf(" %d", &first);
	n--;
	while (n--)
	{
		scanf(" %d", &temp);
		temp2 = max(first, temp);
		printf("%d/%d\n", first / temp2, temp / temp2);
	}
}