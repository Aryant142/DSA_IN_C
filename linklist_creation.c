#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
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

int main()
{
  struct Node *head;
  struct Node *second;
  struct Node *third;

  // Allocate memory for node in the linked list heap
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));

  head->data = 7;
  head->next = second;

  second->data = 11;
  second->next = third;

  third->data = 12;
  third->next = NULL;

  linktrversal(head);

  return 0;
}