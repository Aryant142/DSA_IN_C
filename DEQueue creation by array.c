#include <stdio.h>
#include <stdlib.h>

struct deque
{
    int front;
    int rear;
    int *arr;
    int size;
};

int isFull(struct deque *q)
{
    return (q->rear == q->size - 1)?1:0;
}

int isEmpty(struct deque *q)
{
    return (q->front == q->rear) ?1:0;
}

void enqueueRear(struct deque *q, int val)
{
    if (isFull(q))
    {
        printf("DEQUE IS FULL\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->arr[q->rear] = val;
}

void enqueueFront(struct deque *q, int val)
{
    if (q->front == 0)
    {
        printf("INSERTION AT FRONT NOT POSSIBLE\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->front--;
    }
    q->arr[q->front] = val;
}

int dequeueFront(struct deque *q)
{
    if (isEmpty(q))
    {
        printf("DEQUE IS EMPTY\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return val;
}

int dequeueRear(struct deque *q)
{
    if (isEmpty(q))
    {
        printf("DEQUE IS EMPTY\n");
        return -1;
    }
    int val = q->arr[q->rear];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->rear--;
    }
    return val;
}

int main()
{
    struct deque q;
    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueueRear(&q, 1);
    enqueueRear(&q, 2);
    enqueueFront(&q, 0);

    printf("Dequeued from front: %d\n", dequeueFront(&q));
    printf("Dequeued from rear: %d\n", dequeueRear(&q));

    free(q.arr);
    return 0;
}
