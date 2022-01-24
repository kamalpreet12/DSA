#include <stdio.h>

void display(int arr[] , int size){
    for (int i = 0; i <= size; i++)
    {
        printf("%d\n" , arr[i]);
    }
    printf("\n");
}
int sortedarr(int arr[], int size ,int  element,int capacity , int index){
    if (size>=capacity)
    {
        return -1;
    }
    for (int i = size-1 ; i <= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
    
}

int main(){
    int arr[100] = { 1 , 23 , 34 , 67};
    int size = 3, element = 20 , index = 1; 
    display(arr , size);
    sortedarr(arr, size , element, 100 , index);
    size += 1;
     display(arr , size);
    return 0;
}