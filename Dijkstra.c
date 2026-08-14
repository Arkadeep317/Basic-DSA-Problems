#include <stdio.h>
#define inf 999

int n, dist[10], pred[10];

void dijk(int s, int cost[10][10]) {
    int vis[10], count, min, u, i;
    for (i = 1; i <= n; i++) {
        dist[i] = cost[s][i];
        pred[i] = s;
        vis[i] = 0;
    }
    dist[s] = 0;
    vis[s] = 1;
    count = 2;

    while (count <= n) {
        min = inf;
        for (i = 1; i <= n; i++) {
            if (dist[i] < min && !vis[i]) {
                min = dist[i];
                u = i;
            }
        }
        vis[u] = 1;
        for (i = 1; i <= n; i++) {
            if ((dist[u] + cost[u][i] < dist[i]) && !vis[i]) {
                dist[i] = dist[u] + cost[u][i];
                pred[i] = u;
            }
        }
        count++;
    }
}

int main() {
    int s, i, j, cost[10][10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the cost adjacency Matrix: ");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) 
                cost[i][j] = inf;
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &s);
    
    dijk(s, cost);
    
    printf("\nShortest path:\n");
    for (i = 1; i <= n; i++) {
        if (i != s) {
            printf("%d -> %d => cost = %d\n", s, i, dist[i]);
        }
    }
    return 0;
}



// Dijkstra's Shortest Path Algorithm
// 1. Start
// 2. Read number of nodes (n), cost adjacency matrix & the source node (s).
// 3. **Initialize**:-
//   * set distance array:- dist[i] = cost[s][i]
//   * set predecessor array:- pred[i] = s
//   * set visited array:- vis[i] = 0
// 4. Set:-
//        dist[s] = 0
//        vis[s] = 1
//        count  = 2
//5. Repeat while count <=n
//   * set min = infinity
//   * Find the unvisited node with minimum distance & store it in U:-
//     for i=1 to n do:-
//         if ( dist[i] < min &&  !vis[i]) then
//              min = dist[i]
//                            [End of if block & for loop]
//    Mark node U as visited -> (vis[U] = 1)
// 6. Update shortest distance:-
//   For each node i
//     if (dist[U] + cost[U][i] < dist[i]  and node  i  not visited)
//     -> update dist[i] = dist[u] +cost[u][i]
//     ->set pred[i] = u
// 7. Increment Count
// 8. Display shortest distance from source node to all other nodes along with cost
// 9. Stop



//T={Time for Initialisation}+{Time for Extract-Min}+{Time for Decrease-Key}
//Timefor Initialisation}=O(V)
//{Timefor Extract-Min}=V. O(log V)=O(V\log V)
//{Time\ for\ Decrease-Key}=E. O(\log V)=O(E\log V)
//(T=O(V)+O(V\log V)+O(E\log V))
//(T=O((V+E)\log V))
