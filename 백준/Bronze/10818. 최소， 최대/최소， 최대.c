#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num,high,low;
	scanf("%d", &num);
	int* arr = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		scanf(" %d", &arr[i]);
	high = arr[0];
	low = arr[0];
	for (int i = 1; i < num; i++)
	{
		if (arr[i] > high)
			high = arr[i];
		if (arr[i] < low)
			low = arr[i];
	}
	printf("%d %d", low, high);
}