#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void swap(int *a, int *b) {
  int temp = *a; *a = *b; *b = temp;
}

void heapify(int *arr, int n, int i) {
  int largest = i, left = 2 * i + 1, right = 2 * i + 2;
  
  if (left < n) {
    count++;
    if (arr[left] > arr[largest]) largest = left;
  }
  
  if (right < n) {
    count++;
    if (arr[right] > arr[largest]) largest = right;
  }
  
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void buildMaxHeap(int *arr, int n) {
  // Bottom-up heap construction - start from last non-leaf node
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
}

int heapSort(int *arr, int n) {
  count = 0;
  
  // Build max heap using bottom-up construction
  buildMaxHeap(arr, n);
  
  // Extract elements from heap one by one
  for (int i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
  
  return count;
}

void plotter(int p) {
  int *a, n, i;
  char *filename = p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\HeapSort\\HeapWorstCase.txt" :
                   p == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\HeapSort\\HeapBestCase.txt" :
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\HeapSort\\HeapAvgCase.txt";
  FILE *fp = fopen(filename, "w");
  srand(time(NULL));
  
  for (n = 10; n < 1000; n = (n < 10 ? n * 10 : n + 100)) {
    a = (int*)malloc(n * sizeof(int));
    if (p == 1) {
      // Worst case: sorted array (for max heap)
      for (i = 0; i < n; i++) a[i] = i;
    } else if (p == 2) {
      // Best case: reverse sorted array
      for (i = 0; i < n; i++) a[i] = n - i;
    } else {
      // Average case: random array
      for (i = 0; i < n; i++) a[i] = rand() % n;
    }
    fprintf(fp, "%d\t%d\n", n, heapSort(a, n));
    free(a);
  }
  fclose(fp);
}

int main() {
  plotter(1); plotter(2); plotter(3);
  printf("Heap sort analysis complete.\n");
  return 0;
}
