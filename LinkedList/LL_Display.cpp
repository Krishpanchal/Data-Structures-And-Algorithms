#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
}*first=NULL;

void create(int A[], int n) {
  int i;
  struct Node *t, *last;

  first=(struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->next = NULL;
  last=first;

  for(i=1; i<n; i++) {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last=t;
  }
}

void display(struct Node *p) {
  while(p  != NULL){
    printf("%d ", p->data);
    p = p->next;
  }
} 

void RDisplay(struct Node *p) {
  if(p  != NULL){
    printf("%d ", p->data);
    RDisplay(p -> next);
  }
} 


int countOfLL(struct Node *p) {
  int length = 0;
  while(p){
    length++;
    p=p->next;
  }
  return length;
}

int RCount(struct Node *p) {
  if(p!=NULL)
    return RCount(p->next) + 1;
  else
    return 0;
}

int sum(struct Node *p) {
  int res = 0;

  while(p  != NULL){
    res = res + p->data;
    p=p->next;
  }

  return res;
}

int RSum(struct Node *p){
  if(p == 0)
    return 0;
  else
    return RSum(p-> next) + p->data;
}


int maximum(struct Node *p) {
  int max = -32768;

  while(p  != NULL){
    if(p->data > max){
      max = p ->data;
    }
    p=p->next;
  }

  return max;
}

int minimum(struct Node *p) {
  int min = p->data;

  while(p  != NULL){
    if(p->data < min){
      min = p ->data;
    }
    p=p->next;
  }

  return min;
}

Node* LinearSearch(struct Node *p, int key) {
  while(p != NULL){
    if(key == p->data) return p;
    p=p->next;
  }
  return NULL;
}

Node* RescursiveLinearSearch(struct Node *p, int key) {
  if(p == NULL) return NULL;
  if(key == p->data) return p;
  return RescursiveLinearSearch(p->next, key);
}


Node* ImprovedLinearSearch(struct Node *p, int key) {
  struct Node *q;
   while(p != NULL){
    if(key == p->data) {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;
}


void insert(struct Node *p,int pos, int x){

  if(pos < 0 || pos > countOfLL(p)){
    return;
  }


  struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;



  if(pos == 0){
    t->next = first;
    first = t;
  } 
  
  else{
    for(int i = 0 ; i < pos-1; i++) p = p->next;
      t->next = p->next;
      p->next = t;
   }
}


void sortedInsert(struct Node *p, int x){
  struct Node *t,*q=NULL;
  t= (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;


  if(first==NULL){
     first=t; 
  }else {
    while(p != NULL && p->data < x){
      q=p;
      p=p->next;
    }
      if(p==first){
        t->next=first;
        first=t;
      }else {
        t->next = q->next;
        q->next=t;  
      }
  }
}

int deleteNode(struct Node *p, int pos) {
  struct Node *q=NULL;
  int x=-1,i;

  if(pos < 1 || pos > countOfLL(p)){
    return -1;
  }

  if(pos == 1){
    q=first;
    x = first->data;
    first=first->next;
    free(p);
    return x;
  }else {
    for(i=0;i<pos-1; i++){
      q=p;
      p=p->next;
    }

    q->next = p->next;
    x=p->data;
    free(p);
  return x;
  }

}

bool isListSorted(struct Node *p){
  int x= 0;

  while(p!=NULL){
    if(p->data < x)
      return false;
    x=p->data;
    p=p->next;
  }

  return true;
}

void removeDuplicate(struct Node *p){
  struct Node *q=p->next;

  while(q!=NULL){
    if(p->data != q->data){
      p=q;
      q=q->next;
    }else {
      p->next = q->next;
      free(q);
      q=p->next;
    }
  }
}

void reverseThroughElements(struct Node *p){
  int i=0, arr[countOfLL(p)];

  while(p!=NULL){
    arr[i] = p->data;
    i++; 
    p=p->next;
  }

  p=first; i--;

  while(p!=NULL){
    p->data= arr[i--];
    p=p->next;
  }

}

void reverseThroughLinks(struct Node *p){
  struct Node *q=NULL,*r=NULL;

  while(p!=NULL){
    r=q;
    q=p;
    p=p->next;
    q->next=r;
  }
  first=q;
}

void recursiveReverseThroughLinks(struct Node *q,struct Node *p){

  if(p!=NULL){
    recursiveReverseThroughLinks(p, p->next);
    p->next = q;
  }else{
    first = q;
  }
}


int main () {
  int A[] = {1,2,3,4,5,6,7,9};
  // int A[] = {1,2,4,4,5,5,5,5};

  create(A,8);
  // display(first);
  // Display Rescursviely
  // RDisplay(first);
  // printf("\n");

  // printf("\nLength :-  %d",RCount(first));
  // printf("\nSum :-  %d",sum(first));
  // printf("\nSum :-  %d",RSum(first));
  // printf("Max :- %d", maximum(first));

  // printf("\nMin :- %d", minimum(first));

  // ///////////Linear Search
  // struct Node *element = LinearSearch(first,1);
  // if(element)
  //   printf("%d",element->data);
  // else 
  //   printf("Element not found");
  // return 0;


  ////////////Rescursive Linear Search
//  struct Node *element = RescursiveLinearSearch(first,3);
//   if(element)
//     printf("%d",element->data);
//   else 
//     printf("Element not found");

////////////Improved Linear Search

//  struct Node *element = ImprovedLinearSearch(first, 35);
//   if(element)
//     printf("%d \n",element->data);
//   else 
//     printf("Element not found");

  // display(first);
  // printf("\n");
  // // insert(first,0, 1); 
  // // sortedInsert(first, 0);
  // printf("Deleted element is %d ",deleteNode(first, 5));
  // printf("\n");
  // display(first);

    // isListSorted(first) ? printf("List is sorted") : printf("List is not sorted");
    display(first);
    printf("\n");
    // removeDuplicate(first);
  // reverseThroughElements(first);
  // reverseThroughLinks(first);
  recursiveReverseThroughLinks(NULL,first);
    printf("\n");
    display(first);


  return 0;
}


