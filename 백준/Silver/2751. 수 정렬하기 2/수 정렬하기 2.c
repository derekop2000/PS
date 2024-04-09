#include<stdio.h>
#include<stdlib.h>
void merge(int* arr, int s, int mid, int e)
{
	int* temp = (int*)malloc(sizeof(int) * (e - s));
	int q = s, p = mid, w = 0;
	while (q < mid && p < e)
	{
		temp[w++] = arr[q] < arr[p] ? arr[q++] : arr[p++];
	}
	while (q < mid)
	{
		temp[w++] = arr[q++];
	}
	while (p < e)
	{
		temp[w++] = arr[p++];
	}
	w--;
	while (w > -1)
	{
		arr[s + w] = temp[w];
        w--;
	}
	free(temp);
}

void sort(int* arr, int s, int e)
{
	if (s < e - 1)
	{
		int mid = (s + e) / 2;
		sort(arr, s, mid);
		sort(arr, mid, e);
		merge(arr, s, mid, e);
	}
}
int main()
{
	int n,temp;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %d", &temp);
		arr[i] = temp;
	}
	sort(arr, 0, n);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	free(arr);
}