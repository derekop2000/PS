#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int arr[10], count = 0, same = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf(" %d", arr+ i);
		arr[i] = arr[i] % 42;
		for (int j = 0; j <= i - 1;j++)
			if (arr[i] == arr[j])
				same = 1;
		if (same != 1)
			count++;
		same = 0;
	}
	printf("%d", count);
}