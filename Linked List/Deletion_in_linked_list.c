#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

void print(struct node *ptr){
    while (ptr!=NULL)
    {
   printf("Elements are : %d\n" , ptr->data);
   ptr = ptr->next;
        
    }
    printf("\n");
}

struct node *deletionfirst(struct node *head){
  struct node *p = head;
  head = head->next;
  free(p);
  return head;    
}

struct node *deletionatindex( struct node *head , int index){
    struct node *p = head;
    struct node *q = head->next;

    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct node *deletionatend(struct node *head){
    struct node *p = head;
    struct node *q = head->next;
    while (q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node *deletionatvalue(struct node *head , int value){
  struct node *p = head;
    struct node *q = head->next;
    while (q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data==value)
    {
    
    p->next = q->next;
    free(q);
        
    }
    return head;
  
}
int main(){
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    
    second->data = 20;
    second->next = third;

    
    third->data = 30;
    third->next = NULL;
    print(head);
    // head = deletionfirst(head);
    // head = deletionatindex(head , 1);
    // head = deletionatend(head);
    head = deletionatvalue(head , 20);
    print(head);

    return 0;
}