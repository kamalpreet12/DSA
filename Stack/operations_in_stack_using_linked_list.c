#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node* top = NULL;
void print(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elements are : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int empty(struct node* top){
   if (top==NULL)
   {
       return 1;
   }
   else{
       return 0;
   }
   
}

int full(struct node* top){
    struct node* n = (struct node *)malloc (sizeof(struct node));
    if (n==NULL)
    {
        return 1;
    }
    return 0;
    
}

struct node* push(struct node* top , int x){
    if (full(top))
    {
        printf("Stack Overflow \n");
    }
    else{
       struct node* n = (struct node *)malloc(sizeof(struct node));
       n->data = x;
       n->next = top;
       top = n;
       return top;
    }
    
}

int pop(struct node** top){
    if (empty(*top))
    {
        printf("Stack Underflow \n");
    }
    else{
       struct node* n = *top;
      *top = (*top)->next;
      int x = n->data;
      free(n);
      return x;
    }
    
}

int peek(int position){
    struct node* ptr = top;
    for (int i = 0; (i < position-1 && ptr!= NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr!=NULL)
    {
        return ptr->data;
    }
    
  
     
}
int main(){
    top = push(top , 2);
    top = push(top , 56);
    top = push(top , 34);
    print(top);
    int element = pop(&top); 
    printf("Popped element is %d \n ", element);
    print(top);
    for (int i = 1; i <= 3; i++)
    {
    printf("The element at postion %d is %d \n ",i , peek(i));
    
    }
    
    
    return 0;
}