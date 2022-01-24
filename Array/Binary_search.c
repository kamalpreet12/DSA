#include <stdio.h>

int binarysearch(int arr[], int size ,int element){
    int low , mid , high;
    low = 0;
    high = size-1;
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]==element){
            return mid; 
        }
        if (arr[mid]<element)
        {
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        
    }
    return -1;
}
int main(){
    int arr[100] = {2, 4, 6, 8, 12};
     int size = sizeof(arr)/sizeof(int);
    int n;
    printf("Enter the element you want to search \n");
    scanf("%d" , &n);
   int foundElement = binarysearch(arr , size , n);
    printf("The element is at %d",foundElement );
    return 0;
}