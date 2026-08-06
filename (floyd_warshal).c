
#include <stdio.h>
#define INF 999

int n, cost[10][10], d[10][10], path[10][10];

void floyd() {
    int i, j, k;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            d[i][j] = cost[i][j];
            if(i == j || cost[i][j] == INF)
                path[i][j] = 0;
            else
                path[i][j] = i;
        }
    }
    
    for(k = 1; k <= n; k++) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if((d[i][k] + d[k][j]) < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
    
    printf("Shortest Distance Matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }
    
    printf("\nPath Matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            printf("%d\t", path[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter cost matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }
    
    floyd();
    return 0;
}



//1) start
// 2)read number of nodes(n), cost matrix
// 3)initialize distance & path matreix:-
//   for i = 1 to n do :-
//      for j = 1 to n do:-
//        d[i][j] = cost[i][j];
//        if i = j or cost [i][j] = infinity 
//             set path[i][j] = 0
//        else
//	        set path[i][j] = i
//  4)repeat for k = 1 to n do:
//           for i = 1 to n do:
//		     for j = 1 to n do:
//			if d[i][j] >d[i][k] + d[k][j]
//			  ->update d[i][j] = d[i][k] + d[k][j]
//			  ->set path[i][j] = k
//  5) display the shortest distance matrix and path matrix
//  6)End

/*  time complexity:
theta(n^3). Because the three nested loops run precisely n times each,
 regardless of the edge distribution or structure of the graph.
		

	  		        
