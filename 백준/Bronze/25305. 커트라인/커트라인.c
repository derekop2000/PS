#include <stdio.h>
#include <stdlib.h>
void merge(int *list,int s,int e,int mid)
{
    int* temp=(int*)malloc(4*(e-s));
    int left=s,right=mid,temp_point=0;
    while(left<mid&&right<e)
    {
        if(list[left]>list[right])
        {
            temp[temp_point]=list[left];
            temp_point++;
            left++;
        }
        else
        {
            temp[temp_point]=list[right];
            temp_point++;
            right++;
        }
    }
    while(left<mid)
    {
        temp[temp_point]=list[left];
        temp_point++;
        left++;
    }
    while(right<e)
    {
        temp[temp_point]=list[right];
        temp_point++;
        right++;
    }
    temp_point--;
    for(int k=temp_point;k>=0;k--)
    {
        list[s+k]=temp[k];
    }
    free(temp);
}
void merge_sort(int*list,int s,int e)
{
    if(s<e-1)
    {
        int mid= (s+e)/2;
        merge_sort(list,s,mid);
        merge_sort(list,mid,e);
        merge(list,s,e,mid);
    }
}
int main()
{
    int n,k,m;
    scanf("%d %d",&n,&k);
    int* list=(int*)malloc(4*n);
    for(int i=0;i<n;i++)
    {
        scanf(" %d",&m);
        list[i]=m;
    }
    merge_sort(list,0,n);
    printf("%d",list[k-1]);
    free(list);
}
