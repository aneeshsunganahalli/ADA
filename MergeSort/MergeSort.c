#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void merge(int *a, int left, int mid, int right) {
  int i, j, k, n1 = mid - left + 1, n2 = right - mid;
  int *L = (int*)malloc(n1 * sizeof(int));
  int *R = (int*)malloc(n2 * sizeof(int));
  
  for (i = 0; i < n1; i++) L[i] = a[left + i];
  for (j = 0; j < n2; j++) R[j] = a[mid + 1 + j];
  
  i = 0; j = 0; k = left;
  while (i < n1 && j < n2) {
    count++;
    if (L[i] <= R[j]) a[k++] = L[i++];
    else a[k++] = R[j++];
  }
  while (i < n1) a[k++] = L[i++];
  while (j < n2) a[k++] = R[j++];
  
  free(L); free(R);
}

void mergeSort(int *a, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
  }
}

int mergeSortWrapper(int *a, int n) {
  count = 0;
  mergeSort(a, 0, n - 1);
  return count;
}

void plotter(int p) {
  int *a, n, i;
  char *filename = p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\MergeSort\\MergeWorstCase.txt" :
                   p == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\MergeSort\\MergeBestCase.txt" :
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\MergeSort\\MergeAvgCase.txt";
  FILE *fp = fopen(filename, "w");
  srand(time(NULL));
  
  for (n = 10; n < 1000; n = (n < 10 ? n * 10 : n + 100)) {
    a = (int*)malloc(n * sizeof(int));
    if (p == 1) {
      // Worst case: reverse sorted
      for (i = 0; i < n; i++) a[i] = n - i;
    } else if (p == 2) {
      // Best case: already sorted
      for (i = 0; i < n; i++) a[i] = i;
    } else {
      // Average case: random
      for (i = 0; i < n; i++) a[i] = rand() % n;
    }
    fprintf(fp, "%d\t%d\n", n, mergeSortWrapper(a, n));
    free(a);
  }
  fclose(fp);
}

void tester() {
  printf("=== Merge Sort Tester ===\n");
  
  // Test Case 1: Random array
  int arr1[] = {5, 2, 8, 1, 9};
  int n1 = 5, *test1 = (int*)malloc(n1 * sizeof(int));
  for (int i = 0; i < n1; i++) test1[i] = arr1[i];
  int comp1 = mergeSortWrapper(test1, n1);
  printf("Test 1 - Random array: [5,2,8,1,9], Comparisons=%d\n", comp1);
  printf("         Sorted result: [");
  for (int i = 0; i < n1; i++) printf("%d%s", test1[i], (i < n1-1) ? "," : "");
  printf("]\n");
  free(test1);
  
  // Test Case 2: Already sorted
  int arr2[] = {1, 2, 3, 4, 5};
  int n2 = 5, *test2 = (int*)malloc(n2 * sizeof(int));
  for (int i = 0; i < n2; i++) test2[i] = arr2[i];
  int comp2 = mergeSortWrapper(test2, n2);
  printf("Test 2 - Already sorted: [1,2,3,4,5], Comparisons=%d\n", comp2);
  free(test2);
  
  // Test Case 3: Reverse sorted
  int arr3[] = {5, 4, 3, 2, 1};
  int n3 = 5, *test3 = (int*)malloc(n3 * sizeof(int));
  for (int i = 0; i < n3; i++) test3[i] = arr3[i];
  int comp3 = mergeSortWrapper(test3, n3);
  printf("Test 3 - Reverse sorted: [5,4,3,2,1], Comparisons=%d\n", comp3);
  printf("         Sorted result: [");
  for (int i = 0; i < n3; i++) printf("%d%s", test3[i], (i < n3-1) ? "," : "");
  printf("]\n");
  free(test3);
  
  // Test Case 4: Single element
  int arr4[] = {42};
  int n4 = 1, *test4 = (int*)malloc(n4 * sizeof(int));
  test4[0] = arr4[0];
  int comp4 = mergeSortWrapper(test4, n4);
  printf("Test 4 - Single element: [42], Comparisons=%d\n", comp4);
  free(test4);
  
  // Test Case 5: Duplicates
  int arr5[] = {3, 1, 3, 2, 1};
  int n5 = 5, *test5 = (int*)malloc(n5 * sizeof(int));
  for (int i = 0; i < n5; i++) test5[i] = arr5[i];
  int comp5 = mergeSortWrapper(test5, n5);
  printf("Test 5 - With duplicates: [3,1,3,2,1], Comparisons=%d\n", comp5);
  printf("         Sorted result: [");
  for (int i = 0; i < n5; i++) printf("%d%s", test5[i], (i < n5-1) ? "," : "");
  printf("]\n");
  free(test5);
  
  printf("\n=== Performance Analysis ===\n");
  printf("Best Case: O(n log n) - Divide and conquer approach\n");
  printf("Worst Case: O(n log n) - Guaranteed performance\n");
  printf("Average Case: O(n log n) - Stable and predictable\n");
  printf("Space Complexity: O(n) - Requires additional memory for merging\n\n");
}

int main() {
  tester();
  printf("Generating analysis data...\n");
  plotter(1); plotter(2); plotter(3);
  printf("Merge sort analysis complete.\n");
  return 0;
}
