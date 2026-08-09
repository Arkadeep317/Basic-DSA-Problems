#include <stdio.h>
#define MAX 100

int arr[MAX];

void sortArray(int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int binarySearch(int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            return binarySearch(low, mid - 1, key);
        else
            return binarySearch(mid + 1, high, key);
    }
    return -1;
}

int main() {
    int n, key, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sortArray(n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    int result = binarySearch(0, n - 1, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}

//Start.
//Read the number of elements n.
//Read n elements into the array.
//For i = 0 to n - 2:
//For j = 0 to n - i - 2:
//If arr[j] > arr[j + 1], swap them.
//Array is now sorted.
//Algorithm for Binary Search
//Set low = 0 and high = n - 1.
//If low > high, return -1 (element not found).
//Compute mid = (low + high) / 2.
//If arr[mid] == key, return mid.
//If key < arr[mid], search in the left half (low to mid - 1).
//Otherwise, search in the right half (mid + 1 to high).
//Repeat until the element is found or the search range becomes empty.
// time complexity: 
//n/2^0->n/2^1->...->n/2^k
//n/2^k=1
//n=2^k
//log2(n)=log2(2^k)
//k=log2(n)
//O(log2(n))
