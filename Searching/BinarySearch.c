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

int main() {
  plotter(1);
  plotter(2);
  printf("Data generation complete.\n");
  return 0;
}