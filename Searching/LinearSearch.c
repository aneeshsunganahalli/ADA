#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear(int *a, int k, int n) {
  int i, count = 0;
  for (i = 0; i <= n; i++) {
    count++;
    if (a[i] == k) return count;
  }
  return count;
}

void plotter(int p) {
  int *a, n, i;
  FILE *fp = fopen(p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Searching\\WorstCase.txt" : 
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Searching\\BestCase.txt", "w");
  srand(time(NULL));
  for (n = 10; n < 1000; n = (n < 10 ? n * 10 : n + 100)) {
    a = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) a[i] = rand() % n;
    fprintf(fp, "%d\t%d\n", n, linear(a, p == 1 ? (a[n-1] = -1) : a[0], n));
    free(a);
  }
  fclose(fp);
}

void tester() {
  printf("=== Linear Search Tester ===\n");
  
  // Test Case 1: Element found at beginning
  int arr1[] = {5, 10, 15, 20, 25};
  int n1 = 5, key1 = 5;
  int result1 = linear(arr1, key1, n1-1);
  printf("Test 1 - Element at beginning: Array[%d], Key=%d, Operations=%d %s\n", 
         n1, key1, result1, (result1 == 1) ? "✓" : "✗");
  
  // Test Case 2: Element found at end
  int arr2[] = {5, 10, 15, 20, 25};
  int n2 = 5, key2 = 25;
  int result2 = linear(arr2, key2, n2-1);
  printf("Test 2 - Element at end: Array[%d], Key=%d, Operations=%d %s\n", 
         n2, key2, result2, (result2 == 5) ? "✓" : "✗");
  
  // Test Case 3: Element not found
  int arr3[] = {5, 10, 15, 20, 25};
  int n3 = 5, key3 = 30;
  int result3 = linear(arr3, key3, n3-1);
  printf("Test 3 - Element not found: Array[%d], Key=%d, Operations=%d %s\n", 
         n3, key3, result3, (result3 == 5) ? "✓" : "✗");
  
  // Test Case 4: Single element array - found
  int arr4[] = {42};
  int n4 = 1, key4 = 42;
  int result4 = linear(arr4, key4, n4-1);
  printf("Test 4 - Single element found: Array[%d], Key=%d, Operations=%d %s\n", 
         n4, key4, result4, (result4 == 1) ? "✓" : "✗");
  
  // Test Case 5: Single element array - not found
  int arr5[] = {42};
  int n5 = 1, key5 = 50;
  int result5 = linear(arr5, key5, n5-1);
  printf("Test 5 - Single element not found: Array[%d], Key=%d, Operations=%d %s\n", 
         n5, key5, result5, (result5 == 1) ? "✓" : "✗");
  
  printf("\n=== Performance Analysis ===\n");
  printf("Best Case: O(1) - Element found at first position\n");
  printf("Worst Case: O(n) - Element not found or at last position\n");
  printf("Average Case: O(n/2) - Element found at middle position\n");
}

int main() {
  tester();
  printf("\nGenerating analysis data...\n");
  plotter(1);
  plotter(2);
  printf("Analysis complete! Check WorstCase.txt and BestCase.txt\n");
  return 0;
}