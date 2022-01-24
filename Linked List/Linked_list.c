#include <stdio.h>
#include <stdlib.h>
// Syntax of Linked List
struct node
{
    int data;
    struct node *next;
};

void print(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elements are : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *first;
    struct node *second;
    struct node *third;
    first = (struct node *)malloc(sizeof(struct node));  //The “malloc” or “memory allocation” method in C is used
                                                   // to dynamically allocate a single large block of memory with the specified size.
    second = (struct node *)malloc(sizeof(struct node)); //int *ptr; ptr=(int *)malloc(8);
    third = (struct node *)malloc(sizeof(struct node));

    // linking first and second node
    first->data = 10;
    first->next = second;

    // linking second and third node
    second->data = 20;
    second->next = third;

    // terminate the third node
    third->data = 30;
    third->next = NULL;

    print(first);
    return 0;
}