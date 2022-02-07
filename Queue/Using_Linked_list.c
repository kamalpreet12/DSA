#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL;
struct node *r = NULL;

struct node
{
    int data;
    struct node *next;
};

void print(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("The elements in stack are %d \n", ptr->data);
        ptr = ptr->next;
    }
}
void enqueue( int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is FUll \n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }

        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue(){
    int val = -1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty \n");
    }
    
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}
int main()
{

    enqueue(12);
    enqueue(42);
    enqueue(892);
    print(f);
    printf("Dequeueing Element froem queue is %d\n", dequeue());
    printf("Dequeueing Element froem queue is %d\n", dequeue());
    
    return 0;
}