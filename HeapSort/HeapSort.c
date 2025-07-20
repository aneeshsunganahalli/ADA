#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void swap(int *a, int *b) {
  int temp = *a; *a = *b; *b = temp;
}

void heapify(int *arr, int n, int i) {
  int largest = i, left = 2 * i + 1, right = 2 * i + 2;
  
  if (left < n) {
    count++;
    if (arr[left] > arr[largest]) largest = left;
  }
  
  if (right < n) {
    count++;
    if (arr[right] > arr[largest]) largest = right;
  }
  
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void buildMaxHeap(int *arr, int n) {
  // Bottom-up heap construction - start from last non-leaf node
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
}

int heapSort(int *arr, int n) {
  count = 0;
  
  // Build max heap using bottom-up construction
  buildMaxHeap(arr, n);
  
  // Extract elements from heap one by one
  for (int i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
  
  return count;
}

void plotter(int p) {
  int *a, n, i;
  char *filename = p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\HeapSort\\HeapWorstCase.txt" :
                   p == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\HeapSort\\HeapBestCase.txt" :
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\HeapSort\\HeapAvgCase.txt";
  FILE *fp = fopen(filename, "w");
  srand(time(NULL));
  
  for (n = 10; n < 1000; n = (n < 10 ? n * 10 : n + 100)) {
    a = (int*)malloc(n * sizeof(int));
    if (p == 1) {
      // Worst case: sorted array (for max heap)
      for (i = 0; i < n; i++) a[i] = i;
    } else if (p == 2) {
      // Best case: reverse sorted array
      for (i = 0; i < n; i++) a[i] = n - i;
    } else {
      // Average case: random array
      for (i = 0; i < n; i++) a[i] = rand() % n;
    }
    fprintf(fp, "%d\t%d\n", n, heapSort(a, n));
    free(a);
  }
  fclose(fp);
}

void tester() {
  printf("=== Heap Sort Tester ===\n");
  
  // Test Case 1: Random array
  int arr1[] = {4, 10, 3, 5, 1};
  int n1 = 5, *test1 = (int*)malloc(n1 * sizeof(int));
  for (int i = 0; i < n1; i++) test1[i] = arr1[i];
  int comp1 = heapSort(test1, n1);
  printf("Test 1 - Random array: [4,10,3,5,1], Comparisons=%d\n", comp1);
  printf("         Sorted result: [");
  for (int i = 0; i < n1; i++) printf("%d%s", test1[i], (i < n1-1) ? "," : "");
  printf("]\n");
  free(test1);
  
  // Test Case 2: Already sorted
  int arr2[] = {1, 2, 3, 4, 5};
  int n2 = 5, *test2 = (int*)malloc(n2 * sizeof(int));
  for (int i = 0; i < n2; i++) test2[i] = arr2[i];
  int comp2 = heapSort(test2, n2);
  printf("Test 2 - Already sorted: [1,2,3,4,5], Comparisons=%d\n", comp2);
  printf("         Sorted result: [");
  for (int i = 0; i < n2; i++) printf("%d%s", test2[i], (i < n2-1) ? "," : "");
  printf("]\n");
  free(test2);
  
  // Test Case 3: Reverse sorted
  int arr3[] = {5, 4, 3, 2, 1};
  int n3 = 5, *test3 = (int*)malloc(n3 * sizeof(int));
  for (int i = 0; i < n3; i++) test3[i] = arr3[i];
  int comp3 = heapSort(test3, n3);
  printf("Test 3 - Reverse sorted: [5,4,3,2,1], Comparisons=%d\n", comp3);
  printf("         Sorted result: [");
  for (int i = 0; i < n3; i++) printf("%d%s", test3[i], (i < n3-1) ? "," : "");
  printf("]\n");
  free(test3);
  
  // Test Case 4: Single element
  int arr4[] = {42};
  int n4 = 1, *test4 = (int*)malloc(n4 * sizeof(int));
  test4[0] = arr4[0];
  int comp4 = heapSort(test4, n4);
  printf("Test 4 - Single element: [42], Comparisons=%d\n", comp4);
  free(test4);
  
  // Test Case 5: Duplicate elements
  int arr5[] = {3, 3, 3, 3};
  int n5 = 4, *test5 = (int*)malloc(n5 * sizeof(int));
  for (int i = 0; i < n5; i++) test5[i] = arr5[i];
  int comp5 = heapSort(test5, n5);
  printf("Test 5 - All duplicates: [3,3,3,3], Comparisons=%d\n", comp5);
  free(test5);
  
  printf("\n=== Performance Analysis ===\n");
  printf("Best Case: O(n log n) - Bottom-up heap construction is efficient\n");
  printf("Worst Case: O(n log n) - Consistent performance\n");
  printf("Average Case: O(n log n) - Heap sort has guaranteed performance\n\n");
}

int main() {
  tester();
  printf("Generating analysis data...\n");
  plotter(1); plotter(2); plotter(3);
  printf("Heap sort analysis complete.\n");
  return 0;
}
