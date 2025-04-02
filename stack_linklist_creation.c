#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void trav(struct Node *top)
{
    struct Node *ptr = top;
    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isempty(struct Node *top)
{
    return (top == NULL) ? 1 : 0;
}

int isfull(struct Node *top)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        return 1;
    }
    else
    {
        free(newnode);
        return 0;
    }
}

struct Node *push(struct Node *top, int data)
{
    if (isfull(top))
    {
        printf("STACK IS OVERFLOW\n");
        return top;
    }
    else
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->next = top;
        top = newnode;
        return top;
    }
}

struct Node *pop(struct Node *top)
{
    if (isempty(top))
    {
        printf("STACK IS UNDERFLOW\n");
        return top;
    }
    else
    {
        struct Node *n = top;
        top = top->next;
        free(n);
        return top;
    }
}

int peek(struct Node *top, int pos)
{
    struct Node *ptr = top;
    for (int i = 0; i < pos - 1 ; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        printf("Position %d not found in the stack\n", pos);
        return -1; // Indicating an invalid position
    }
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    trav(top);

    // top = pop(top);
    // trav(top);

    int pos = 3;
    int val = peek(top, pos);
    if (val != -1)
    {
        printf("Element at position %d is %d\n", pos, val);
    }

    return 0;
}
