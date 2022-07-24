#include<stdio.h>
#include<conio.h>


int findMax(int A[], int n){
  int max=A[0];

  for(int i=0;i<n;i++){
    if(A[i]>max) max=A[i];
  }

  return max;
}

void CountSort(int A[],int n){
  int max = findMax(A,n);

  int temArray[max+1] = {0};

  for(int i=0;i<n;i++){
    temArray[A[i]]++;
  }


  int i=0,j=0;

  while(j<max+1){
    if(temArray[j]>0){
      A[i++]=j;
      temArray[j]--;
    }else{
      j++;
    }
  }

  for(int i=0;i<n;i++){
    printf("%d ",A[i]);
  }
    printf("\n");

   for(int i=0;i<max+1;i++){
    printf("%d ",temArray[i]);
  }
}

int main(){
  int A[]={7,6,5,4,4,4,3,3,2,2},n=10;

  CountSort(A,n);

}