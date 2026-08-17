#include <stdio.h>
#include <limits.h>

int m[100][100], s[100][100];

void print_optimal_parenthesis(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        print_optimal_parenthesis(i, s[i][j]);
        print_optimal_parenthesis(s[i][j] + 1, j);
        printf(")");
    }
}

void matrix_chain_order(int d[], int n)
{
    int i, j, k, l;

    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] +
                        d[i - 1] * d[k] * d[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    int n, i, j;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int d[n + 1];

    printf("Enter dimensions array: ");
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &d[i]);
    }

    matrix_chain_order(d, n);

    printf("\nMinimum scalar multiplications = %d\n", m[1][n]);

    printf("Optimal Parenthesization = ");
    print_optimal_parenthesis(1, n);
    printf("\n");

    printf("\nM Table:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i > j)
                printf("-\t");
            else
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nS Table:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i >= j)
                printf("-\t");
            else
                printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    return 0;
}




//### Algorithm
//#### **Function: Print_optimal_parenthesis(i, j)
// 1. if i == j:
  //  then Print "A", i
 //2. else
  //   Print "("
    // call Print_optimal_parenthesis(i, s[i][j])
     //call Print_optimal_parenthesis(s[i][j]+1, j)
     //Print ")"
 //3. [End of If]
 // Function: matrix_chain_order(int d[], int n)
 //1. Initialize diagonal Elements
 //  For i=1 to n:
   
// 2. Step-2:- Calculate minimal cost for different chain Length
//    For l=2  to  n:
//        For  i=1  to n-l+1:
//           j = i+l-1
//           m[i][j] = \infty (very large number/INT_MAX)
//            For  k=i to j-1:
//               q = m[i][k] + m[k+1][j] + (d[i-1] \cdot d[k] \cdot d[j])
//               if  q < m[i][j]:
//                   m[i][j] = q
//                 s[i][j] = k
//           [End of For & if]
//    [End of For]
//[End of For]
//### Main Function
 //1. Take number of matrix as n
 //2. Take input of dimension array as d[i]
  // *[if number of matrices is n then dimension array should contains n+1 dimensions]*
 //3. call matrix_chain_order(d, n)
 //4. Print minimal scalar multiplication
 //5. call print_optimal_parenthesis(1, n)
 //6. Print M table
 //7. Print s table
 
 
 
//Outer Loop (k): Runs exactly n times.
//Middle Loop (i): Runs exactly n times for every single iteration of k.
//Inner Loop j: Runs exactly n times for every single iteration of i.
//O(N^3)
