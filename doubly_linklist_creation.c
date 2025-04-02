#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
   struct Node *prev;
};

void linktrversal(struct Node *head)
{
  struct Node *ptr = head;
  while (ptr != NULL)
  {
    printf("%d \n", ptr->data);
    ptr = ptr->next;
  }
}

void revtrversal(struct Node *tail){
    struct Node *ptr = tail;
    while(ptr!=NULL){
        printf("%d \n",ptr->data);
        ptr=ptr->prev;
    }
}

int main()
{
  struct Node *head;
  struct Node *second;
  struct Node *third;

  // Allocate memory for node in the linked list heap
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));

  head->prev= NULL;
  head->data = 7;
  head->next = second;

  second->prev=head;
  second->data = 11;
  second->next = third;

  third->prev=second;
  third->data = 12;
  third->next = NULL;

  printf("forward print : \n");
  linktrversal(head);

  printf("backword print : \n");
  revtrversal(third);
  return 0;
}