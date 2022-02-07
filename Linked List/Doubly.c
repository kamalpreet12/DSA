#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void display(struct node *ptr , struct node *p) // there is two ponters one start from beginning and one start from ending  
{  
    while (ptr!=NULL)
    {
       printf("Elemets in forward direction are %d \n",ptr->data);
       ptr = ptr->next;
    }

    while (p!=NULL)
    {
        printf("Elemets in backward direction are %d \n",p->data);
       p = p->prev;
    }
    
     
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    
    head->data = 10;
    head->next = second;
    head->prev = NULL;

    second->data = 20;
    second->next = third;
    second->prev = head;

    third->data = 30;
    third->next = NULL;
    third->prev = second;
   
    display(head , third);

   
    return 0;
}