#include<stdio.h>
#include<stdlib.h>
int main()
{
	int c, student, count;
	float avg;
	int* p;
	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		avg = 0;
		count = 0;
		scanf(" %d", &student);
		p = (int*)malloc(sizeof(int) * student);
		for (int j = 0; j < student; j++)
		{
			scanf(" %d", p + j);
			avg += *(p + j);
		}
		avg = avg / student;
		for (int h = 0; h < student; h++)
			if (*(p + h) > avg)
				count++;
		printf("%.3f%%\n",(float)count/(float)student*100);
	}
}