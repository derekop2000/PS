#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num, count = 0, score = 0;
	scanf("%d", &num);
	int* pscore = (int*)malloc(sizeof(int) * num);
	char line[80];
	char* p = line;
	for (int i = 0; i < num; i++)
	{
		scanf("%s", &line);
		while (*p != '\0')
		{
			if (*p == 'O')
				score += ++count;
			else count = 0;
			p++;
		}
		p = line;
		pscore[i] = score;
		score = 0;
		count = 0;
	}
	for (int i = 0; i < num; i++)
		printf("%d\n", pscore[i]);
	free(pscore);
}