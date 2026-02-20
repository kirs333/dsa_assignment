# Program 7: Dijkstra's Shortest Path Algorithm

## Data Structures

Weighted graph using adjacency matrix.

```c
int graph[MAX][MAX];
int n;
```

Arrays for algorithm:
- `dist[]` - shortest distance from source
- `visited[]` - tracks visited vertices
- `parent[]` - stores path

## Functions

**`int minDistance(int dist[], int visited[])`**
- Finds vertex with minimum distance that is not visited
- Returns index of that vertex

**`void printPath(int parent[], int j)`**
- Recursively prints path from source to vertex j
- Uses parent array to backtrack

**`void dijkstra(int src)`**
- Main algorithm to find shortest paths from source
- Initializes distances to infinity
- Iteratively selects minimum distance vertex
- Updates distances of neighbors
- Prints results with paths

## Main Function

1. Takes number of vertices
2. Takes edges with weights
3. Takes source vertex
4. Calls dijkstra() to find shortest paths
5. Displays distance and path to all vertices

## How Dijkstra Works

Greedy algorithm:
1. Set distance of source to 0, others to infinity
2. Select unvisited vertex with minimum distance
3. Mark it visited
4. Update distances of its neighbors if shorter path found
5. Repeat until all vertices visited

## Sample Output

```
Enter number of vertices: 5
Enter number of edges: 7
Enter edges (u v weight):
0 1 4
0 2 1
1 3 1
2 1 2
2 3 5
3 4 3
1 4 6

Enter source vertex: 0

Vertex	Distance	Path
0	0		0 
1	3		0 2 1 
2	1		0 2 
3	4		0 2 1 3 
4	7		0 2 1 3 4 
```
