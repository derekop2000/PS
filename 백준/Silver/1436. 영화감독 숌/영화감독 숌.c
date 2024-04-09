#include<stdio.h>
int main()
{int n,count=1,space=1,front,back,six_count,temp;
	scanf("%d",&n);
	if(n==1)
	{
		printf("666");
		return 0;
	}
	while(1)
	{
		for(front=space;front<space*10;front++)
		{
			six_count=0;
			if(front%10==6)
			{
				temp=front/10;
				six_count++;
				while(temp%10==6)
				{
					six_count*=10;
					temp/=10;
				}
				six_count*=10;
				for(back=0;back<six_count;back++)
				{
					count++;
					if(count==n)
						goto a;
				}
			}
			else
			{
				count++;
				if(count==n)
					goto a;
			}
		}
		space*=10;
	}
a:
	six_count?printf("%d",front/six_count*1000*six_count+six_count*666+back):\
		printf("%d",front*1000+666);}