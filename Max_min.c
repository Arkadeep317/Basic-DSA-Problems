#include <stdio.h>
#define MAX 100

int a[MAX], max, min;

void maxmin(int i, int j) {
    int mid, max1, min1;
    
    if (i == j) {
        max = min = a[i];
    } else if (i == j - 1) {
        if (a[i] > a[j]) {
            max = a[i];
            min = a[j];
        } else {
            max = a[j];
            min = a[i];
        }
    } else {
        mid = (i + j) / 2;
        
        maxmin(i, mid);
        max1 = max; 
        min1 = min;
        
        maxmin(mid + 1, j);
        
        if (max1 > max) {
            max = max1;
        }
        if (min1 < min) {
            min = min1;
        }
    }
}

void main() {
    int n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter Elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    maxmin(0, n - 1);
    
    printf("Max = %d , Min = %d\n", max, min);
}


//void max_min(int i,int j):-
//     if (i == j)//for single element
//        set max = min = a[i]
//     else if(i == j -1) // for 2 element :
//	     i)if (a[i] >a[j]):
//		     max = a[i]
//			min = a[j]
//		else:
//		     max = a[j]
//			min = a[i]
//	else:
//	    set  mid = (i+j)/2
//	    call max_min(i,mid)
//	    set  max| = max, min| = min
//	    call max_min(mid+1, j)
//	    if (max|>max)
//	        max = max|
//	    if (min|<min)
//	        min = min -1

//T(N)=2T(N/2)+C
//=2^2.T(N/2^2)+2C+C
//=2^3.T(N/2^3)+2^2.2C+2C+C
//=...
//=C.LOG2N-1 BIGSIG I=0 2^I
//=C.((2LOG2N-1)/(2-1))	
//=C(N-1)=O(N)	   
