#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void *linktrversal(struct Node *p)
{

    while (p != NULL)
    {
        printf("%d \n", p->data);
        p = p->next;
    }
}

struct Node *deleteatfirst(struct Node *head)
{
    struct Node *p = head;
    head = head->next;
    free(p);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }

    struct Node *q =p->next;   
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteatlast(struct Node *head){
    struct Node *p=head;
 
    // Traverse to the second-to-last node
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    struct Node *q=p->next;
    p->next=NULL;
    free(q);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for node in the linked list heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 12;
    third->next = fourth;

    fourth->data = 13;
    fourth->next = NULL;

    head=deleteatfirst(head);
    linktrversal(head);

    head=deleteAtIndex(head,2);
    linktrversal(head);

    head=deleteatlast(head); 
    linktrversal(head);

    return 0;
}