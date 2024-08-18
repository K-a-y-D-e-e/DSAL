#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        
    }
    printf("\n");
}

void Bubble_Sort(int arr[], int size){
    int i, j, temp;
    for(i = 0; i < size-1; i++) // For number of passes
    {
        for(j = 0; j < size-1-i; j++ ) // For the completion of the number of passes
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

int main() {

    int size = 5;
    int arr[] = {5,1,4,3,2};
    
    printArray(arr,size);
    Bubble_Sort(arr,size);
    printArray(arr,size);
    return 0;
}