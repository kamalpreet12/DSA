#include <stdio.h>
#include <stdlib.h>

struct node{
   int data;
   struct node *next;
};

void printlist(struct node *ptr){
    while (ptr!=NULL)
    {
    printf("Elements are %d\n", ptr->data);
    ptr = ptr->next;
        
    } 
    printf("\n");  
}

struct node *insertionfirst(struct node *head , int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = head;
    return p;
}

struct node *insertatindex(struct node *head , int data , int index){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    int i = 0;

    while (i!=index-1)
    {
        ptr = ptr->next;
        i++;
    }
    p->data = data;
    p->next = ptr->next;
    ptr->next = p;
    return head;
}

struct node *insertionatend(struct node *head , int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
   while (ptr->next!=NULL)
   {
       ptr = ptr->next;
   }
   
    p->data = data;
    ptr->next = p;
    p->next = NULL;
    return head;
}

struct node *insertionafterNode(struct node *prevnode ,struct node *head, int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    // struct node *ptr = head;
    p->data = data;
    p->next = prevnode->next;
   prevnode->next = p; 
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

   printlist(head);
//    head = insertionfirst(head, 45);
//    head = insertatindex(head , 45 , 2);
//    head = insertionatend(head , 45);
      head = insertionafterNode(second,head , 45);
   printlist(head);
    return 0;
}