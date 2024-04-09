#include<stdio.h>
int main()
{
	char str[1000001];
	scanf("%[^\n]s", str);
	int count=0,i=0;
	if (isalpha(str[0]))
		count++;
	while (1)
	{
		if (str[++i] == '\0')
			break;
		if (str[i-1] == ' ' && isalpha(str[i]))
			count++;
	}
	printf("%d", count);
}