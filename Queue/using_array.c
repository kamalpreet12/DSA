#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size, front, rear;
    int *arr;
};

void show( struct queue *n){
    for (int i = 0; i < 4 ; i++)
    {
       printf("%d \n" , n->arr[i]);
    }
    
}

int empty(struct queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    return 0;
}

int full(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (full(q))
    {
        printf("Queue is Full! \n ");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (empty(q))
    {
        printf("Queue is Empty! \n ");
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}
int main()
{

    struct queue *q;
    q->size = 4;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    show(q);
    // printf("Dequeueing Element is %d \n", dequeue(q));
    // printf("Dequeueing Element is %d \n", dequeue(q));
    // printf("Dequeueing Element is %d \n", dequeue(q));
    // printf("Dequeueing Element is %d \n", dequeue(q));

    if (empty(q))
    {
        printf("Queue is empty\n");
    }
    if (full(q))
    {
        printf("Queue is full\n");
    }

    return 0;
}