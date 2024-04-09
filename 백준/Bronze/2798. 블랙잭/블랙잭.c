#include <stdio.h>
int main()
{
	int n, m,sum,max=0,i,j,k;
	scanf("%d %d", &n, &m);
	int arr[100];
	for (i = 0; i < n; i++)
		scanf("%d", arr + i);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			for (k = j + 1; k < n; k++)
			{
				sum = arr[i] + arr[j] + arr[k];
				if (sum > max&& sum<m+1)
					max = sum;
			}
	printf("%d", max);
}
