#include <stdio.h>
int main()
{
	int n, k, w, v, i, j;
	scanf("%d %d", &n, &k);
	int arr[100001];
	scanf("%d %d", &w, &v);
	if (w > k)
		for (i = 0; i < k+1; i++)
			arr[i] = 0;
	else
	{
		for (i = 0; i < w ; i++)
			arr[i] = 0;
		for (; i < k+1; i++)
			arr[i] = v;
	}
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &w, &v);
		for (j = k ; j >= w ; j--)
			arr[j] = (arr[j - w ] + v) > arr[j] ? (arr[j - w] + v) : arr[j];
	}
	printf("%d", arr[k]);
}