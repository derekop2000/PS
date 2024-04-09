#include<stdio.h>
int main()
{
	int a,sum=0;
	char str[101];
	scanf("%d", &a);
	scanf("%s", &str);
	for (int i = 0; i < a; i++)
		sum += str[i] - '0';
	printf("%d", sum);
}

