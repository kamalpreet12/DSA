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

int top(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int bottom(struct stack *ptr){
    return ptr->arr[0];
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

    printf("The topmost element in stack is %d \n ", top(s));
    printf("The bottom element in stack is %d \n ", bottom(s));
    return 0;
}