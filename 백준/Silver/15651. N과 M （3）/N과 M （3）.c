#include <stdio.h>

int N,M;
char arr[15];


void permute(int depth){

  if(depth == M){
    for(int i=0; i<2*M ; i++){
      printf("%c",arr[i]);
    }
    printf("\n");
    return;
  }

  for(int i=1; i<=N ; i++){
    arr[2*depth] = i + '0';
    permute(depth+1);

  }
}
int main(){
  

  scanf("%d %d",&N,&M);
  for(int i=0 ; i<2*M ; i++){
    arr[i] = ' ';
  }
  permute(0);



  

}