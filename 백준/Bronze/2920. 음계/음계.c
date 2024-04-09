#include <stdio.h>
int main()
{
  int arr[8];
  for(int i=0;i<8;i++)
    scanf(" %d",&arr[i]);
  int ans=2;
  if(arr[0]==1)
  {
      ans=0;
      for(int i=1;i<8;i++)
        if(arr[i]-1!=i)
      {
          ans=2;
          break;
      }
  }
  else if(arr[0]==8)
  {
      ans=1;
      for(int i=1;i<8;i++)
        if(arr[i]!=8-i)
      {
          ans=2;
          break;
      }
  }
  if(ans==0)
    printf("ascending");
  else if(ans==1)
    printf("descending");
  else
    printf("mixed");


}
