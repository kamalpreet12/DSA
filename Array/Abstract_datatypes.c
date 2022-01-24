#include <stdio.h>
#include <stdlib.h>
struct array
{
    int array_size;
    int array_sizeused;
    int *ptr;
};

void getvalues( struct array * n , int total_size , int size_used){
    
    n->array_size = total_size;
    n->array_sizeused = size_used;
    n->ptr = (int*)malloc(total_size * sizeof(int));
}

void setvalues( struct array * n ){
    int a;
    for (int i = 0; i < n->array_sizeused; i++)
    {
        printf("Enter the elements of array %d " , i);
        scanf("%d" , &a);
        (n->ptr)[i] = a;
    }
    
}

void show( struct array *n){
    for (int i = 0; i < n->array_sizeused; i++)
    {
       printf("%d \n" , n->ptr[i]);
    }
    
}
int main(){
    struct array arr;
    getvalues(&arr , 10 , 3);
    setvalues(&arr);
    show(&arr);
    return 0;
}