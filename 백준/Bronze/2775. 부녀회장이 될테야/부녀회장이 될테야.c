#include<stdio.h>
int main()
{
	int arr[15][14];
	for (int i = 0; i < 14; i++)
		arr[0][i] = i+1;
	for (int i = 1; i < 15; i++)
		arr[i][0] = 1;
	for (int i = 1; i < 15; i++)
		for (int j = 1; j < 14; j++)
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
	int t, k, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &k, &n);
		printf("%d\n", arr[k][n - 1]);
	}
}