#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (full(ptr))
    {
        printf("Stack overflow \n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int peek(struct stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        printf("Invalid position \n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 23);
    push(s, 230);
    push(s, 243);
    push(s, 123);
    push(s, 3);

    for (int k = 1; k <= s->top + 1; k++)
    {
        printf("The value at position %d is %d \n ", k, peek(s, k));
    }

    return 0;
}