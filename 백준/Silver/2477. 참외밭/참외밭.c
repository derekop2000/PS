#include<stdio.h>
int main()
{
	
	int n;
	scanf(" %d", &n);
	int list[6][2];
	for (int i = 0; i < 6; i++)
		scanf(" %d %d", &list[i][0], &list[i][1]);
	int list2[5] = {0};
	for (int i = 0; i < 6; i++)
		list2[list[i][0]]++;
	int a=0, b=0;
	for (int i = 1; i < 5; i++)
		if (list2[i] == 2)
		{
			if (a == 0)
				a = i;
			else b = i;
		}
	int s=0;
	while (list[s][0] == a || list[s][0] == b)
	{
		s = (s + 1) % 6;
	}
	while (list[s][0] != a && list[s][0] != b)
	{
		s = (s + 1) % 6;
	}

	printf("%d", n * (list[(s + 5) % 6][1] * list[(s + 4) % 6][1] - list[(s + 1) % 6][1] * list[(s + 2) % 6][1]));
	
}