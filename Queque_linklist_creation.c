#include <stdio.h>
#include <stdlib.h>

struct que
{
    int data;
    struct que *next;
};

struct que *f = NULL;
struct que *r = NULL;



int isempty()
{
    return f == NULL;
}

int isfull(struct que *a)
{
    return a == NULL;
}

void enquee(int ndata)
{
    struct que *n = (struct que *)malloc(sizeof(struct que));
    if (isfull(n))
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = ndata;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n; // Queue is empty
        }
        else
        {
            r->next = n;   // Link the new node at the end
            r = n;         // Update the rear pointer

        }
    }
}

int dequee()
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int val = f->data;
        struct que *n = f;
        f = f->next;
        if (f == NULL)
        {
            r = NULL; // Reset rear if the queue becomes empty
        }
        free(n);
        return val;
    }
}

int main()
{
    enquee(10);
    enquee(20);
    enquee(30);

    printf("Dequeued: %d\n", dequee());
    printf("Dequeued: %d\n", dequee());
    printf("Dequeued: %d\n", dequee());
    printf("Dequeued: %d\n", dequee());

    return 0;
}
