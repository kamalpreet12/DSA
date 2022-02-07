#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
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

void push(struct stack *ptr, char val)
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

char pop(struct stack *ptr)
{
    if (empty(ptr))
    {
        printf("Stack is empty \n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

    int parenthesisMatch(char *exp)
    {
        struct stack *s;
        s->size = 50;
        s->top = -1;
        s->arr = (char *)malloc(s->size * sizeof(char));

        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '(')
            {
                push(s, '(');
            }
            else if( exp[i] == ')' )
            {
                if (empty(s))
                {
                    return 0;
                }
                pop(s);
            }
        }
        if (empty(s))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int main()
    {
        char *exp = "((8)(*--$$9))";

        if (parenthesisMatch(exp))
        {
            printf("The parenthesis is matching");
        }
        else
        {
            printf("The parenthesis is not matching");
        }

        return 0;
    }