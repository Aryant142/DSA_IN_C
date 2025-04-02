// peek,push,pop,isempty,isfull
#include <stdio.h>
#include <stdlib.h>

struct stack
{
   int top;
   int size;
   int *arr;
};

int isempty(struct stack *ptr)
{
   return (ptr->top == -1) ? 1 : 0;
}

int isfull(struct stack *ptr)
{
   return (ptr->top == ptr->size - 1) ? 1 : 0;
}

void push(struct stack *ptr, int value)
{
   if (isfull(ptr))
   {
      printf("Stack overflow! Cannot push %d\n", value);
   }
   else
   {
      ptr->top++;
      ptr->arr[ptr->top] = value;
      printf("%d pushed to stack\n", value);
   }
}

int pop(struct stack *ptr)
{
   if (isempty(ptr))
   {
      printf("Stack underflow! Cannot pop\n");
      return -1; // Returning -1 to indicate error
   }
   else
   {
      int value = ptr->arr[ptr->top];
      ptr->top--;
      printf("%d popped from stack\n", value);
      return value;
   }
}

int peek(struct stack *ptr)
{
   if (isempty(ptr))
   {
      printf("Stack is empty, cannot peek\n");
      return -1; // Returning -1 to indicate error
   }
   else
   {
      return ptr->arr[ptr->top];
   }
}

int main()
{
   struct stack *s = (struct stack *)malloc(sizeof(struct stack));
   s->size = 6;
   s->top = -1;
   s->arr = (int *)malloc(s->size * sizeof(int));

   push(s, 10);
   push(s, 20);
   push(s, 30);

   // to see the top element
   printf("Top element is %d\n", peek(s));

   pop(s);

   return 0;
}
