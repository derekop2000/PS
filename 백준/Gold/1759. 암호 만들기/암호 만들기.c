#include<stdio.h>
char list[15];
char list_ans[15];
int l, c,ae,bc;
void f(int count,int q)
{
	if (count == l)
	{
		ae = 0; bc = 0;
		for (int h = 0; h < l; h++)
			if (list_ans[h] == 'a' || list_ans[h] == 'e' || list_ans[h] == 'i' || list_ans[h] == 'o' || list_ans[h] == 'u')
				ae++;
			else bc++;
		if (ae > 0 && bc > 1)
			printf("%s\n", list_ans);
	}
	else
	{
		for (int i = q; i < c; i++)
		{
			list_ans[count] = list[i];
			f(count+1, i+1);
		}
	}
}
int main()
{
	scanf(" %d %d", &l, &c);
	for (int i = 0; i < c; i++)
	{
		scanf(" %c", &list[i]);
	}
	for (int i = 0; i < c - 1; i++)
		for (int j = i + 1; j < c; j++)
		{
			if (list[i] > list[j])
			{
				list[i] = list[j] ^ list[i];
				list[j] = list[i] ^ list[j];
				list[i] = list[i] ^ list[j];
			}
		}
	f(0, 0);
}