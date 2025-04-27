#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;
int linear(int *a, int k, int n) {
  int i, count = 0;
  for (i = 0; i <= n; i++) {
    count++;
    if (*(a+i) == k)
      return count;
  }
  return count;
}

void plotter(int p){
  int *a, n, key, i, res;
  FILE *fp;
  if (p == 1)
    fp = fopen("C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Searching\\WorstCase.txt", "w");
  else
    fp = fopen("C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\Searching\\BestCase.txt", "w");
  srand(time(NULL));
  for (n = 10; n < 1000; n = (n < 10 ? n * 10 : n + 100)) {
    a = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
      *(a + i) = rand() % n;
    }
    key = (p == 1)? (*(a + n - 1) = -1) : a[0];
    res = linear(a, key, n);
    fprintf(fp, "%d\t%d\n", n, res);
    free(a);
  }
  fclose(fp);
}

void main(){
  int i;
  for (i = 1; i <= 2; i++){
    plotter(i);
  }
}