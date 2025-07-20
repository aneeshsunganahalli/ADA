#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int selectionSort(int *a, int n) {
  int i, j, min_idx, count = 0, temp;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      count++;
      if (a[j] < a[min_idx]) min_idx = j;
    }
    if (min_idx != i) {
      temp = a[i]; 
      a[i] = a[min_idx]; 
      a[min_idx] = temp;
    }
  }
  return count;
}

void plotter(int p) {
  int *a, n, i;
  char *filename = p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\SelectionWorstCase.txt" :
                   p == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\SelectionBestCase.txt" :
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\SelectionAvgCase.txt";
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
    fprintf(fp, "%d\t%d\n", n, selectionSort(a, n));
    free(a);
  }
  fclose(fp);
}

void tester() {
  printf("=== Selection Sort Tester ===\n");
  
  // Test Case 1: Already sorted
  int arr1[] = {1, 2, 3, 4, 5};
  int n1 = 5, *test1 = (int*)malloc(n1 * sizeof(int));
  for (int i = 0; i < n1; i++) test1[i] = arr1[i];
  int comp1 = selectionSort(test1, n1);
  printf("Test 1 - Already sorted: [1,2,3,4,5], Comparisons=%d %s\n", 
         comp1, (comp1 == 10) ? "✓" : "✗");
  free(test1);
  
  // Test Case 2: Reverse sorted
  int arr2[] = {5, 4, 3, 2, 1};
  int n2 = 5, *test2 = (int*)malloc(n2 * sizeof(int));
  for (int i = 0; i < n2; i++) test2[i] = arr2[i];
  int comp2 = selectionSort(test2, n2);
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
  int comp3 = selectionSort(test3, n3);
  printf("Test 3 - Random array: [3,1,4,2,5], Comparisons=%d %s\n", 
         comp3, (comp3 == 10) ? "✓" : "✗");
  printf("         Sorted result: [");
  for (int i = 0; i < n3; i++) printf("%d%s", test3[i], (i < n3-1) ? "," : "");
  printf("]\n");
  free(test3);
  
  // Test Case 4: All same elements
  int arr4[] = {7, 7, 7, 7};
  int n4 = 4, *test4 = (int*)malloc(n4 * sizeof(int));
  for (int i = 0; i < n4; i++) test4[i] = arr4[i];
  int comp4 = selectionSort(test4, n4);
  printf("Test 4 - All same: [7,7,7,7], Comparisons=%d %s\n", 
         comp4, (comp4 == 6) ? "✓" : "✗");
  free(test4);
  
  printf("\n=== Performance Analysis ===\n");
  printf("Best Case: O(n²) - Already sorted (still needs to find minimum)\n");
  printf("Worst Case: O(n²) - Any configuration\n");
  printf("Average Case: O(n²) - Selection sort has consistent behavior\n\n");
}

int main() {
  tester();
  printf("Generating analysis data...\n");
  plotter(1); plotter(2); plotter(3);
  printf("Selection sort analysis complete.\n");
  return 0;
}
