#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void swap(int *a, int *b) {
  int temp = *a; *a = *b; *b = temp;
}

int partition(int *a, int low, int high) {
  int pivot = a[high], i = low - 1, j;
  for (j = low; j < high; j++) {
    count++;
    if (a[j] <= pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[high]);
  return i + 1;
}

void quickSort(int *a, int low, int high) {
  if (low < high) {
    int pi = partition(a, low, high);
    quickSort(a, low, pi - 1);
    quickSort(a, pi + 1, high);
  }
}

int quickSortWrapper(int *a, int n) {
  count = 0;
  quickSort(a, 0, n - 1);
  return count;
}

void plotter(int p) {
  int *a, n, i;
  char *filename = p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\QuickSort\\QuickWorstCase.txt" :
                   p == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\QuickSort\\QuickBestCase.txt" :
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\QuickSort\\QuickAvgCase.txt";
  FILE *fp = fopen(filename, "w");
  srand(time(NULL));
  
  for (n = 10; n < 1000; n = (n < 10 ? n * 10 : n + 100)) {
    a = (int*)malloc(n * sizeof(int));
    if (p == 1) {
      // Worst case: already sorted (with last element as pivot)
      for (i = 0; i < n; i++) a[i] = i;
    } else if (p == 2) {
      // Best case: pivot always divides array in half
      for (i = 0; i < n; i++) a[i] = rand() % n;
    } else {
      // Average case: random array
      for (i = 0; i < n; i++) a[i] = rand() % n;
    }
    fprintf(fp, "%d\t%d\n", n, quickSortWrapper(a, n));
    free(a);
  }
  fclose(fp);
}

int main() {
  plotter(1); plotter(2); plotter(3);
  printf("Quick sort analysis complete.\n");
  return 0;
}
