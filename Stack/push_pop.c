#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int empty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
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

int pop(struct stack *ptr)
{
    if (empty(ptr))
    {
        printf("Stack is empty \n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("Before pushing and poping operations the stack is \n");
    printf("Stack is empty %d\n", empty(s));
    printf("Stack is full %d\n", full(s));
    push(s, 23);
    push(s, 230);
    push(s, 243);
    push(s, 123);
    push(s, 3);
    printf("After pushing and poping operations the stack is \n");
    printf("Stack is empty %d\n", empty(s));
    printf("Stack is full %d\n", full(s));

    printf("Poped %d from the stack \n ", pop(s));

    return 0;
}