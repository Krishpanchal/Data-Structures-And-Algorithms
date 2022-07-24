#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
}*Head;


void create(int A[], int n){
  int i;
  struct Node *t,*last;
  Head=(struct Node *)malloc(sizeof(struct Node));
  Head->data=A[0];
  Head->next= Head;
  last=Head;


  for(i=1; i<n; i++){
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=Head;
    last->next=t;
    last=t;
  }
}

void Display(struct Node *p) {
  do{
    printf("%d ", p->data);
    p=p->next;
  }while(p!=Head);
}

int Length(struct Node *p) {
  int i=0;
  do{
    p=p->next;
    i++;
  }while(p!=Head);

  return i;
}


void Insert(struct Node *p, int index, int val){
  int i;
  Node *t = (struct Node *)malloc(sizeof(struct Node));
  t->data = val;

  if(index <= 0 || index > Length(Head)) return;

  if(index == 0){
    if(Head == NULL){
      Head=t;
      t->next=Head;
    }else {
      t->next=Head;
      while(p->next!=Head) p=p->next;
      p->next=t;
      Head=t;
    }
  }

  else {
    for(i=0;i<index-1;i++){
      p=p->next;
    }

    t->next = p->next;
    p->next = t;
  }
}


int Delete(struct Node *p, int index){

  struct Node *q;
  int i,x;

  if(index <= 0 || index > Length(Head)) return -1;
    
    if(index==1){
        while(p->next!=Head) p=p->next;
        x = Head->data;

        if(p==Head){
          free(Head);
          Head = NULL;
        } else {
          p->next = Head->next;
          free(Head);
          Head = p->next;
        }
      }

  else {
    for( i=0; i < index-2 ; i++) p=p->next;

    q=p->next;
    p->next = q->next;
    x = q->data;
    free(q);
  }

  return x;
}

int main(){
  int A[] = {1,2,3,4,5, 6};

  create(A,6);
  Display(Head);
  printf("\n Length :- %d \n", Length(Head));

  // Insert(Head, 1, 0);
  // Display(Head);


  Display(Head);
  printf("\n Node with value %d deleted \n", Delete(Head, 10));
  Display(Head);

}