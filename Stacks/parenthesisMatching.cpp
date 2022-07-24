#include<stdio.h>
#include<stdlib.h>

struct Node {
  char data;
  struct Node *next;
}*top=NULL;

void push(char x){
  struct Node *t = (struct Node*)malloc(sizeof(struct Node));
  if(!t) printf("Stack Overflow");
  else {
    t->data = x;
    t->next= top;
    top=t;
  }
}

char pop(){
  struct Node *t;
  int x = -1;  
  if(top == NULL)
    printf("Stack is Empty \n");
  else {
    t=top;
    top=top->next;
    x=t->data;
    free(t);
  }
    return x;
}

void Display(){
  struct Node *p = top;
  while(p->next != NULL){
    printf("%d ", p->data);
    p=p->next;
  }
  printf("\n");
}


int isBalanced(char *exp){
  int i;

  for(i=0; exp[i] != '\0'; i++){
    if(exp[i] == '(') push(exp[i]);
    else if(exp[i] == ')') {
      if(top == NULL) return 0;
      pop();
    }
  }

  if(top == NULL) return 1;
  else return 0;
}


int main(){

  char str[40];
  printf("Enter the expression: ");
  gets(str);

  int balanced = isBalanced(str);

  balanced == 1 ? printf("The given exp is balanced") : printf("The given exp is not balanced");

}