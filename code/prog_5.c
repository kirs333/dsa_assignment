#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int dequeue(Queue* q) {
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

void createGraph() {
    int edges, u, v;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void displayGraph() {
    printf("\nAdjacency Matrix:\n");
    printf("  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void BFS(int start) {
    Queue q;
    initQueue(&q);
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    printf("\nBFS Traversal: ");
    visited[start] = 1;
    enqueue(&q, start);
    
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);
        
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

void DFSUtil(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            DFSUtil(i);
        }
    }
}

void DFS(int start) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    printf("\nDFS Traversal: ");
    DFSUtil(start);
    printf("\n");
}

int main() {
    int start;
    
    createGraph();
    displayGraph();
    
    printf("\nEnter starting vertex: ");
    scanf("%d", &start);
    
    BFS(start);
    DFS(start);
    
    return 0;
}
