#include <stdio.h>
int main()
{
	int m, n, i, j;
	char nums[1000001] = {1, 1};
	scanf("%d %d", &m, &n);
	for (i = 2; i * i < n + 1; i++) 
		if(!nums[i])
			for (j = i * i; j < n+1; j += i)
				nums[j] = 1;
	for (i = m; i < n + 1; i++)
		if (!nums[i]) printf("%d\n", i);
	return 0;
}