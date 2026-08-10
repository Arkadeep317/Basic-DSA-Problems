#include <stdio.h>
#define MAX 100

int arr[MAX];

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
    
    printf("Enter sorted elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    
    int result = binarySearch(0, n - 1, key);
    
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
        
    return 0;
}



//binary_search(int low,int high,int,key){
 //        if(low<=high):
 //        set mid = (low+high)/2
 //        if key == a[mid]then return mid
 //        else if (key <a[mid]):
 //          return binary_search(low,mid-1,key);
 //         else
//		  return binary_search(mid+1, end, key);
// otherwise:
//     return -1 // target not found
//}
