#include<stdio.h>
int main()
{
	int i = 0,k;
	char str[100];
	int abc[26];
	for (int j = 0; j < 26; j++)
		abc[j] = -1;
	scanf("%s", str);
	while (1)
	{
		k = str[i] - 'a';
		if (abc[k] == -1)
			abc[k] = i;
		i++;
		if (str[i] == '\0')
			break;
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", abc[i]);
}

