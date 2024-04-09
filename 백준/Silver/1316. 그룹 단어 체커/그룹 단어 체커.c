#include<stdio.h>
int is_group(char* str);
int main()
{
	int num,count=0;
	scanf("%d", &num);
	char str[101];
	while (num--)
	{
		scanf("%s", str);
		if (is_group(str))
			count++;
	}
	printf("%d", count);
}
int is_group(char* str)
{
	int abc[26] = { 0 };
	char ing = str[0];
	abc[str[0] - 'a'] = 1;
	int i = 0;
	while (str[++i])
	{
		if (ing == str[i])
			continue;
		else
		{
			if (abc[str[i] - 'a'] == 1)
				return 0;
			else
			{
				ing = str[i];
				abc[str[i] - 'a'] = 1;
			}
		}
	}
	return 1;
}