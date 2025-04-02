#include <stdio.h>
#include <stdlib.h>

struct que
{
    int front;
    int rear;
    int *arr;
    int size;
};
 
int isfull(struct que *q)
{
    return (q->rear == q->size - 1) ? 1 : 0;
}

int isempty(struct que *q)
{
    return (q->rear == q->front) ? 1 : 0;
}

int dequeue(struct que *q)
{
    if (isempty(q))
    {
        printf("QUEUE IS EMPTY\n");
        return -1; // Return a sentinel value indicating the queue is empty
    }
    else
    {
        q->front++;
        int val = q->arr[q->front];
        return val;
    }
}

void enqueue(struct que *q, int val)
{
    if (isfull(q))
    {
        printf("QUEUE IS FULL\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int main()
{
    struct que q;
    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue elements
    enqueue(&q, 1);
    enqueue(&q, 2);
    
    // Dequeue element
    int dequeued_val = dequeue(&q);
    if (dequeued_val != -1)
        printf("Dequeued: %d\n", dequeued_val);

    // Free allocated memory
    free(q.arr);

    return 0;
}
