#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int bruteForceSearch(char *text, char *pattern, int n, int m) {
  int i, j, count = 0;
  for (i = 0; i <= n - m; i++) {
    for (j = 0; j < m; j++) {
      count++;
      if (text[i + j] != pattern[j]) break;
    }
    if (j == m) return count; // Pattern found
  }
  return count;
}

void generateText(char *text, int n, int case_type) {
  int i;
  if (case_type == 1) {
    // Worst case: text of all same characters except last
    for (i = 0; i < n - 1; i++) text[i] = 'A';
    text[n - 1] = 'B';
  } else if (case_type == 2) {
    // Best case: pattern at the beginning
    for (i = 0; i < n; i++) text[i] = 'A';
  } else {
    // Average case: random text
    for (i = 0; i < n; i++) text[i] = 'A' + (rand() % 4); // A,B,C,D
  }
  text[n] = '\0';
}

void generatePattern(char *pattern, int m, int case_type) {
  int i;
  if (case_type == 1) {
    // Worst case: pattern of all same chars as text except last
    for (i = 0; i < m - 1; i++) pattern[i] = 'A';
    pattern[m - 1] = 'B';
  } else if (case_type == 2) {
    // Best case: pattern matches from start
    for (i = 0; i < m; i++) pattern[i] = 'A';
  } else {
    // Average case: random pattern
    for (i = 0; i < m; i++) pattern[i] = 'A' + (rand() % 4);
  }
  pattern[m] = '\0';
}

void plotter(int p) {
  char *text, *pattern;
  int n, m, comparisons;
  char *filename = p == 1 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\StringMatching\\BruteForceWorstCase.txt" :
                   p == 2 ? "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\StringMatching\\BruteForceBestCase.txt" :
                            "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\StringMatching\\BruteForceAvgCase.txt";
  FILE *fp = fopen(filename, "w");
  srand(time(NULL));
  
  for (n = 20; n <= 1000; n += 50) {
    m = n / 4; // Pattern length is 1/4 of text length
    if (m < 2) m = 2;
    
    text = (char*)malloc((n + 1) * sizeof(char));
    pattern = (char*)malloc((m + 1) * sizeof(char));
    
    generateText(text, n, p);
    generatePattern(pattern, m, p);
    
    comparisons = bruteForceSearch(text, pattern, n, m);
    fprintf(fp, "%d\t%d\n", n, comparisons);
    
    free(text);
    free(pattern);
  }
  fclose(fp);
}

int main() {
  plotter(1); plotter(2); plotter(3);
  printf("Brute Force String Matching analysis complete.\n");
  return 0;
}
