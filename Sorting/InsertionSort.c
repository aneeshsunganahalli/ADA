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

int main() {
  plotter(1); plotter(2); plotter(3);
  printf("Insertion sort analysis complete.\n");
  return 0;
}
