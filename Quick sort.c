#include <stdio.h>
#define MAX 100

int a[MAX];

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int low, int high) {
    int pivot = a[low], i = low, j = high;
    while (i < j) {
        while (a[i] <= pivot && i < high)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
    }
    swap(&a[low], &a[j]);
    return j;
}

void quickSort(int low, int high) {
    if (low < high) {
        int pivot = partition(low, high);
        quickSort(low, pivot - 1);
        quickSort(pivot + 1, high);
    }
}

void main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quickSort(0, n - 1);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}


// 1)Initialize :
//     1) set pivot = a[low], i = low, j = high
//     
 //  2)Rearrange while i<j :
   //        i)repeat while a[i] <= pivot and i<= high:
//		        set  i=i+1
//		ii)repeat  while a[j] > pivot
//		      set j = j+1
//		iii)if i<j:
//		      swap a[i] and a[j]
//	3) Final pivot placement
//	     swap a[low] and a[j]
//	4) return j			 	 	     

/*time complexity:
The problem of size $n$ is divided into two equal subproblems of size n/2.
These subproblems are solved recursively.
The results are merged (or partitioned) in linear time, which takes O(n) steps.
the recurrance relation : 
T(n) = 2T(n/2)+ Cn
using master theorem: 
a=2, b=2, f(n) = Cn => O(n^1) i.e. d=1
T(n) = O(n^d logn)
T(n) = O(n logn)*/
