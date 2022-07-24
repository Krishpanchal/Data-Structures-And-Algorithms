#include<stdio.h>
#include<stdlib.h>

struct Node {
  struct Node *lchild;
  int data;
  struct Node *rchild;
}*root=NULL;

void Insert(int key){
  struct Node *t=root;
  struct Node *r,*p;

  if(root == NULL) {
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    root=p;
    return;
  }

  while(t!=NULL){
    r=t;

    if(key<t->data)
      t=t->lchild;
    else if(key>t->data)
      t=t->rchild;
    else
      return;
  }

  p=(struct Node *)malloc(sizeof(struct Node));
  p->data = key;
  p->rchild=p->lchild=NULL;

  if(key<r->data) r->lchild=p;
  else r->rchild=p;
}

void Inorder(struct Node *p){
  if(p){
    Inorder(p->lchild);
    printf("%d ", p->data);
    Inorder(p->rchild);
  }
}

struct Node * search(int key) {

  struct Node *t = root;

  while(t!=NULL){
    if(key==t->data)
      return t;
    else if (key<t->data)
      t=t->lchild;
    else
      t=t->rchild;
  }

  return NULL;
}

int Height(struct Node *p) {
  int x,y;
  if(p==NULL) return 0;
  x=Height(p->lchild);
  y=Height(p->rchild);
  return x>y ? x+1:y+1; 
}

struct Node *InPre(struct Node *p) {
  while(p && p->rchild!=NULL)
    p=p->rchild;
  
  return p;
}

struct Node *InSucc(struct Node *p) {
  while(p && p->lchild!=NULL)
    p=p->lchild;
  
  return p;
}

struct Node * Delete(struct Node *p, int key){

  struct Node *q;

  if(p==NULL)
    return NULL;
  if(p->lchild==NULL && p->rchild==NULL){
    
    if(p==root)
      root = NULL;
    free(p);
    return NULL;
  }


  if(key < p->data)
    p->lchild=Delete(p->lchild,key);
  else if(key>p->data)
    p->rchild=Delete(p->rchild,key);
  else {

      if(Height(p->lchild) > Height(p->rchild)){
        q=InPre(p->lchild);
        p->data = q->data;
        p->lchild=Delete(p->lchild,q->data);
      } else {
        q=InSucc(p->rchild);
        p->data = q->data;
        p->rchild=Delete(p->rchild,q->data);
      }

  }

  return p;
}


int main(){

   int willContinue = 1;

    while (willContinue == 1)
    {

        int choice;

         printf(
            "\n\nWhich operation you want to do ??:"
            "\n\n 1. Insert in Tree"
            "\n 2. Search an element in Tree"
            "\n 3. Delete an element from Tree"
            "\n\n Enter the number:- "
            );
        scanf("%d", &choice);


        switch(choice){

          case 1: {
            Insert(10);
            Insert(5);
            Insert(20);
            Insert(8);
            Insert(30);
            Insert(9);
            Insert(7);
            Insert(15);
            Inorder(root);
            break;
          }

          case 2: {
              int key;
              printf("Enter the value you want to search :");
              scanf("%d", &key);
              if(search(key)!=NULL)
                printf("\nThe value %d is present in the tree", key);
              else
                printf("\nThe value %d is not present in the tree", key);
              printf("\n");
              break;
          }

          case 3: {
            int key;
            printf("\nEnter the value you want to delete :");
            scanf("%d", &key);
            if(Delete(root,key)!=NULL)
              printf("\nThe value %d is deleted in the tree\n", key);
            else
              printf("\nThe value %d is not present in the tree \n", key);

            Inorder(root);
            break;
          }
        
          default:
            printf("No");
            break;  
        }

      printf("\n\nDo you want to redo the operation ? \n If yes, enter 1 else 0 \n");
        scanf("%d", &willContinue);
    }

  return 0;
}

