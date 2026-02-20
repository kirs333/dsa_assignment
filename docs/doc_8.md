# Program 8: Sorting Algorithms with Performance Analysis

## Data Structures

Uses arrays to store numbers. Global counters for performance metrics.

```c
int comparisons = 0;
int swaps = 0;
```

## Functions

**Sorting Algorithms:**

**`void bubbleSort(int arr[], int n)`**
- Repeatedly swaps adjacent elements if in wrong order
- Time: O(n²)

**`void selectionSort(int arr[], int n)`**
- Finds minimum element and places it at begining
- Time: O(n²)

**`void insertionSort(int arr[], int n)`**
- Builds sorted array one element at a time
- Time: O(n²) worst case, O(n) best case

**`void mergeSort(int arr[], int n)`**
- Divides array and merges sorted halves
- Time: O(n log n)

**Helper Functions:**
- `merge()` - merges two sorted subarrays
- `mergeSortHelper()` - recursive helper for merge sort
- `swap()` - swaps elements and increments swap counter
- `printArray()` - displays array

## Main Function

1. Takes N from user
2. Generates N random numbers between 1 and 1000
3. Shows menu to choose sorting algorithm
4. Displays array before sorting
5. Performs chosen sorting algorithm
6. Displays array after sorting
7. Shows performance metrics (comparisions and swaps)

## How Performance Counting Works

Global variables `comparisons` and `swaps` are incremented during sorting:
- Comparisons counted in if conditions
- Swaps counted in swap function
- Reset to 0 before each sort

Note: Merge sort doesnt count swaps as it uses temporary arrays.

## Sample Output

```
Enter number of elements (N): 10

Generating 10 random numbers in range [1, 1000]...

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice: 1

Before sorting:
234 567 123 890 456 789 321 654 987 210 

Using Bubble Sort...

After sorting:
123 210 234 321 456 567 654 789 890 987 

Performance Metrics:
Total Comparisons: 45
Total Swaps: 21
```

Another example:

```
Enter number of elements (N): 8

Generating 8 random numbers in range [1, 1000]...

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice: 4

Before sorting:
432 765 198 543 876 234 567 321 

Using Merge Sort...
Note: Merge Sort does not count swaps

After sorting:
198 234 321 432 543 567 765 876 

Performance Metrics:
Total Comparisons: 17
```
