#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertionAtFirst(struct Node *head, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = head;
    newNode->data = newData;
    return newNode;
}

struct Node *insertionAtIndex(struct Node *head, int newData, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;

    struct Node *p = head;
    int i = 0;

    while (i < index - 1)
    {
        p = p->next;
        i++;
    }

    newNode->next = p->next;
    p->next = newNode;
    return head;
}

struct Node *insertatlast(struct Node *head, int newdata)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = NULL; // Set new node's next to NULL as it will be the last node

    struct Node *p = head;
    while (p->next != NULL) // Corrected condition
    {
        p = p->next;
    }
    p->next = newnode;
    return head;
}

struct Node *insertafternode(struct Node *head, struct Node *prevnode, float newdata)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = prevnode->next;
    prevnode->next = newnode;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 9;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 11;
    third->next = NULL;

    printf("Original linked list:\n");
    linkTraversal(head);

    // Uncomment to test insertion at the beginning
    head = insertionAtFirst(head, 8);
    printf("After insertion at first:\n");
    linkTraversal(head);

    // Uncomment to test insertion at a specific index
    head = insertionAtIndex(head, 8, 2);
    printf("After insertion at index 2:\n");
    linkTraversal(head);

    // Insert at the last
    printf("After insertion at last:\n");
    head = insertatlast(head, 13);
    linkTraversal(head);

    printf("insert after a node:\n");
    head = insertafternode(head, second,11);
    linkTraversal(head);
    
    return 0;
}
