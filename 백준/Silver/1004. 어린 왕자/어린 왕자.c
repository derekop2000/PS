#include<stdio.h>
int main(int argc, char *argv[])
{
	int xs,ys,xe,ye;
	int x,y,r;
	int test_case;
	int n;
	int count=0;
	scanf("%d",&test_case);
	for(int i=0;i<test_case;i++)
		{
			count=0;
			scanf(" %d %d %d %d",&xs,&ys,&xe,&ye);
			scanf(" %d",&n);
			while(n--)
			{
				scanf(" %d %d %d",&x,&y,&r);
				if(( (x-xs)*(x-xs)+(y-ys)* (y-ys)<(r*r ))&& ((x-xe)*(x-xe)+(y-ye)* (y-ye)>(r*r)) )
				count++;
				if( ((x-xe)*(x-xe)+(y-ye)* (y-ye)<r*r) && ((x-xs)*(x-xs)+(y-ys)* (y-ys)>(r*r)) )
				count++;
			}
			printf("%d\n",count);
		}
		
}