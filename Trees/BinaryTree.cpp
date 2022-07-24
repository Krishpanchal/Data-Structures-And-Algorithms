#include<stdio.h>
#include<stdlib.h>

struct Node {
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

struct Node *root =NULL;

struct Queue {
  int size;
  int front;
  int rear;
  Node **Q; // Queue is an array of address of Nodes and we are going to create Queue dynamically
};


void createQueue(struct Queue *q, int size){
  q->size = size;
  q->front=q->rear = -1;
  q->Q = (Node **) malloc(size*sizeof(Node *));
}

int isEmpty(struct Queue q){
  return q.front == q.rear;
}

void enqueue(struct Queue *q,  Node *x){
   if(q->rear == q->size-1)
    printf("Queue is full\n");
    else {
      q->rear++;
      q->Q[q->rear] = x;
    }
}

Node * dequeue(struct Queue *q){
  Node* x = NULL;
  if(q->front == q->rear)
    printf("Queue is empty \n");
  else {
    q->front++;
    x=q->Q[q->front];
  }
  return x;
}


void createBinaryTree () {
  struct Node *p,*t;
  int x;
  struct Queue q;
  createQueue(&q,100);

  printf("Enter the root value");
  scanf("%d", &x);

  root=(struct Node *)malloc(sizeof(struct Node));
  root->data = x;
  root->lchild=root->rchild=NULL;
  enqueue(&q, root);

  while(!isEmpty(q)){
    p = dequeue(&q);
    printf("Enter the left child value of %d", p->data);
    scanf("%d", &x);
    if(x!= -1){
      t= (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      t->lchild=t->rchild=NULL;
      p->lchild=t;
      enqueue(&q, t);
    }

    printf("Enter the right child value %d", p->data);
    scanf("%d", &x);
    if(x!= -1){
      t= (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      t->lchild=t->rchild=NULL;
      p->rchild=t;
      enqueue(&q, t);
    }
  }
}

void preOrder(struct Node *p){
  if(p){
    printf("%d ", p->data);
    preOrder(p->lchild);
    preOrder(p->rchild);
  }
}


int main() {
  createBinaryTree();
  preOrder(root);

  return 0;
}


