#include <stdio.h>


int p[100], slot[100], d[100], id[100]; 

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int JobSequencing(int n) {
    int c = 0, sump = 0, i, K, dmax = d[0];
    
    
    for (i = 1; i < n; i++) {
        if (dmax < d[i]) 
            dmax = d[i];
    }
    printf("Max deadline = %d", dmax);
    
    
    for (i = 1; i <= dmax; i++) {
        slot[i] = -1;
    }
    
    
    for (i = 0; i < n; i++) {
        K = d[i];
        while (K > 0) {
            if (slot[K] == -1) {
                slot[K] = i;
                sump += p[i];
                c++;
                break;
            }
            K--;
        }
        if (c == dmax) 
            break;
    }
    
    
    printf("\nSolution Vector: \n");
    for (i = 1; i <= dmax; i++) {
        if (slot[i] != -1) {
            printf("j%d %d %d\n", id[slot[i]], p[slot[i]], d[slot[i]]);
        }
    }
    return sump;
}

int main() {
    int n, i, j;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter Job id:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &id[i]);
    }
    
    printf("Enter profit:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    printf("Enter deadlines: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j] < p[j + 1]) {
                swap(&p[j], &p[j + 1]);
                swap(&id[j], &id[j + 1]);
                swap(&d[j], &d[j + 1]);
            }
        }
    }
    
    int total_profit = JobSequencing(n);
    printf("\nTotal Profit: %d\n", total_profit);
    
    return 0;
}




//Step-1: Input job details**
// * Read n
// * **For** i=0 to n-1
//   * Read id[i]
// * **For** i=0 to n-1
//   * Read profit[i]
// * **For** i=0 to n-1
//   * Read deadline[i]
//### **Step-2: Sort Jobs in Descending order of profit**
// * **For** i=0 to n-2
//   * **For** j=0 to n-i-2
//     * **If** profit[j] < profit[j+1]
//       * swap profit[j] & profit[j+1]
//       * swap id[j] & id[j+1]
//       * swap deadline[j] & deadline[j+1]
// * [End of if & both for Loop]
//### **Step-3: Find maximum deadline**
// * set dmax = deadline[0]
// * **For** i=1 to n-1
//   * **if** dmax < deadline[i]
//     * set dmax = deadline[i]
// * [End of For loop & if]
//### **Step-4: Initialize slot array**
// * **For** i=1 to dmax
//   * set slot[i] = -1
// * set total\_profit = 0 , count = 0
//### **Step-5: Allocate Jobs greedily**
// * **For** i=0 to n-1
//   * set k = deadline[i]
//   * **While** k > 0
//     * **if** slot[k] == -1
//       *        *        *        * break
 //    * **else**
 //      *    * [End of If & while]
 //  * **if** count == dmax
 //    * break
 //* [End of For]
//**Step-6: Print solution Vector**
// * **For** i=1 to dmax
//   * **if** slot[i] != -1
//     * Print id[slot[i]], profit[slot[i]], deadline[slot[i]]
//**Step-7: print total profit**





//Enter the number of elements: 4
//Enter Job id:
//1 2 3 4
//Enter profit:
//100 20 40 60
//Enter deadlines: 2 1 2 1
//Max deadline = 2
//Solution Vector:
//j4 60 1
//j1 100 2

//Total Profit: 160


//(T=\text{Time\ to\ Sort\ Jobs}+\text{Time\ to\ Slot\ Jobs}\)\
//({Time\ to\ Sort\ Jobs}=O(n\log n)\)
//T=O(NLOGN)+O(N^2)
//T=O(N^2)
