#include <stdio.h>
#include <stdlib.h>
int a[20], i;
void linear_search() {
    int n, x, s = 0,c1=0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter Element Number %d: ", (i+1));
        scanf("%d", &a[i]);
    }
    printf("The Array you gave is:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nEnter the Element to Search: ");
    scanf("%d", &x);
    for(i = 0; i < n; i++) {
    	c1++;
        if(a[i] == x) {
            s=1;
            break;
        }
    }
    if(s == 0) {
        printf("Search Unsuccessful \n");
    } else {
        printf("Search Successful at position %d \n",(i+1));
    }
    printf("The  total number of searches in in linear search is %d",c1);
}

int binary_search() {
    int n, x, s = 0, low, high, mid,c2=0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("Enter Element Number %d: ", (i+1));
        scanf("%d", &a[i]);
    }
    printf("The Array you gave is:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nEnter the Element to Search: ");
    scanf("%d", &x);
    
    low = 0;
    high = n - 1;
    while(low <= high) {
    	c2++;
        mid = (low + high) / 2;
        if(a[mid] == x) {
            s++;
            break;
        }
        else if(x < a[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if(s == 0) {
        printf("Search Unsuccessful \n");
    } else {
        printf("Search Successful at position %d \n",(mid+1));
    }
	printf("The  total number of searches in in binary search is %d",c2);
    return 0;
}

void interpolation_search( ) {
    int n, x, s = 0, low, high, pos,c3=0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in UNIFORM ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("Enter Element Number %d: ", (i+1));
        scanf("%d", &a[i]);
    }
    printf("The Array you gave is:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nEnter the Element to Search: ");
    scanf("%d", &x);
    low = 0;
    high = n - 1;
    
    while(low <= high && x >= a[low] && x <= a[high]) {
    	c3++;
        if (a[high] == a[low]) 
		{
			c3++;
			break;
		}

        pos = low + ((x - a[low]) * (high - low)) / (a[high] - a[low]);

        if(a[pos] == x) {
        	c3++;
            s++;
            break;
        }
        else if(a[pos] < x) {
        	c3++;
            low = pos + 1;
        }
        else {
        	c3++;
            high = pos - 1;
        }
    }

    if(s == 0) {
        printf("Search Unsuccessful ");
    } else {
        printf("Search Successful at position %d \n",(pos+1));
    }
    printf("The  total number of searches in in interpolation search is %d",c3);
}

int main() {
    int choice;
    while(1) {
        printf("\n1. Linear Search \n2. Binary Search \n3. Interpolation Search \n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                linear_search();
                break;
            case 2:
                binary_search();
                break;
            case 3:
                interpolation_search();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
