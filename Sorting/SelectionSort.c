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
      temp = a[i]; a[i] = a[min_idx]; a[min_idx] = temp;
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

int main() {
  plotter(1); plotter(2); plotter(3);
  printf("Selection sort analysis complete.\n");
  return 0;
}
