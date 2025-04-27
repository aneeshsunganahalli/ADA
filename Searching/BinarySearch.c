#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

int binary_recursive(int *a, int low, int high, int k) {
  count++;
  
  if (low > high)
    return count;
    
  int mid = low + (high - low) / 2;
  
  if (*(a + mid) == k)
    return count;
    
  if (*(a + mid) < k)
    return binary_recursive(a, mid + 1, high, k);
  else
    return binary_recursive(a, low, mid - 1, k);
}

int binary(int *a, int k, int n) {
  count = 0;
  return binary_recursive(a, 0, n - 1, k);
}

void plotter(int p) {
  int *a, n, key, i, res;
  FILE *fp;
  
  // Make sure we're using the correct file for each case
  if (p == 1) // Worst case
    fp = fopen("C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Searching\\BinaryWorstCase.txt", "w");
  else // Best case 
    fp = fopen("C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Searching\\BinaryBestCase.txt", "w");
    
  srand(time(NULL));
  
  for (n = 10; n < 1000; n = (n < 10 ? n * 10 : n + 100)) {
    a = (int*)malloc(n * sizeof(int));
    
    // Create sorted array
    for (i = 0; i < n; i++) {
      *(a + i) = i;
    }
    
    if (p == 1) {
      // Worst case: key not in array OR at the very end
      // We'll use a value larger than any in the array
      key = n; // This ensures we'll search through the entire array
    } else {
      // Best case: key at the middle position - found on first comparison
      key = a[n/2];
    }
    
    res = binary(a, key, n);
    fprintf(fp, "%d\t%d\n", n, res);
    free(a);
  }
  fclose(fp);
}

void main() {
  // Run worst case first
  plotter(1);
  // Then best case
  plotter(2);
  
  printf("Data generation complete.\n");
}