#include <stdio.h>

int linearsearch(int arr[], int size , int element){
    for (int i = 0; i <= size ; i++)
    {
        if (arr[i]==element)
        {
           return i;
        }
        
    }
        return -1;
    
}
int main(){
    int arr[100] = {1, 2, 45, 5, 3, 34};
    int size = sizeof(arr)/sizeof(int);
    int n;
    printf("Enter the element you want to search \n");
    scanf("%d" , &n);
   int foundElement = linearsearch(arr , size , n);
    printf("The element is at %d",foundElement );
    return 0;
}