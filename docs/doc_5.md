# Program 5: Graph Traversal using BFS and DFS

## Data Structures

Graph is represented using adjacency matrix.

```c
int graph[MAX][MAX];
int visited[MAX];
int n;
```

Queue structure for BFS:
```c
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;
```

## Functions

**Graph Creation:**
- `createGraph()` - takes input for vertices and edges, builds adjacency matrix
- `displayGraph()` - prints adjacency matrix

**Queue Operations:**
- `initQueue()` - initializes queue
- `enqueue()` - adds element
- `dequeue()` - removes element
- `isEmpty()` - checks if queue empty

**Traversal Functions:**
- `BFS(int start)` - breadth first search using queue
- `DFS(int start)` - depth first search wrapper
- `DFSUtil(int vertex)` - recursive DFS helper

## Main Function

1. Creates graph by taking input
2. Displays adjacency matrix
3. Takes starting vertex
4. Performs BFS traversal
5. Performs DFS traversal

## How BFS Works

Uses queue to visit nodes level by level:
1. Mark start vertex as visited and enqueue
2. Dequeue vertex and print it
3. Enqueue all unvisited neighbors
4. Repeat until queue is emty

## How DFS Works

Uses recursion to go deep first:
1. Mark current vertex as visited and print
2. Recursively visit all unvisited neighbors
3. Backtrack when no unvisited neighbors

## Sample Output

```
Enter number of vertices: 5
Enter number of edges: 6
Enter edges (u v):
0 1
0 2
1 3
1 4
2 4
3 4

Adjacency Matrix:
  0 1 2 3 4 
0 0 1 1 0 0 
1 1 0 0 1 1 
2 1 0 0 0 1 
3 0 1 0 0 1 
4 0 1 1 1 0 

Enter starting vertex: 0

BFS Traversal: 0 1 2 3 4 

DFS Traversal: 0 1 3 4 2 
```
