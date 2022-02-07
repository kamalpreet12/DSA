#include <stdio.h>

void print(int *arr , int size){
    for (int i = 0; i < size; i++)
    {
    printf("%d ", arr[i]);
        
    }
    printf("\n");
}

void BubbleSort(int *arr , int size){
    int temp;
    int isSorted = 0;    // For making Bubble Sort Adaptive
    for (int i = 0; i < size-1; i++)  // Numberc of passes
    {
        printf("Sorted in pass number %d \n", i+1);
        isSorted = 1;
        for (int j = 0; j < size-1-i; j++)  // Number of comparison
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted  =0;
            }
            
        }
        if (isSorted)
        {
            return ;
        }
        
    }
    
}

int main(){
    int arr[] = {2 , 7, 3 , 14 , 1};
    // int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    print(arr , size);
    BubbleSort(arr , size);
    print(arr , size);
    return 0;
}