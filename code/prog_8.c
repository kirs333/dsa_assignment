#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;
int swaps = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(&arr[i], &arr[minIdx]);
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSort(int arr[], int n) {
    mergeSortHelper(arr, 0, n - 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice;
    
    printf("Enter number of elements (N): ");
    scanf("%d", &n);
    
    int original[n];
    int arr[n];
    
    srand(time(NULL));
    printf("\nGenerating %d random numbers in range [1, 1000]...\n", n);
    for (int i = 0; i < n; i++) {
        original[i] = (rand() % 1000) + 1;
    }
    
    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    for (int i = 0; i < n; i++) {
        arr[i] = original[i];
    }
    
    printf("\nBefore sorting:\n");
    printArray(arr, n);
    
    comparisons = 0;
    swaps = 0;
    
    switch (choice) {
        case 1:
            printf("\nUsing Bubble Sort...\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("\nUsing Selection Sort...\n");
            selectionSort(arr, n);
            break;
        case 3:
            printf("\nUsing Insertion Sort...\n");
            insertionSort(arr, n);
            break;
        case 4:
            printf("\nUsing Merge Sort...\n");
            mergeSort(arr, n);
            printf("Note: Merge Sort does not count swaps\n");
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
    
    printf("\nAfter sorting:\n");
    printArray(arr, n);
    
    printf("\nPerformance Metrics:\n");
    printf("Total Comparisons: %d\n", comparisons);
    if (choice != 4) {
        printf("Total Swaps: %d\n", swaps);
    }
    
    return 0;
}
