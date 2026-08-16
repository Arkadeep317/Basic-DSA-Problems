#include <stdio.h>

int n;
float v[10], w[10], r[10], x[10], W;

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void frac_knapsack() {
    int i;
    float U = W, tp = 0;

    for (i = 0; i < n; i++) {
        if (w[i] > U) 
            break;
        else {
            x[i] = 1.0;
            U -= w[i];
            tp += v[i];
        }
    }

    if (i < n) {
        x[i] = U / w[i];
        tp += x[i] * v[i];
    }

    printf("Fractions Taken: ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }
    printf("\nTotal Profit: %.2f\n", tp);
}

void main() {
    int i, j;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    printf("Enter values & corresponding weights: \n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &v[i], &w[i]);
    }
    
    printf("Enter Capacity: ");
    scanf("%f", &W);

    
    for (i = 0; i < n; i++) {
        r[i] = v[i] / w[i];
    }

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (r[j] < r[j + 1]) {
                swap(&r[j], &r[j + 1]);
                swap(&v[j], &v[j + 1]);
                swap(&w[j], &w[j + 1]);
            }
        }
    }

    frac_knapsack();
}



// 1) Calculate value/weight ratio:-**
// * For i=0 to n-1
//   * **2) Sort items in descending order of ratio**
// * For i=0 to n-2:
//   * For j=0 to n-i-2:
//     * if ratio[j] < ratio[j+1]:
//       * i) swap ratio[j] and ratio[j+1]
//       * ii) swap value[j] and value[j+1]
 //      * iii) swap weight[j] and weight[j+1]
 //* **3) Initialize:**
 //* remaining capacity = W , total profit = 0
 //* For i=0 to n-1:
  // * **4) Selects items greedily**
 //* For i=0 to n-1:
 //  * if weight[i] <= remaining capacity
 //    *      *      *    * else:
 //    * break
 //* **5) Take fraction of next item**
// * IF i<n:
//   *    *  * **6) Output result**
// * Print x[i] and total profit



//Enter the number of items: 3
//Enter values & corresponding weights:
//60 10
//100 20
//120 30
//Enter Capacity: 50
//Fractions Taken: 1.00 1.00 0.67
//Total Profit: 240.00

//(T=\text{Time\ to\ Calculate\ Ratios}+\text{Time\ to\ Sort}+\text{Time\ to\ Iterate\ and\ Pack}\)
//(T=O(n)+O(n\log n)+O(n)\)
//(T=O(n\log n)\)
