#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

   
    i = 0; 
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements of L[], if any
    while (i < n1)
        arr[k++] = L[i++];

    // Copy remaining elements of R[], if any
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    int i;
    for ( i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Perform merge sort
    mergeSort(arr, 0, n - 1);

    // Output sorted array
    printf("Sorted array:\n");
    
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
