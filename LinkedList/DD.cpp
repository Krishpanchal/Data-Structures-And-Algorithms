#include<stdio.h>
#include<stdlib.h>

struct Node {
  struct Node *prev;
  int data;
  struct Node *next;
}*first=NULL;

void create(int A[], int n) {
  struct Node *t, *last;
  int i;

  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->prev=first->next=NULL;
  last=first;

  for(i=1; i < n; i++){
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->prev=last;
    t->next=NULL;
    last->next=t;
    last=t;
  }
}


void display(struct Node *p) {
  while(p!= NULL){
    printf("%d ", p->data);
    p = p->next;
  }
} 


int length(struct Node *p) {
  int length = 0;
  while(p){
    length++;
    p=p->next;
  }
  return length;
}

void insert(struct Node *p, int index,int val){

  struct Node *t=(struct Node *)malloc(sizeof(struct Node));
  int i;
  t->data=val;

  if(index <= 0 || index > length(p)) return;


  if(index == 1) {
    t->prev=NULL;
    t->next=first;
    first->prev=t;
    first=t;
  } else {

    for(i=0; i < index- 1; i++) p=p->next;
    
    t->next=p->next;
    t->prev=p;
    if(p->next){
      p->next->prev=t;
      p->next=t;
    }


  }

}

int Delete(struct Node *p, int index) {

  int x,i;

  if(index <= 0 || index > length(p)) return -1;

  if(index == 1){
    first = first->next;  
    x=p->data;
    free(p);
    if(first) first->prev = NULL;


  } else {

    for(i=0; i< index-1 ; i++) p=p->next;

    p->prev->next = p->next;
    if(p->next){
      p->next->prev = p->prev;
    }

    x=p->data;
    free(p);
  }

  return x;
}

int main(){

  int A[] = {1,2,3,4,5,6,7,8};

  create(A, 8);
  display(first);
  printf("\n Length of DLL  : %d\n", length(first));

  // insert(first, 1, 10);
  // display(first);


  Delete(first, 4);
  display(first);

}




