#include <stdio.h>

// A utility function to swap two elements, just like in selection sort
void swap(int *a, int *b) {
    int temp = *a;  // Store one element in a temporary variable
    *a = *b;        // Replace the first element with the second
    *b = temp;      // Put the original first element in the second's place
}

// This function takes the last element as pivot, places the pivot in its correct
// position in the sorted array, and places all smaller elements to the left of the pivot
// and all greater elements to the right
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // We choose the last element as pivot
    int i = (low - 1);      // i will track the position of the smaller elements

    // This loop goes through the array from low to high-1
    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Move the boundary of smaller elements to the right
            swap(&arr[i], &arr[j]);  // Swap the current element with the element at i
        }
    }

    // Place the pivot in its correct position by swapping it with the element at i+1
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);  // Return the partition point (where the pivot is placed)
}

// The main quickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {  // Base condition: if low is not less than high, the segment is sorted
        // Partition the array and get the pivot's position
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);  // Sort the left part
        quickSort(arr, pi + 1, high); // Sort the right part
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};  // Example array to sort
    int n = sizeof(arr) / sizeof(arr[0]);  // Figure out the size of the array

    printf("Original array: \n");
    printArray(arr, n);  // Print the array before sorting

    quickSort(arr, 0, n - 1);  // Call quickSort function on the entire array

    printf("Sorted array: \n");
    printArray(arr, n);  // Print the array after sorting

    return 0;
}
