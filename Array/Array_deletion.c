#include <stdio.h>

void display(int arr[] , int n){
    for (int i = 0; i <= n; i++)
    {
        printf("%d\n" , arr[i]);
    }
    printf("\n");
}
int deletedarr(int arr[], int size ,int index){

    for (int i = index ; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    
    
    
}

int main(){
    int arr[100] = { 1 , 23 , 34 , 67};
    int size = 3, index = 2; 
    display(arr , size);
    deletedarr(arr, size , index);
    size -= 1;
     display(arr , size);
    return 0;
}