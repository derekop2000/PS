#include<stdio.h>
#include<ctype.h>
int main()
{
	char str[1000000];
	scanf("%s", str);
	int abc[26] = {0};
	for (int i = 0;; i++)
	{
		if (str[i] == '\0')
			break;
		abc[tolower(str[i]) - 'a']++;
	}
	int count = 0,same=0;
	for (int i = 1; i < 26; i++)
	{	
		if (abc[i] == abc[count])
			same = 1;
		if (abc[i] > abc[count])
		{
			count = i;
			same = 0;
		}
	}
	if (same == 1)
		putchar('?');
	else putchar(count+'A');
}