#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary(int *a, int k, int n) {
  int low = 0, high = n - 1, count = 0, mid;
  while (low <= high) {
    count++;
    mid = low + (high - low) / 2;
    if (a[mid] == k) return count;
    if (a[mid] < k) low = mid + 1;
    else high = mid - 1;
  }
  return count;
}

void plotter(int p) {
  int *a, n, i;
  FILE *fp = fopen(p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Searching\\BinaryWorstCase.txt" : 
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Searching\\BinaryBestCase.txt", "w");
  for (n = 10; n < 1000; n = (n < 10 ? n * 10 : n + 100)) {
    a = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) a[i] = i;
    fprintf(fp, "%d\t%d\n", n, binary(a, p == 1 ? n : a[n/2], n));
    free(a);
  }
  fclose(fp);
}

void tester() {
  printf("=== Binary Search Tester ===\n");
  
  // Test array (sorted)
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 67, 78};
  int n = 10;
  
  // Test Case 1: Element at middle (Best case)
  int key1 = 16, result1 = binary(arr, key1, n);
  printf("Test 1 - Middle element: Key=%d, Operations=%d %s\n", 
         key1, result1, (result1 <= 4) ? "PASS" : "FAIL");
  
  // Test Case 2: Element at beginning
  int key2 = 2, result2 = binary(arr, key2, n);
  printf("Test 2 - First element: Key=%d, Operations=%d %s\n", 
         key2, result2, (result2 <= 4) ? "PASS" : "FAIL");
  
  // Test Case 3: Element at end
  int key3 = 78, result3 = binary(arr, key3, n);
  printf("Test 3 - Last element: Key=%d, Operations=%d %s\n", 
         key3, result3, (result3 <= 4) ? "PASS" : "FAIL");
  
  // Test Case 4: Element not found (Worst case)
  int key4 = 99, result4 = binary(arr, key4, n);
  printf("Test 4 - Not found: Key=%d, Operations=%d %s\n", 
         key4, result4, (result4 == 4) ? "PASS" : "FAIL");
  
  // Test Case 5: Single element array
  int single[] = {42};
  int key5 = 42, result5 = binary(single, key5, 1);
  printf("Test 5 - Single element: Key=%d, Operations=%d %s\n", 
         key5, result5, (result5 == 1) ? "PASS" : "FAIL");
  
  printf("\n=== Performance Analysis ===\n");
  printf("Best Case: O(1) - Element at middle position\n");
  printf("Worst Case: O(log n) - Element not found or at leaf\n");
  printf("Average Case: O(log n)\n\n");
}

int main() {
  tester();
  printf("Generating analysis data...\n");
  plotter(1);
  plotter(2);
  printf("Data generation complete.\n");
  return 0;
}