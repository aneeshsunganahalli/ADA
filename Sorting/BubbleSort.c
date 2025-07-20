#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubbleSort(int *a, int n) {
  int i, j, count = 0, temp, swapped;
  for (i = 0; i < n - 1; i++) {
    swapped = 0;
    for (j = 0; j < n - i - 1; j++) {
      count++;
      if (a[j] > a[j + 1]) {
        temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
        swapped = 1;
      }
    }
    if (!swapped) break; // Early termination for best case
  }
  return count;
}

void plotter(int p) {
  int *a, n, i;
  char *filename = p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\BubbleWorstCase.txt" :
                   p == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\BubbleBestCase.txt" :
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Sorting\\BubbleAvgCase.txt";
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
    fprintf(fp, "%d\t%d\n", n, bubbleSort(a, n));
    free(a);
  }
  fclose(fp);
}

int main() {
  plotter(1); plotter(2); plotter(3);
  printf("Bubble sort analysis complete.\n");
  return 0;
}
