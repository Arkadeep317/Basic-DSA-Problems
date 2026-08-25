#include <stdio.h>

int arr[100];

void merge(int beg, int mid, int end) {
    int i = beg, j = mid + 1, idx = 0, temp[100];
    
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[idx] = arr[i];
            i++; idx++;
        }
        else {
            temp[idx] = arr[j];
            j++; idx++;
        }
    }
    
    if (i > mid) {
        while (j <= end) {
            temp[idx] = arr[j];
            idx++; j++;
        }
    }
    else {
        while (i <= mid) {
            temp[idx] = arr[i];
            idx++; i++;
        }
    }
    
    int k = 0;
    while (k < idx) {
        arr[beg + k] = temp[k];
        k++;
    }
}

void mergeSort(int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        mergeSort(beg, mid);
        mergeSort(mid + 1, end);
        merge(beg, mid, end);
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    mergeSort(0, n - 1);
    
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}


//merge sort(beg,end) 
//1)if beg < end:
//	i) set mid = \lfloor (beg + end) / 2 \rfloor
//	ii) call mergeSort(beg, mid)
//	iii) call mergeSort(mid + 1, end)
//	iv) call merge(beg, mid, end)
//[End of IF]
//merge(beg, mid, end)
//1)Initialize:
// * set i = beg, j = mid + 1, index = 0
//2)Repeat while [(i <=mid)  and (j <=	 end)]
//	i) if arr[i] <= arr[j]
  //         set temp[index] = arr[i]
      //     set i = i + 1, index = index + 1
    //    else
        //   set temp[index] = arr[j]
          // set j = j + 1, index = index + 1
//[End of if and end of Loop]

//3)Copy remaining element of any subarray if exist
//if i > mid : //if exist in right subarray
//	i) repeat while j \le end:
//		set temp[index] = arr[j]
//		set j = j + 1, index = index + 1
//else //if exist in left subarray
//	i) repeat while i <= mid
//		set temp[index] = arr[i]
//		set i = i + 1, index = index + 1
//[Copy the content of temp back to arr]
//4)set K = 0
//5)Repeat while K < \text{temp.size}
//	i) set arr[beg + K] = temp[K]
//	ii) K = K + 1
//6)End

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
