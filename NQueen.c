#include <stdio.h>
#include <stdlib.h>

int x[20];   


int place(int k, int i)
{
    int j;

    for(j = 1; j <= k - 1; j++)
    {
        
        if((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    }

    return 1;
}


void nqueen(int k, int n)
{
    int i, j;

    for(i = 1; i <= n; i++)
    {
        if(place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                printf("\nSolution:\n");

                for(j = 1; j <= n; j++)
                {
                    printf("Queen %d placed at Row %d Column %d\n",
                           j, j, x[j]);
                }

                
                printf("\nChessboard:\n");

                for(j = 1; j <= n; j++)
                {
                    int col;
                    for(col = 1; col <= n; col++)
                    {
                        if(x[j] == col)
                            printf(" Q ");
                        else
                            printf(" . ");
                    }
                    printf("\n");
                }
            }
            else
            {
                nqueen(k + 1, n);
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    nqueen(1, n);

    return 0;
}



//place(k,i) {kth queen place at coiumn i
//     for j = 1 to k-1 do
//      if (x[j] == i) or (Abs(x[j] - i)== Abs(j-k))
//        then return false
//     return true
//}
//N queen's(k,n)
//  for i =1 to n do
//      if place(k,i) then{
//        set x[k] -i
//        if (k==n) then print x[1 to n]
//        else N-queen (k+1, n)
//     }
//   }
//}


/* time complexity:
choice for 1st Queen = n
choice of 2nd Queen = n-1
choice of 3rd Queen = n-2
and so on...

so, total no. of choices = n*(n-1)*(n-2)*(n-3)*...*1
						= n!
T(n) = O(n!)

