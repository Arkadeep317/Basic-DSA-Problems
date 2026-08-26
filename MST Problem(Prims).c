#include <stdio.h>
#define MAX 20
#define INF 999

int cost[MAX][MAX], visited[MAX];

int prim(int n) {
    int i, j, k, min, mincost = 0, u = 1, v = 1;
    
    for (i = 1; i <= n; i++) 
        visited[i] = 0;
        
    visited[1] = 1;
    printf("\nSelected Edges:\n");
    
    for (k = 1; k < n; k++) {
        min = INF;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    if (visited[i] != 0 && visited[j] == 0 && cost[i][j] != INF) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("Edge: %d (%d -> %d) cost = %d\n", k, u, v, min);
        visited[v] = 1;
        mincost = mincost + min;
    }
    return mincost;
}

int main() {
    int n, i, j, mincost;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter cost adjacency Matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INF;
            }
        }
    }
    
    mincost = prim(n);
    printf("Minimum cost = %d\n", mincost);
    return 0;
}



//## Algorithm: PRIM(G, n)
// INPUT:
//  G ->  Cost adjacency matrix
//  n ->  number of vertices
//### Steps:
// 1. Set visited[1....n] <-0
// 2. set [min cost] <- 0
// 3. visited[1] <- 1 // We want to start from vertex 1
// 4. For K = 1 to n-1 do
//        min = infinty sign
//    For i = 1 to n do
// 7. For j = 1 to n do
// 8.   If G[i][j] < min then
// 9.     If G[i][j] != infinity and visited[i] = 1 and visited[j] = 0
//           min<-G[i][j]
//           u<-i
//           v<-j
//  [End of all if block & all for loop except k loop]
// 10. Print "Edge: ", U, " - ", V, "Cost: ", min
// 11.visited[v]<-1
// 12.mincost <- mincost+ min
// 13. [End of K loop]
// 14. Return Mincost
 //15. End
 
// 0 2 4 0
//2 0 1 7
//4 1 0 3
//0 7 3 0


//T=O(V2)+O(E)+O(V2)
//T=O(V2)
