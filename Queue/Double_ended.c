#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size, front, front1,  rear;
    int *arr;
};

void show( struct queue *n , int usedSize){
    for (int i = 0; i < usedSize ; i++)
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

void enqueueRear(struct queue *q, int val)
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

int enqueueFront(struct queue *q, int val)
{
    if (full(q))
    {
        printf("Queue is Full! \n ");
    }
    else
    {
        int a;
        a = q->arr[q->front1-1];
        q->arr[q->front1] = val;
        q->front1--;
         return a;   
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
    q->size =5;
    q->front = q->rear = -1;
    q->front1 = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    enqueueRear(q, 10);
    enqueueRear(q, 20);
    enqueueRear(q, 30);
    enqueueRear(q, 40);
    show(q , 4);
    enqueueFront(q , 78);
    show(q ,4);

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