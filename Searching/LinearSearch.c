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

int main() {
  plotter(1);
  plotter(2);
  return 0;
}