#include<stdio.h>
int main()
{
	int t,r,i;
	char str[20];
	scanf("%d", &t);
	while (t--)
	{
		i = 0;
		scanf(" %d %s", &r, str);
		while (str[i] != '\0')
		{
			for (int j = 0; j < r; j++)
				putchar(str[i]);
			i++;
		}
		putchar('\n');
	}
}

