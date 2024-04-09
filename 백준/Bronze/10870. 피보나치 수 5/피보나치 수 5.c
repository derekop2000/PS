#include <stdio.h>
int main()
{
	int arr[21] = { 0,1 };
	int i;
	for (i = 1; i < 19; i++)
	{
		arr[i + 1] += arr[i];
		arr[i + 2] += arr[i];
	}
	arr[20] += arr[19];
	scanf("%d", &i);
	printf("%d", arr[i]);
}
