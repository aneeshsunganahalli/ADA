#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertionSort(int *a, int n) {
  int i, j, key, count = 0;
  for (i = 1; i < n; i++) {
    key = a[i];
    j = i - 1;
    while (j >= 0) {
      count++;
      if (a[j] > key) {
        a[j + 1] = a[j];
        j--;
      } else break;
    }
    a[j + 1] = key;
  }
  return count;
}

void plotter(int p) {
  int *a, n, i;
  char *filename = p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\InsertionWorstCase.txt" :
                   p == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\InsertionBestCase.txt" :
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\InsertionAvgCase.txt";
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
    fprintf(fp, "%d\t%d\n", n, insertionSort(a, n));
    free(a);
  }
  fclose(fp);
}

void tester() {
  printf("=== Insertion Sort Tester ===\n");
  
  // Test Case 1: Already sorted (Best case)
  int arr1[] = {1, 2, 3, 4, 5};
  int n1 = 5, *test1 = (int*)malloc(n1 * sizeof(int));
  for (int i = 0; i < n1; i++) test1[i] = arr1[i];
  int comp1 = insertionSort(test1, n1);
  printf("Test 1 - Already sorted: [1,2,3,4,5], Comparisons=%d %s\n", 
         comp1, (comp1 == 4) ? "✓" : "✗");
  free(test1);
  
  // Test Case 2: Reverse sorted (Worst case)
  int arr2[] = {5, 4, 3, 2, 1};
  int n2 = 5, *test2 = (int*)malloc(n2 * sizeof(int));
  for (int i = 0; i < n2; i++) test2[i] = arr2[i];
  int comp2 = insertionSort(test2, n2);
  printf("Test 2 - Reverse sorted: [5,4,3,2,1], Comparisons=%d %s\n", 
         comp2, (comp2 == 10) ? "✓" : "✗");
  printf("         Sorted result: [");
  for (int i = 0; i < n2; i++) printf("%d%s", test2[i], (i < n2-1) ? "," : "");
  printf("]\n");
  free(test2);
  
  // Test Case 3: Random array
  int arr3[] = {3, 1, 4, 2, 5};
  int n3 = 5, *test3 = (int*)malloc(n3 * sizeof(int));
  for (int i = 0; i < n3; i++) test3[i] = arr3[i];
  int comp3 = insertionSort(test3, n3);
  printf("Test 3 - Random array: [3,1,4,2,5], Comparisons=%d\n", comp3);
  printf("         Sorted result: [");
  for (int i = 0; i < n3; i++) printf("%d%s", test3[i], (i < n3-1) ? "," : "");
  printf("]\n");
  free(test3);
  
  // Test Case 4: Single element
  int arr4[] = {42};
  int n4 = 1, *test4 = (int*)malloc(n4 * sizeof(int));
  test4[0] = arr4[0];
  int comp4 = insertionSort(test4, n4);
  printf("Test 4 - Single element: [42], Comparisons=%d %s\n", 
         comp4, (comp4 == 0) ? "✓" : "✗");
  free(test4);
  
  printf("\n=== Performance Analysis ===\n");
  printf("Best Case: O(n) - Already sorted\n");
  printf("Worst Case: O(n²) - Reverse sorted\n");
  printf("Average Case: O(n²) - Random data\n\n");
}

int main() {
  tester();
  printf("Generating analysis data...\n");
  plotter(1); plotter(2); plotter(3);
  printf("Insertion sort analysis complete.\n");
  return 0;
}
