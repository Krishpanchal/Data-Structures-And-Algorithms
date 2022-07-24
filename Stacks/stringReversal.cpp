#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct Stack {
  int size;
  int top;
  char* array;
};

struct Stack* create(int size){
  
  struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
  stack->size=size;
  stack->top = -1;
  stack->array = (char*) malloc(stack->size * sizeof(char));
  return stack;
}

void Display(struct Stack st){
  int i;
  for(i=st.top; i >=0; i--){
    printf("%d ", st.array[i]);
  }
  printf("\n");
}

int isFull(struct Stack* stack){ 
  return stack->top == stack->size - 1; 
}
 

int isEmpty(struct Stack* stack){
   return stack->top == -1; 
}

void push(struct Stack *st, char value){
  if(isFull(st))
    printf("Stack Overflow");
  else {
    st->top++;
    st->array[st->top] = value;
  }
}

char pop(struct Stack *st){
  int x=-1;

  if(isEmpty(st))
    printf("Stack Underflow");
  else 
    x = st->array[st->top--];
  return x;
}

void reverse(char str[]){
  int n = strlen(str);
  struct Stack *stack = create(n);

  int i;
  for(i=0; i<n;i++)
    push(stack, str[i]);

  for(i = 0; i < n; i++)
    str[i] = pop(stack);

}

void Display(struct Stack st){
  int i;
  for(i=st.top; i >=0; i--){
    printf("%d ", st.array[i]);
  }
  printf("\n");
}


int main(){
  
  char str[20];
  printf("Enter a string you want to reverse: ");
  gets(str);
  
  reverse(str);
  printf("\nThe reversed string is %s \n", str);

  return 0;
}
