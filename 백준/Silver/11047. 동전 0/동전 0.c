#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int n,k,sum=0,temp;
	scanf(" %d %d",&n,&k);
	int* list= (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		scanf(" %d",list+i);
	for(int i=n-1;i>=0;i--)
	{
		sum+=(k/list[i]);
		k=(k%list[i]);
		if(k==0)
		break;
	}
	printf("%d",sum);
	free(list);
}