#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int top(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int precedence(char c){
    if (c == '*' || c == '/')
    {
        return 3;
    }
    else if (c == '+' || c == '-')
    {
        return 2;
    }
    else{
        return 0;
    }  
}

int operator(char c){
    if (c == '*' || c == '/' || c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
    
}

char *postfix( char *infix){
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 50;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *post = (char *)malloc(strlen(infix)+1 * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i]!= '\0')
    {
        if (!operator(infix[i]))
        {
        post[j] = infix[i];
        i++;
        j++; 
          
        }
        
    
    else{
        if (precedence(infix[i]) > precedence(top(s)) )
        {
            push(s , infix[i]);
            i++;
        }
        else{
            post[j] = pop(s);
            j++;
        }
        
    }
    }
    while (!empty(s))
    {
        post[j] = pop(s);
            j++;
    }
    post[j] = '\0';
    return post;
    
    
}

int main()
{
   char * infix = "x-y/z-k*d";
   printf("Postfix is %s ", postfix(infix));


    return 0;
}