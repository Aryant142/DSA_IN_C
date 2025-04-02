#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

struct Deque* createDeque() {
    struct Deque* q = (struct Deque*)malloc(sizeof(struct Deque));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct Deque* q) {
    return q->front == NULL;
}

void enqueueFront(struct Deque* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue is full\n");
        return;
    }
    newNode->data = val;
    newNode->next = q->front;
    newNode->prev = NULL;
    if (isEmpty(q)) {
        q->rear = newNode;
    } else {
        q->front->prev = newNode;
    }
    q->front = newNode;
}

void enqueueRear(struct Deque* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue is full\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = q->rear;
    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

int dequeueFront(struct Deque* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front) {
        q->front->prev = NULL;
    } else {
        q->rear = NULL;
    }
    free(temp);
    return val;
}

int dequeueRear(struct Deque* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = q->rear;
    int val = temp->data;
    q->rear = q->rear->prev;
    if (q->rear) {
        q->rear->next = NULL;
    } else {
        q->front = NULL;
    }
    free(temp);
    return val;
}

int main() {
    struct Deque* q = createDeque();

    enqueueRear(q, 10);
    enqueueRear(q, 20);
    enqueueFront(q, 5);

    printf("Dequeued from front: %d\n", dequeueFront(q));
    printf("Dequeued from rear: %d\n", dequeueRear(q));
    printf("Dequeued from front: %d\n", dequeueFront(q));
    printf("Dequeued from rear: %d\n", dequeueRear(q));

    free(q);
    return 0;
}
