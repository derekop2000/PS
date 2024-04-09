#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int x,y;
}point;
void merge(point *list,int s,int e,int mid)
{
    point* temp=(int*)malloc(sizeof(point)*(e-s));
    int left=s,right=mid,temp_point=0;
    while(left<mid&&right<e)
    {
        if(list[left].y<list[right].y)
        {
            temp[temp_point]=list[left];
            temp_point++;
            left++;
        }
        else if(list[left].y==list[right].y)
        {
            if(list[left].x<list[right].x)
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
    for(int k=temp_point; k>=0; k--)
    {
        list[s+k]=temp[k];
    }
    free(temp);
}
void merge_sort(point*list,int s,int e)
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
    int n;
    scanf("%d",&n);
    point* list=(point*)malloc(sizeof(point)*n);
    for(int i=0;i<n;i++)
    {
        scanf(" %d %d",&list[i].x,&list[i].y);
    }
    merge_sort(list,0,n);
    for(int i=0;i<n;i++)
        printf("%d %d\n",list[i].x,list[i].y);
    free(list);
}
