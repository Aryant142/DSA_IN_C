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
   return(ptr->top == -1)?1:0;
   
}
int isfull(struct stack *ptr)
{
   return (ptr->top == ptr->size - 1)?1:0;
   
}

int main()
{
   struct stack *s = (struct stack *)malloc(sizeof(struct stack));
   s->size = 6;
   s->top = -1;
   s->arr = (int *)malloc(s->size * sizeof(int));

   printf("Enter the values for the stack: ");
   for (int i = 0; i < s->size; i++)
   {
      scanf("%d", &s->arr[i]);
      s->top++; // Increment top as we add elements to the stack
   }

   // Checking condition
   if (isempty(s))
   {
      printf("Stack is empty\n");
   }
   else
   {
      printf("Stack is not empty\n");
   }

   if (isfull(s))
   {
      printf("Stack is full\n");
   }
   else
   {
      printf("Stack is not full\n");
   }
   
   return 0;
}
