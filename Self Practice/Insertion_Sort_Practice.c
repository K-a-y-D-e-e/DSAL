#include <stdio.h>

void printArray(int arr[], int size){  // Print Function
    for (int i = 0; i < size; i++ ){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Insertion_Sort(int arr[], int size){  // Insertion Sort Function
    int i, j, key;  
    for (i = 1; i <= size-1; i++) // For the number of passes
    {
        key = arr[i]; // Setting up a variable that acts as the next number to be compared in the pass
        j = i-1; // Position of the number preceeding the index number

        while(j >= 0 && arr[j] > key ) // While loop that carries out each pass
        {
            arr[j+1] = arr[j]; // Incase if the initialization expression is not true, the number on the j position is shifted to the j+1 position and so on until the right number is being replaced in the linked list
            j--; 

        }
        arr[j+1] = key;
    }    
}

int main(){
    int arr[] = {56 ,22 ,71 ,15 ,25 }; 
    int size = 5;

    printArray(arr, size);
    Insertion_Sort(arr, size);
    printArray(arr, size);
}   