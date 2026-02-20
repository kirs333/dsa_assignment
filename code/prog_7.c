#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF INT_MAX

int graph[MAX][MAX];
int n;

int minDistance(int dist[], int visited[]) {
    int min = INF;
    int minIndex = -1;
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    
    return minIndex;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }
    
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX];
    int parent[MAX];
    
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited);
        
        if (u == -1) break;
        
        visited[u] = 1;
        
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 && 
                dist[u] != INF && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    printf("\nVertex\tDistance\tPath\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", i);
        if (dist[i] == INF) {
            printf("INF\t\tNo path\n");
        } else {
            printf("%d\t\t", dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
}

int main() {
    int edges, u, v, weight, src;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight;
    }
    
    printf("Enter source vertex: ");
    scanf("%d", &src);
    
    dijkstra(src);
    
    return 0;
}
