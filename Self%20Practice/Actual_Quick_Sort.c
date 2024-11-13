#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {  // If current element is smaller than the pivot
            i++;
            swap(&arr[i], &arr[j]);  // Swap arr[i] and arr[j]
        }
    }
    // Swap the pivot element with the element at i+1
    swap(&arr[i + 1], &arr[high]);
    return i + 1;  // Return the partition index
}

// Function to implement Quick Sort
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition index

        // Recursively sort elements before and after partition
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
