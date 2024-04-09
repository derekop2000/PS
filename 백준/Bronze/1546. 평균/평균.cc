#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,max=0;
	double avg=0;
	scanf("%d", &n);
	int* p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %d", p + i);
		if (*(p + i) > max)
			max = *(p + i);
		avg += *(p + i);
	}
	avg = avg / max * 100 / n;
	printf("%.5lf", avg);
	free(p);
}