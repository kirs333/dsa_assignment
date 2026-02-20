# Program 6: Min Heap and Max Heap Builder

## Data Structures

Uses arrays to store heap data. No special structure needed as heap is represented as array.

## Functions

**`void swap(int* a, int* b)`**
- Swaps two integers

**`void heapifyMax(int arr[], int n, int i)`**
- Maintains max heap property for subtree rooted at index i
- Finds largest among node and its children
- Swaps if needed and recursively heapifies

**`void heapifyMin(int arr[], int n, int i)`**
- Maintains min heap property for subtree rooted at index i
- Finds smallest among node and its childern
- Swaps if needed and recursively heapifies

**`void buildMaxHeap(int arr[], int n)`**
- Builds max heap from unsorted array
- Starts from last non-leaf node and heapifies all nodes

**`void buildMinHeap(int arr[], int n)`**
- Builds min heap from unsorted array
- Starts from last non-leaf node and heapifies all nodes

**`void printArray(int arr[], int n)`**
- Prints array elements

## Main Function

1. Takes number of elements as input
2. Takes array elements from user
3. Creates copies for max heap and min heap
4. Builds max heap using buildMaxHeap()
5. Builds min heap using buildMinHeap()
6. Displays original array and both heaps

## How Heap Building Works

Heap is built bottom up:
1. Start from last non-leaf node (n/2 - 1)
2. Heapify each node going upwards
3. Each heapify ensures subtree satisfies heap property

Max Heap: Parent >= Children
Min Heap: Parent <= Children

## Sample Output

```
Enter number of elements: 7
Enter 7 elements:
12
45
23
51
19
8
30

Original array: 12 45 23 51 19 8 30 

Max Heap: 51 45 30 12 19 8 23 

Min Heap: 8 19 12 51 45 23 30 
```

Another example:

```
Enter number of elements: 5
Enter 5 elements:
5
3
8
1
9

Original array: 5 3 8 1 9 

Max Heap: 9 5 8 1 3 

Min Heap: 1 3 8 5 9 
```
