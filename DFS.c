#include <stdio.h>


int G[10][10], vis[10], n;


void DFS(int v){
    int j;
    vis[v] = 1;         
    printf("%d ", v);   
    fflush(stdout);     
    
    for(j = 1; j <= n; j++){ 
        if(G[v][j] == 1 && vis[j] == 0){ 
            DFS(j);     
        }
    }
}

int main(){
    int i, j, start;
    
   
    printf("Enter the no of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &G[i][j]);
        }
    }
    
   
    for(i = 1; i <= n; i++){
        vis[i] = 0;
    }
    
    
    printf("Enter the source vertex: ");
    scanf("%d", &start);
    
    
    printf("\nThe DFS Traversal is:\n");
    DFS(start);
    printf("\n");
    
    
    return 0;
}
// DFS (V) {
//   visited[v] = 1
//   print v
//   for j =1 to n
//     if adj[v][j] == 1 AND visited[j] == 0 then
//	    call DFS(J)
//	[End of if block & for loop]
//}

//1)read number of vertices(n) & adjececcy matrix(adj)
//2)for i =1 to n
//      visited[i] = 0
//3) input starting vertex start
//4)call DFS (start)
//5)stop 


     
//0 1 1  0
//1 0 0 1
//1 0 0 0
//0 1 0 0
//1



//T=O(V)+O(E)
//T=O(V+E)
