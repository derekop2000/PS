#include <stdio.h>
int main()
{
	int num, count=0,new_num;
	scanf("%d", &num);
	new_num = num;
	while (1)
	{
		if (new_num < 10)
			new_num = new_num * 11;
		else
			new_num = new_num % 10 * 10 + (new_num / 10 + new_num % 10) % 10;
		count += 1;
		if (num == new_num)
			break;
	}
	printf("%d", count);
}