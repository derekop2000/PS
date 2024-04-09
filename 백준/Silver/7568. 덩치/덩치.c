#include <stdio.h>
int main()
{
	int a[50][2];
	int n,i,j,rank;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i][0], &a[i][1]);
	}
	for (i = 0; i < n; i++)
	{
		rank = 1;
		for (j = 0; j < n; j++)
			if (a[i][0] < a[j][0] && a[i][1] < a[j][1])++rank;
		printf("%d ", rank);
	}

}
