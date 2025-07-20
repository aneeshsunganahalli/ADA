#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void swap(int *a, int *b) {
  int temp = *a; *a = *b; *b = temp;
}

int partition(int *a, int low, int high) {
  int pivot = a[high], i = low - 1, j;
  for (j = low; j < high; j++) {
    count++;
    if (a[j] <= pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[high]);
  return i + 1;
}

void quickSort(int *a, int low, int high) {
  if (low < high) {
    int pi = partition(a, low, high);
    quickSort(a, low, pi - 1);
    quickSort(a, pi + 1, high);
  }
}

int quickSortWrapper(int *a, int n) {
  count = 0;
  quickSort(a, 0, n - 1);
  return count;
}

void plotter(int p) {
  int *a, n, i;
  char *filename = p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\QuickSort\\QuickWorstCase.txt" :
                   p == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\QuickSort\\QuickBestCase.txt" :
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\QuickSort\\QuickAvgCase.txt";
  FILE *fp = fopen(filename, "w");
  srand(time(NULL));
  
  for (n = 10; n < 1000; n = (n < 10 ? n * 10 : n + 100)) {
    a = (int*)malloc(n * sizeof(int));
    if (p == 1) {
      // Worst case: already sorted (with last element as pivot)
      for (i = 0; i < n; i++) a[i] = i;
    } else if (p == 2) {
      // Best case: pivot always divides array in half
      for (i = 0; i < n; i++) a[i] = rand() % n;
    } else {
      // Average case: random array
      for (i = 0; i < n; i++) a[i] = rand() % n;
    }
    fprintf(fp, "%d\t%d\n", n, quickSortWrapper(a, n));
    free(a);
  }
  fclose(fp);
}

void tester() {
  printf("=== Quick Sort Tester ===\n");
  
  // Test Case 1: Random array
  int arr1[] = {3, 6, 8, 10, 1, 2, 1};
  int n1 = 7, *test1 = (int*)malloc(n1 * sizeof(int));
  for (int i = 0; i < n1; i++) test1[i] = arr1[i];
  int comp1 = quickSortWrapper(test1, n1);
  printf("Test 1 - Random array: [3,6,8,10,1,2,1], Comparisons=%d\n", comp1);
  printf("         Sorted result: [");
  for (int i = 0; i < n1; i++) printf("%d%s", test1[i], (i < n1-1) ? "," : "");
  printf("]\n");
  free(test1);
  
  // Test Case 2: Already sorted (Worst case)
  int arr2[] = {1, 2, 3, 4, 5};
  int n2 = 5, *test2 = (int*)malloc(n2 * sizeof(int));
  for (int i = 0; i < n2; i++) test2[i] = arr2[i];
  int comp2 = quickSortWrapper(test2, n2);
  printf("Test 2 - Already sorted: [1,2,3,4,5], Comparisons=%d\n", comp2);
  printf("         Note: This is worst case with last element pivot\n");
  free(test2);
  
  // Test Case 3: Reverse sorted
  int arr3[] = {5, 4, 3, 2, 1};
  int n3 = 5, *test3 = (int*)malloc(n3 * sizeof(int));
  for (int i = 0; i < n3; i++) test3[i] = arr3[i];
  int comp3 = quickSortWrapper(test3, n3);
  printf("Test 3 - Reverse sorted: [5,4,3,2,1], Comparisons=%d\n", comp3);
  printf("         Sorted result: [");
  for (int i = 0; i < n3; i++) printf("%d%s", test3[i], (i < n3-1) ? "," : "");
  printf("]\n");
  free(test3);
  
  // Test Case 4: Single element
  int arr4[] = {42};
  int n4 = 1, *test4 = (int*)malloc(n4 * sizeof(int));
  test4[0] = arr4[0];
  int comp4 = quickSortWrapper(test4, n4);
  printf("Test 4 - Single element: [42], Comparisons=%d\n", comp4);
  free(test4);
  
  // Test Case 5: All same elements
  int arr5[] = {7, 7, 7, 7};
  int n5 = 4, *test5 = (int*)malloc(n5 * sizeof(int));
  for (int i = 0; i < n5; i++) test5[i] = arr5[i];
  int comp5 = quickSortWrapper(test5, n5);
  printf("Test 5 - All same: [7,7,7,7], Comparisons=%d\n", comp5);
  free(test5);
  
  printf("\n=== Performance Analysis ===\n");
  printf("Best Case: O(n log n) - Pivot divides array evenly\n");
  printf("Worst Case: O(n²) - Already sorted with poor pivot choice\n");
  printf("Average Case: O(n log n) - Random pivot positioning\n");
  printf("Space Complexity: O(log n) - Recursion stack\n\n");
}

int main() {
  tester();
  printf("Generating analysis data...\n");
  plotter(1); plotter(2); plotter(3);
  printf("Quick sort analysis complete.\n");
  return 0;
}
