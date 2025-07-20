#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void merge(int *a, int left, int mid, int right) {
  int i, j, k, n1 = mid - left + 1, n2 = right - mid;
  int *L = (int*)malloc(n1 * sizeof(int));
  int *R = (int*)malloc(n2 * sizeof(int));
  
  for (i = 0; i < n1; i++) L[i] = a[left + i];
  for (j = 0; j < n2; j++) R[j] = a[mid + 1 + j];
  
  i = 0; j = 0; k = left;
  while (i < n1 && j < n2) {
    count++;
    if (L[i] <= R[j]) a[k++] = L[i++];
    else a[k++] = R[j++];
  }
  while (i < n1) a[k++] = L[i++];
  while (j < n2) a[k++] = R[j++];
  
  free(L); free(R);
}

void mergeSort(int *a, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
  }
}

int mergeSortWrapper(int *a, int n) {
  count = 0;
  mergeSort(a, 0, n - 1);
  return count;
}

void plotter(int p) {
  int *a, n, i;
  char *filename = p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\MergeSort\\MergeWorstCase.txt" :
                   p == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\MergeSort\\MergeBestCase.txt" :
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\MergeSort\\MergeAvgCase.txt";
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
    fprintf(fp, "%d\t%d\n", n, mergeSortWrapper(a, n));
    free(a);
  }
  fclose(fp);
}

int main() {
  plotter(1); plotter(2); plotter(3);
  printf("Merge sort analysis complete.\n");
  return 0;
}
