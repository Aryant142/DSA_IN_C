#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void linktrversal(struct Node *head)
{
  struct Node *ptr=head;
  do
  {
    printf("%d \n", ptr->data);
    ptr = ptr->next;
  } while (ptr!=head);
  
}

struct Node *insertionatfirst(struct Node *head,int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    struct Node *ptr=head;
    newnode->data=data;
    do
    {
        ptr=ptr->next;
    } while (ptr->next!=head);
    ptr->next=newnode;
    newnode->next=head;
    head=newnode;
    return head;
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
  third->next = head;
  
  printf("after insertion at first : \n");
  head=insertionatfirst(head,6);
  linktrversal(head);

  return 0;
}