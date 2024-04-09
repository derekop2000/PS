#include<stdio.h>
int main()
{
	int x=1,num,son,mom,sub;
	scanf("%d", &num);
	if (num == 1)
	{
		printf("%d/%d", 1, 1);
		return 0;
	}
	while (1)
	{
		if (x*(x + 1) / 2 < num && num <= (x + 1)*(x + 2) / 2)
			break;
		else x++;
	}
	sub = num - x * (x + 1) / 2;
	if ((x + 1) % 2 == 0)
	{
		son = sub; mom = x + 1 - sub + 1;
	}
	else { son = x + 1 - sub + 1; mom = sub; }
	printf("%d/%d", son, mom);
}